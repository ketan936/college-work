from gi.repository import Gtk
from gi.repository import GObject

from dbus import glib

import dbus
import signal
import subprocess


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
        reply =  interface.getvalue1()
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
            dialog.destroy()

    def add_clicked(self,button):
       subprocess.call(['gksudo','python root.py'])
       


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
bus.add_signal_receiver(handler.hello_signal_handler, dbus_interface = "com.castle.usb", signal_name = "changed_value1")
bus.add_signal_receiver(handler.usb_validate, dbus_interface = "com.castle.usb", signal_name = "changed_value2")
window = builder.get_object("window1")
handler.refresh()


window.show_all()
signal.signal(signal.SIGINT, signal.SIG_DFL)
Gtk.main()
