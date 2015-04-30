#include <stdio.h>

#include <rpc/rpc.h>    /* standard RPC include file */
#include "quiz.h"       /* this file is generated by rpcgen */

main(int argc, char *argv[])
{
    CLIENT *cl;         /* RPC handle */
    char *server;
   input_quiz  *lresult;  
   input_quiz  *presult;      /* return value from bin_date_1() */
    char **sresult;     /* return value from str_date_1() */
    
                char echoString[256];
                memset(&echoString, 0, 256);
    if (argc != 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }
    
    server = argv[1];
    
    /*
     * Create client handle
     */
    
    if ((cl = clnt_create(server, QUIZ_PROG, QUIZ_VERS, "udp")) == NULL) {
        /*
         * can't establish connection with server
         */
         clnt_pcreateerror(server);
         exit(2);
    }
    
    /*
     * First call the remote procedure "bin_date".
     */
for(;;){
    if ( (lresult = quiz_ques_1(NULL, cl)) == NULL) {
        clnt_perror(cl, server);
        exit(3);
    }
	
    printf("%s\n",lresult->answer );
    printf("enter value\n" );
    int d;
    scanf("%d",&d);
    lresult->a=d;
        presult =lresult;
	 if ( (lresult = quiz_ans_1(presult, cl)) == NULL) {
        clnt_perror(cl, server);
        exit(3);
    }
printf("%s\n",lresult->answer );
}}
