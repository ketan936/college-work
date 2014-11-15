import gobject
gobject.threads_init()

from dbus import glib
glib.init_threads()

# Create a session bus.
import dbus
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
print(reply)
