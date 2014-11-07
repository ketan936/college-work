from gi.repository import Gtk
import gobject
gobject.threads_init()

from dbus import glib
glib.init_threads()
import dbus



class Handler:
    def __init__(self,builder):
        self.builder = builder

    def delete(self, *args):
        Gtk.main_quit(*args)

    def refresh(self, widget,event):
        print("Hello World!")
        bus = dbus.SessionBus()

        # Create an object that will proxy for a particular remote object.
        remote_object = bus.get_object("com.castle.usb", # Connection name
                                       "/usbData" # Object's path
        )
        interface = dbus.Interface(remote_object,"com.castle.usb")
        # Introspection returns an XML document containing information
        # about the methods supported by an interface.
        print ("Introspection data:\n")
        reply =  interface.getvalue1()
       
        k = '\n'.join(reply)
        print dir(self)
        print self.__class__
        




builder = Gtk.Builder()
builder.add_from_file("dummy.glade")
builder.connect_signals(Handler(builder))

window = builder.get_object("window1")
window.show_all()

Gtk.main()