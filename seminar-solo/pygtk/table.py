from gi.repository import GObject
from gi.repository import Gtk

from dbus import glib 

import dbus
import signal
import subprocess
import time
import thread

flag = True
def follow(threadname,thefile,textview):
    thefile.seek(0,2)
    textbuffer = textview.get_buffer()
    print threadname
    while flag:
        line = thefile.readline()
        if not line:
           
            textview.set_buffer(textbuffer)
            time.sleep(0.5)
            continue
        print line
        textbuffer.insert(textbuffer.get_end_iter(),line)
        textview.set_buffer(textbuffer)
    print "thread killed"
    


class Handler:

    def __init__(self, builder):
        self.builder = builder

    def delete(self, *args):
        Gtk.main_quit(*args)

   
    def refresh(self, widget=None ,event=None):

        
        bus = dbus.SessionBus()

        # Create an object that will proxy for a particular remote object.
        remote_object = bus.get_object("com.castle.usb", # Connection name
                                       "/usbData" # Object's path
        )
     

        interface = dbus.Interface(remote_object,"com.castle.usb")
        # Introspection returns an XML document containing information
        # about the methods supported by an interface.
        reply =  interface.usb_list()
        print "\n".join(reply)
        usbdata = Gtk.ListStore(str, str, str, str, str, str)
       
        for i in  xrange(0,len(reply),6):
            usbdata.append(reply[i:i+6])

        treeview = builder.get_object("treeview2")
       
        treeview.set_model(usbdata)
        
    def hello_signal_handler(self,string):
        print  (string)
        self.refresh()

    def usb_validate(self,string):
        
        dialog = self.builder.get_object("messagedialog1")
        dialog.format_secondary_text("Serial: "+string)
        response = dialog.run()
        if response == Gtk.ResponseType.OK:
            dialog.hide()
        dialog.hide()



    def add_clicked(self,button):
        
        try:
            thread.start_new_thread( self.root_process, ("Thread-2",) )
        except:
                print "Error: unable to start thread"


    def root_process(self,threadname):
        p = subprocess.Popen(['gksudo','python root.py'])
        p.communicate()
        self.refresh_right_tree()
        print "root process killed"

    def view_logs(self,button):
        global flag
        flag = True
        print "logfile"
        self.logfile = open("secondTRy.log")
        
        textview = builder.get_object("textview1")
        self.builder.add_objects_from_file("gui.glade","window3")
        window3 = builder.get_object("window3")
        window3.show_all()

        try:
            thread.start_new_thread( follow, ("Thread-1", self.logfile,textview,) )
        except:
                print "Error: unable to start thread"
        

    def close_logs(self,widget=None ,event=None):
        global flag
        flag=False
        print "close log "
        self.logfile.close()
        self.builder.get_object("window3").hide()
        return True

    def refresh_right_tree(self, widget=None ,event=None):

        serial = Gtk.ListStore(str)
        f = open('data.txt','r')
        for line in f.readlines():
            print line
            serial.append(eval('["'+line.strip()+'"]'))

        f.close()
        treeview = builder.get_object("treeview1")
       
        treeview.set_model(serial)


       


# bus = dbus.SessionBus()
# try:
#     object  = bus.get_object("com.castle.usb","/usbData")

# except dbus.DBusException:
#     traceback.print_exc()
#     print "error occured bad :("
#     sys.exit(1)

    #lets make a catchall
dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

builder = Gtk.Builder()
builder.add_from_file("gui.glade")
handler = Handler(builder)
builder.connect_signals(handler)
bus = dbus.SessionBus()
bus.add_signal_receiver(handler.hello_signal_handler, dbus_interface = "com.castle.usb", signal_name = "usb_added")
bus.add_signal_receiver(handler.hello_signal_handler, dbus_interface = "com.castle.usb", signal_name = "usb_removed")

bus.add_signal_receiver(handler.usb_validate, dbus_interface = "com.castle.usb", signal_name = "usb_blocked")
window = builder.get_object("window1")
handler.refresh()
handler.refresh_right_tree()

window.show_all()
signal.signal(signal.SIGINT, signal.SIG_DFL)
Gtk.main()
