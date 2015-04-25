/*
 * packet_sniffer.c - Application for testing builder file.
 *
 * Compile with:
 *  gcc -o packet_sniffer packet_sniffer.c $(pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0)
 */
#include <gtk/gtk.h>
#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 1518

/* ethernet headers are always exactly 14 bytes [1] */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN 6

/* Ethernet header */
struct sniff_ethernet
{
        u_char ether_dhost[ETHER_ADDR_LEN]; /* destination host address */
        u_char ether_shost[ETHER_ADDR_LEN]; /* source host address */
        u_short ether_type; /* IP? ARP? RARP? etc */
};

/* IP header */
struct sniff_ip
{
        u_char ip_vhl; /* version << 4 | header length >> 2 */
        u_char ip_tos; /* type of service */
        u_short ip_len; /* total length */
        u_short ip_id; /* identification */
        u_short ip_off; /* fragment offset field */
#define IP_RF 0x8000            /* reserved fragment flag */
#define IP_DF 0x4000            /* dont fragment flag */
#define IP_MF 0x2000            /* more fragments flag */
#define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
        u_char ip_ttl; /* time to live */
        u_char ip_p; /* protocol */
        u_short ip_sum; /* checksum */
        struct in_addr ip_src, ip_dst; /* source and dest address */
};
#define IP_HL(ip)               (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)                (((ip)->ip_vhl) >> 4)

/* TCP header */
typedef u_int tcp_seq;

struct sniff_tcp
{
        u_short th_sport; /* source port */
        u_short th_dport; /* destination port */
        tcp_seq th_seq; /* sequence number */
        tcp_seq th_ack; /* acknowledgement number */
        u_char th_offx2; /* data offset, rsvd */
#define TH_OFF(th)      (((th)->th_offx2 & 0xf0) >> 4)
        u_char th_flags;
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80
#define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
        u_short th_win; /* window */
        u_short th_sum; /* checksum */
        u_short th_urp; /* urgent pointer */
};

enum
{
        COL_SNO = 0,
        COL_PROTOCOL,
        COL_FROM,
        COL_TO,
        COL_SRC_PORT,
        COL_DEST_PORT,
        COL_PAYLOAD,
        NUM_COLS
};
typedef struct _Data Data;
struct _Data
{
        GtkWidget *entry1;
        GtkWidget *entry2;
        GtkWidget *entry3;
        GtkWidget *tree;
        GtkWidget *textview;
        GtkListStore *store;
};
GtkListStore *global_store;
char global_payload[4000];
Data data;
typedef struct _Thread_Data T_Data;
struct _Thread_Data
{
        pcap_t *handle;
        int num_packets;
};
void
got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

void
print_payload(const u_char *payload, int len);

void
print_hex_ascii_line(const u_char *payload, int len, int offset);

/*
 * print data in rows of 16 bytes: offset   hex   ascii
 *
 * 00000   47 45 54 20 2f 20 48 54  54 50 2f 31 2e 31 0d 0a   GET / HTTP/1.1..
 */
void print_hex_ascii_line(const u_char *payload, int len, int offset)
{

        int i;
        int gap;
        const u_char *ch;

        /* offset */
        printf("%05d   ", offset);
        sprintf(global_payload + strlen(global_payload), "%05d   ", offset);
        /* hex */
        ch = payload;
        for (i = 0; i < len; i++) {
                printf("%02x ", *ch);
                sprintf(global_payload + strlen(global_payload), "%02x ", *ch);
                ch++;
                /* print extra space after 8th byte for visual aid */
                if (i == 7) {
                        printf(" ");
                        sprintf(global_payload + strlen(global_payload), " ");
                }
        }
        /* print space to handle line less than 8 bytes */
        if (len < 8)
                printf(" ");
        sprintf(global_payload + strlen(global_payload), " ");
        /* fill hex gap with spaces if not full line */
        if (len < 16) {
                gap = 16 - len;
                for (i = 0; i < gap; i++) {
                        printf("   ");
                        sprintf(global_payload + strlen(global_payload), "   ");
                }
        }
        printf("   ");
        sprintf(global_payload + strlen(global_payload), "   ");

        /* ascii (if printable) */
        ch = payload;
        for (i = 0; i < len; i++) {
                if (isprint(*ch)) {
                        printf("%c", *ch);
                        sprintf(global_payload + strlen(global_payload), "%c",
                                        *ch);
                } else {
                        printf(".");
                        sprintf(global_payload + strlen(global_payload), ".");
                }
                ch++;
        }

        printf("\n");
        sprintf(global_payload + strlen(global_payload), "\n");
        return;
}

