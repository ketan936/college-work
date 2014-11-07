import gtk
import gobject


from dbus import glib

import dbus



class Handler:

    def __init__(self, builder):
        self.builder = builder

    def delete(self, *args):
        gtk.main_quit(*args)

   
    def refresh(self, widget=None ,event=None):

        
        bus = dbus.SessionBus()

        # Create an object that will proxy for a particular remote object.
        remote_object = bus.get_object("com.castle.usb", # Connection name
                                       "/usbData" # Object's path
        )
     

        interface = dbus.Interface(remote_object,"com.castle.usb")
        # Introspection returns an XML document containing information
        # about the methods supported by an interface.
        reply =  interface.getvalue1()
       
        k = '\n'.join(reply)
        textview = builder.get_object("textview1")
        buffer = textview.get_buffer()
        buffer.set_text(k)
        textview.set_buffer(buffer)
        
    def hello_signal_handler(self,string):
        print  (string)
        self.refresh()

       


# bus = dbus.SessionBus()
# try:
#     object  = bus.get_object("com.castle.usb","/usbData")

# except dbus.DBusException:
#     traceback.print_exc()
#     print "error occured bad :("
#     sys.exit(1)

    #lets make a catchall


builder = gtk.Builder()
builder.add_from_file("gui.glade")
handler = Handler(builder)
builder.connect_signals(handler)
bus = dbus.SessionBus()
bus.add_signal_receiver(handler.hello_signal_handler, dbus_interface = "com.castle.usb", signal_name = "changed_value1")
window = builder.get_object("window1")
handler.refresh()
window.show_all()

gtk.main()