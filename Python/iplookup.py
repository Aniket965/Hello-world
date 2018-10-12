#TODO Implement map with seperate tkinter frame (with bg="")

from tkinter import *
import tkinter.messagebox as msgbox
import IP2Location as iplocation
import webbrowser
from json import load
from urllib.request import urlopen
from urllib.error import URLError
from urllib.request import urlretrieve
import os.path

# Initialisation of Tkinter Window Settings
root = Tk()
root.title("iplookup")
root.resizable(False, False)
version = 0.5

class location_data(Frame):
    def __init__(self, w, h, bg, bd, bc, ht):
        Frame.__init__(self, width=w, height=h, bd=bd,bg=bg, highlightbackground=bc, highlightcolor=bc,
                       highlightthickness=ht)

    def represent_data(self, data):
        label_names = ['Country Abbreviation', 'Country', 'Region', 'City', 'Internet Service Provider (ISP)',
                       'Latitude', 'Longitude', 'Domain', 'Zipcode', 'Timezone', 'Netspeed',
                       'Telephone Area Code for International Direct Dialing (IDD)', 'Area code',
                       'Weather station code', 'Weather station name', 'Mobile country code (MCC)',
                       'Mobile network code (MNC)', 'Carrier brand', 'Elevation', 'Usage type']
        for i, label_text in enumerate(label_names, 1):
            Label(self, text=label_text,bg='white').grid(row=i, column=1, sticky="w")


        label_values = [data.country_short, data.country_long, data.region, data.city, data.isp, data.latitude,
                        data.longitude, data.domain, data.zipcode, data.timezone, data.netspeed, data.idd_code,
                        data.area_code, data.weather_code, data.weather_name, data.mcc, data.mnc,
                        data.mobile_brand, data.elevation, data.usage_type]

        for i, label_text in enumerate(label_values, 1):
            Label(self, text=label_text,bg='white', width=25, anchor=W).grid(row=i, column=3, padx=70)

# Application Class inheriting from Frame, so that Interaction with tkinter root window possible
class Application(Frame):

    # Set up the neccessary tkinter objects
    def __init__(self):
        Frame.__init__(self)

        # Frame representing output geolocation data
        self.location_data_frame = location_data(w=400, h=400, bd=0, bc="white", ht=1, bg="white")

        # Top Menu
        self.menu = Menu(self)
        root.config(menu=self.menu)
        self.file_menu = Menu(self.menu, tearoff=False)
        self.help_menu = Menu(self.menu, tearoff=False)
        self.menu.add_cascade(label="File", menu=self.file_menu)
        self.menu.add_cascade(label="Help", menu=self.help_menu)
        self.file_menu.add_command(label="Quit", command=root.destroy)
        self.help_menu.add_command(label="Contact / Suggestions", command=self.show_help)
        self.help_menu.add_command(label="Report Bug", command=self.bug_report)
        self.help_menu.add_command(label="FAQ", command=self.open_faq)
        self.help_menu.add_command(label="About", command=self.show_about)

        #Label
        self.ip_label = Label(self, text="IP-adress")
        self.ip_label.grid(row=1, column=1)

        #Entry
        self.ip = StringVar()
        self.ip.set("")
        self.ip_entry = Entry(self, textvariable=self.ip, width=25)
        self.ip_entry.focus_set()
        self.ip_entry.grid(row=1, column=2)

        #Buttons
        self.my_ip_button = Button(self, text='My IP', command=self.set_my_ip)
        self.my_ip_button.grid(row=1, column=3)
        self.fetch_button = Button(self, text='Fetch geolocation data', command=self.fetch_data)
        self.fetch_button.grid(row=1, column=4)

    # Fetch geolocation of input ip-adress
    def fetch_data(self):
        location_obj = iplocation.IP2Location()
        location_obj.open("data/data.bin")
        try:
            rec = location_obj.get_all(self.ip.get())
            self.location_data_frame.represent_data(rec)
        except OSError or UnboundLocalError:
            msgbox.showerror('Oops','We could not extract any data from the given IP-Adress, please try again! For information about valid IP-Adresses and their respective formats, check the FAQ or contact the developer in the "help" menu cascade.')

    # Get public ip of client computer and set it as input
    def set_my_ip(self):
        try:
            my_ip = load(urlopen('https://api.ipify.org/?format=json'))['ip']
            self.ip.set(my_ip)
        except URLError:
            msgbox.showerror("Oops","Please connect to the Internet to use this feature")

    # Show help messagebox
    def show_help(self):
        response = msgbox.askokcancel("Contact", "Feel free to contact me at\ntobias_vonarx@yahoo.de for any questions or suggestions")
        if response:
            webbrowser.open("mailto:%s?subject=%s" %
                            ('tobias_vonarx@yahoo.de', "Contact - iplookup"))

    # Show bugreport messagebox
    def bug_report(self):
        response = msgbox.askyesno("Report bug", "Have you noticed a bug / a problem with the application?")
        if response:
            response = msgbox.askokcancel("Report bug","Please report the bug and improve the application by proceeding with OK")
            if response:
                #webbrowser.open("mailto:%s?subject=%s&body=%s" %
                #            ('tobias_vonarx@yahoo.de', "Bug Report - iplookup",
                #             "Bug Description:%0A%0A%0A-%0AVersion: {v}%0APlatform: {p}".format(v=version, p=platform())))
                webbrowser.open("https://github.com/tobiasvonarx/iplookup/issues/new")

    # Open FAQ
    def open_faq(self):
        webbrowser.open("https://github.com/tobiasvonarx/iplookup/blob/master/FAQ.md")

    # Show about messagebox
    def show_about(self):
        msgbox.showinfo("About this program", "iplookup version {v} by Tobias von Arx in 2018\n\n\
This site or product includes IP2Location LITE data available from http://www.ip2location.com\n".format(v=version))

    # Show the Version messagebox
    def check_version(self):
        msgbox.showinfo("Version Information", "You are currently running:\nv{v}".format(v=version))

def get_data():
    mypath = os.path.dirname(os.path.realpath(__file__))+'\\data'
    if not os.path.isdir(mypath):
        os.makedirs(mypath)
    fname='data/data.bin'
    if not os.path.isfile(fname):
        try:
            msgbox.showinfo('Initial setup','Click OK to proceed with initial setup. Depending on your internet connection,\
this may take a while. Do not close out of the main window while setup is still running.')
            urlretrieve("https://www.dropbox.com/s/d4rqkgatz3z3uxc/data.BIN?dl=1", fname)
            msgbox.showinfo('Initial setup','Setup completed')
        except URLError:
            msgbox.showerror('Error','Please connect to the internet and restart the application')
def main():
    get_data()
    app = Application()
    app.grid(row=1, column=1, sticky="w")
    app.location_data_frame.grid(row=2, column=1, sticky="w")

if __name__ == "__main__":
    main()

root.mainloop()