/*
 * print packet payload data (avoid printing binary data)
 */
void print_payload(const u_char *payload, int len)
{

        int len_rem = len;
        int line_width = 16; /* number of bytes per line */
        int line_len;
        int offset = 0; /* zero-based offset counter */
        const u_char *ch = payload;

        if (len <= 0)
                return;

        /* data fits on one line */
        if (len <= line_width) {
                print_hex_ascii_line(ch, len, offset);
                return;
        }

        /* data spans multiple lines */
        for (;;) {
                /* compute current line length */
                line_len = line_width % len_rem;
                /* print line */
                print_hex_ascii_line(ch, line_len, offset);
                /* compute total remaining */
                len_rem = len_rem - line_len;
                /* shift pointer to remaining bytes to print */
                ch = ch + line_len;
                /* add offset */
                offset = offset + line_width;
                /* check if we have line width chars or less */
                if (len_rem <= line_width) {
                        /* print last line and get out */
                        print_hex_ascii_line(ch, len_rem, offset);
                        break;
                }
        }

        return;
}

/*
 * dissect/print packet
 */
void got_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet)
{

        static int count = 1; /* packet counter */

        /* declare pointers to packet headers */
        const struct sniff_ethernet *ethernet; /* The ethernet header [1] */
        const struct sniff_ip *ip; /* The IP header */
        const struct sniff_tcp *tcp; /* The TCP header */
        const char *payload; /* Packet payload */

        int size_ip;
        int size_tcp;
        int size_payload;

        g_print("edflaskdj");
        GtkTreeIter iter;
        char c1[250], c2[256], c3[256], c4[256];

        /* Append a row and fill in some data */

        sprintf(c1, "%d", count);
        printf("\nPacket number %d:\n", count);
        count++;
        /* define ethernet header */
        ethernet = (struct sniff_ethernet*) (packet);

        /* define/compute ip header offset */
        ip = (struct sniff_ip*) (packet + SIZE_ETHERNET);
        size_ip =
        IP_HL(
                        ip) * 4;
        if (size_ip < 20) {
                printf("   * Invalid IP header length: %u bytes\n", size_ip);
                return;
        }

        /* print source and destination IP addresses */
        printf("       From: %s\n", inet_ntoa(ip->ip_src));
        printf("         To: %s\n", inet_ntoa(ip->ip_dst));
        strcpy(c2, inet_ntoa(ip->ip_src));
        strcpy(c3, inet_ntoa(ip->ip_dst));
        /* determine protocol */
        switch (ip->ip_p)
        {
        case IPPROTO_TCP:
                printf("   Protocol: TCP\n");
                strcpy(c4, "TCP");
                break;
        case IPPROTO_UDP:
                printf("   Protocol: UDP\n");
                strcpy(c4, "UDP");
                return;
        case IPPROTO_ICMP:
                printf("   Protocol: ICMP\n");
                strcpy(c4, "ICMP");
                return;
        case IPPROTO_IP:
                printf("   Protocol: IP\n");
                strcpy(c4, "IP");
                return;
        default:
                printf("   Protocol: unknown\n");
                strcpy(c4, "UNKNOWN");
                return;
        }

        /*
         *  OK, this packet is TCP.
         */

        /* define/compute tcp header offset */
        tcp = (struct sniff_tcp*) (packet + SIZE_ETHERNET + size_ip);
        size_tcp =
        TH_OFF(
                        tcp) * 4;
        if (size_tcp < 20) {
                printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
                return;
        }
        char c5[10];
        char c6[10];
        c5[0] = '\0';
        c6[0] = '\0';
        printf("   Src port: %d\n", ntohs(tcp->th_sport));
        printf("   Dst port: %d\n", ntohs(tcp->th_dport));
        sprintf(c5, "%d", ntohs(tcp->th_sport));
        sprintf(c6, "%d", ntohs(tcp->th_dport));
        /* define/compute tcp payload (segment) offset */
        payload = (u_char *) (packet + SIZE_ETHERNET + size_ip + size_tcp);

        /* compute tcp payload (segment) size */
        size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);

        /*
         * Print payload data; it might be binary, so don't just
         * treat it as a string.
         */
        if (size_payload > 0) {
                printf("   Payload (%d bytes):\n", size_payload);
                global_payload[0] = '\0';
                print_payload(payload, size_payload);
        }
        gtk_list_store_append(global_store, &iter);
        gtk_list_store_set(global_store, &iter, COL_SNO, c1, COL_PROTOCOL, c4,
                        COL_FROM, c2, COL_TO, c3, COL_SRC_PORT, c5,
                        COL_DEST_PORT, c6, COL_PAYLOAD, global_payload, -1);
        gtk_tree_view_set_model(GTK_TREE_VIEW(data.tree),
                        GTK_TREE_MODEL(global_store));
        /* g_print(
         " ************************************************************\n%s",
         global_payload);
         */
        return;
}
void *myThreadFun(void *t_data)
{
        T_Data *temp = t_data;
               pcap_loop(temp->handle, temp->num_packets, got_packet,
               NULL);




               printf("\nCapture complete.\n");
             //  pcap_close(temp->handle);

               return NULL;
}
GtkTreeModel *
create_and_fill_model(void)
{
        GtkListStore *store;
        GtkTreeIter iter;

        store = gtk_list_store_new(NUM_COLS,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING);

        /* Append a row and fill in some data */
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, COL_SNO, "hello", COL_PROTOCOL,
                        "hello", COL_FROM, "hello", COL_TO, "hello",
                        COL_SRC_PORT, "hello", COL_DEST_PORT, "hello",
                        COL_PAYLOAD, "payload1", -1);

        /* append another row and fill in some data */
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, COL_SNO, "hello", COL_PROTOCOL,
                        "hello", COL_FROM, "hello", COL_TO, "hello",
                        COL_SRC_PORT, "hello", COL_DEST_PORT, "hello",
                        COL_PAYLOAD, "hello2", -1);
        ;

        /* ... and a third row */
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, COL_SNO, "hello", COL_PROTOCOL,
                        "hello", COL_FROM, "hello", COL_TO, "hello",
                        COL_SRC_PORT, "hello", COL_DEST_PORT, "hello",
                        COL_PAYLOAD, "hello3", -1);

        return GTK_TREE_MODEL(store);
}
on_button1_clicked(GtkButton *button, Data *data)
{
        char *dev =
        NULL; /* capture device name */
        char errbuf[PCAP_ERRBUF_SIZE]; /* error buffer */
        pcap_t *handle; /* packet capture handle */

        char filter_exp[1000] = "\0"; /* filter expression */
        struct bpf_program fp; /* compiled filter program (expression) */
        bpf_u_int32 mask; /* subnet mask */
        bpf_u_int32 net; /* ip */
        int num_packets = 1000; /* number of packets to capture */
        GtkTextBuffer *buffer;
        GtkTextIter start, end;
        /* check for capture device name on command-line */

        GtkTreeIter iter;
        pthread_t tid;
        global_store = gtk_list_store_new(NUM_COLS,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING);

        /* Append a row and fill in some data */

        dev = gtk_entry_get_text(GTK_ENTRY(data->entry1));
        /*buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->entry1));
         gtk_text_buffer_get_start_iter(buffer, &start);
         gtk_text_buffer_get_end_iter(buffer, &end);
         g_print("hello");
         g_print(gtk_text_buffer_get_text(buffer, &start, &end, FALSE));*/
        /* find a capture device if not specified on command-line */
        //  dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
                fprintf(
                stderr, "Couldn't find default device: %s\n", errbuf);
                exit(
                EXIT_FAILURE);

        }
        printf("\nEnter no. of packets you want to capture: ");
        num_packets = atoi(gtk_entry_get_text(GTK_ENTRY(data->entry2)));
        printf("\nWhich kind of packets you want to capture : ");
        strcpy(filter_exp, gtk_entry_get_text(GTK_ENTRY(data->entry3)));
        if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
                fprintf(
                stderr, "Couldn't get netmask for device %s: %s\n", dev,
                                errbuf);
                net = 0;
                mask = 0;
        }

        printf("Device: %s\n", dev);
        printf("Number of packets: %d\n", num_packets);
        printf("Filter expression: %s\n", filter_exp);

        handle = pcap_open_live(dev,
        SNAP_LEN, 1, 1000, errbuf);
        if (handle == NULL) {
                fprintf(
                stderr, "Couldn't open device %s: %s\n", dev, errbuf);
                exit(
                EXIT_FAILURE);
        }

        if (pcap_datalink(handle) != DLT_EN10MB) {
                fprintf(
                stderr, "%s is not an Ethernet\n", dev);
                exit(
                EXIT_FAILURE);
        }

        if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
                fprintf(
                stderr, "Couldn't parse filter %s: %s\n", filter_exp,
                                pcap_geterr(handle));
                exit(
                EXIT_FAILURE);
        }

        if (pcap_setfilter(handle, &fp) == -1) {
                fprintf(
                stderr, "Couldn't install filter %s: %s\n", filter_exp,
                                pcap_geterr(handle));
                exit(
                EXIT_FAILURE);
        }
        T_Data tdata;
        tdata.handle = handle;
        tdata.num_packets=num_packets;
        pthread_create(&tid, NULL, myThreadFun, &tdata);
        pcap_freecode(&fp);
}

