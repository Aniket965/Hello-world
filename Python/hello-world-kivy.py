from kivy.app import App
from kivy.uix.label import Label


# main class
class Main(App):
    def build(self):
        return Label(text='Hello World !!', font_size=30)


app = Main()
app.run()
