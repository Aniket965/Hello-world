from gi.repository import Gtk


class MainWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Button Clicker 2.0")
        self.set_border_width(20)
        label = Gtk.Label("Hello, world!")
        self.add(label)


window = MainWindow()
window.connect("delete-event", Gtk.main_quit)
window.show_all()

Gtk.main()
