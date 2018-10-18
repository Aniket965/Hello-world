# coding: utf-8

import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button

# version requirement
kivy.require('1.9.1')


class Tela1(BoxLayout):
    def __init__(self, **kwargs):
        super(Tela1, self).__init__(**kwargs)
        self.orientation = 'vertical'
        bt1 = Button(text='Click')
        bt1.on_press = self.on_press_bt
        self.add_widget(bt1)
        self.add_widget(Button(text='bt2'))
        self.add_widget(Button(text='bt3'))

    def on_press_bt(self):
        janela.root_window.remove_widget(janela.root)
        janela.root_window.add_widget(Tela2())


class Tela2(BoxLayout):
    def __init__(self, **kwargs):
        super(Tela2, self).__init__(**kwargs)
        self.orientation = 'vertical'
        bt = Button(text='Click')
        bt.on_press = self.on_press_bt
        self.add_widget(bt)

    def on_press_bt(self):
        janela.root_window.remove_widget(janela.root)
        janela.root_window.add_widget(Tela1())


class Main(App):
    def build(self):
        return Tela1()


janela = Main()
janela.run()
