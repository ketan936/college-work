from gi.repository import Gtk
import gobject
gobject.threads_init()

from dbus import glib
glib.init_threads()
import dbus

def hello_signal_handler(hello_string):
    print ("Received signal (by connecting using remote object) and it says: "+ hello_string)


class Handler:

    def __init__(self, builder):
        self.builder = builder

    def delete(self, *args):
        Gtk.main_quit(*args)

   
    def refresh(self, widget,event):

        
        bus = dbus.SessionBus()

        # Create an object that will proxy for a particular remote object.
        remote_object = bus.get_object("com.castle.usb", # Connection name
                                       "/usbData" # Object's path
        )
        bus.add_signal_receiver(hello_signal_handler, dbus_interface = "com.castle.usb", signal_name = "changed_value1")

        interface = dbus.Interface(remote_object,"com.castle.usb")
        # Introspection returns an XML document containing information
        # about the methods supported by an interface.
        reply =  interface.getvalue1()
       
        k = '\n'.join(reply)
        textview = builder.get_object("textview1")
        buffer = textview.get_buffer()
        buffer.set_text(k)
        textview.set_buffer(buffer)


# bus = dbus.SessionBus()
# try:
#     object  = bus.get_object("com.castle.usb","/usbData")

# except dbus.DBusException:
#     traceback.print_exc()
#     print "error occured bad :("
#     sys.exit(1)

    #lets make a catchall


builder = Gtk.Builder()
builder.add_from_file("gui.glade")
builder.connect_signals(Handler(builder))

window = builder.get_object("window1")
window.show_all()

Gtk.main()