void view_onRowActivated(GtkTreeView *treeview, GtkTreePath *path,
                GtkTreeViewColumn *col, gpointer userdata)
{
        GtkTreeModel *model;
        GtkTreeIter iter;
        GtkTextBuffer *buffer;

        g_print("A row has been double-clicked!\n");

        model = gtk_tree_view_get_model(treeview);
        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data.textview));
        if (gtk_tree_model_get_iter(model, &iter, path)) {
                gchar *name;

                gtk_tree_model_get(model, &iter, COL_PAYLOAD, &name, -1);
                gtk_text_buffer_set_text(buffer,name,strlen(name));
                gtk_text_view_set_buffer(GTK_TEXT_VIEW(data.textview), buffer);

                g_free(name);
        }
}
int main(int argc, char **argv)
{
        /* Vars */
        GtkWidget *window;
        GtkBuilder *builder;
        GError *error;
        GtkTreeModel *model;
        GtkWidget *view;
        GtkListStore *listStore;

        /* Initialization */
        gtk_init(&argc, &argv);

        /* Create builder and load UI file */
        builder = gtk_builder_new();
        gtk_builder_add_from_file(builder, "ui.glade",
        NULL);

        /* Get main window and connect signals */

        window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
        view = GTK_WIDGET(gtk_builder_get_object(builder, "treeview1"));
        data.entry1 = GTK_WIDGET( gtk_builder_get_object(builder, "entry1"));
        data.entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
        data.entry3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));
        data.tree = GTK_WIDGET(gtk_builder_get_object(builder, "treeview1"));
        data.textview = GTK_WIDGET(
                        gtk_builder_get_object(builder, "textview1"));
        gtk_builder_connect_signals(builder, &data);

        /* Destroy builder */
        g_object_unref(G_OBJECT(builder));
        model = create_and_fill_model();

        /* Show main window and start main loop */
        gtk_widget_show(window);
        gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);

        gtk_main();

        return (0);
}
