
from gi.repository import Gtk
import signal

class PyApp(Gtk.Window):

    def __init__(self):
        super(PyApp, self).__init__()
        
        self.set_title("Entry")
        self.set_size_request(230, 160)
        self.set_position(Gtk.WindowPosition.CENTER)

        fixed = Gtk.Fixed()
        label = Gtk.Label()
        label.set_markup("<b>Enter Serial</b>")
        fixed.put(label, 30, 40)

        button = Gtk.Button("Add Entry")
        button.connect("clicked", self.on_click_me_clicked)
        fixed.put(button, 80, 90)

        self.entry = Gtk.Entry()
        fixed.put(self.entry, 30, 60)
        self.connect("destroy", Gtk.main_quit)
        self.add(fixed)
        self.show_all()

    def on_key_release(self, widget, event):
        self.label.set_text(widget.get_text())

    def on_click_me_clicked(self, button):
        f = open("data.txt",'a')
        f.write(self.entry.get_text()+'\n')
        f.close()
        Gtk.main_quit()
    

PyApp()
signal.signal(signal.SIGINT, signal.SIG_DFL)
Gtk.main()