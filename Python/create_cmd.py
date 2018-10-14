from cmd import Cmd
import os.path
import getpass
import sys
import fileinput
import subprocess
import webbrowser
import shutil
import stat
import pwd

import smtplib
from email.mime.text import MIMEText


"""file discriptors::: this is the number returned by the open file which is saved somewhere in the kernel and uniquely identifies the
OPENED file..."""

def put(value):
    f.write(value+"\n")
def get():
    f.seek(0,0)
    i=1
    x=f.read().splitlines()
    for y in x:
        print("{0:>6} {1:<50}".format(i,y))
        # print(str(i)+": "+y)
        i+=1


class MyPrompt(Cmd):


    def do_read(self,args):
        """read and returns the complete file whose valid address is passed as the argument, in the terminal itself\n
        Syntax: read<SPACE>(file name or complete location"""
        # try
        if(os.path.exists(args)==False):
            print("no such file or directory exists")
            print("if ypu are confident about the filename, pls try again by entering the complete location")
        if (os.path.exists(args) == True):
            for i in fileinput.input(args):
                print(i)
        val="read "+args
        put(val)


    def do_exist(self,args):
        """checks whether the file location entered, exists or not
        Syntax: exist<SPACE>(your file location)\n
        NOTE: if the file location and the current working directory are the same, pls enter only the filename as input\n
              if not so, neter the complete location of the file."""
        print(os.path.exists(args))
        val="exist "+args
        put(val)

    def do_basename(self,args):
        """returns the basename of the location entered as argument"""
        print(os.path.basename(args))
        val="basename "+args
        put(val)

    def do_knowfile(self,args):
        """returns the discription of the file given as the argument.
        NOTE: if the result is filtered using mode method, it returns the mode of the file in octal form"""

        if " " in args:

            q=args.split(" ")
            s = (os.stat(q[0]))
            q1=q[1].strip("-")

            if q1=="mode":
                a = oct(stat.S_IMODE(s.st_mode))
                print(a)

            else:
                print("no more options available")

        else:
            print(os.stat(args))
        val = "knowfile " + args
        put(val)


    def do_usr(self, args):
        """returns the username of the user currently logged in the system \n
        Syntax: user \n

        Note: similar to the whoami command in the bash terminal"""
        print(os.getlogin())
        val = "usr " + args
        put(val)

    def do_greet(self, args):
        """Says hello. If you provide a name, it will greet you with it. \n
        Syntax: greet<SPACE>( your_name or nothing)"""
        if len(args) == 0:
            name = 'stranger'
        else:
            name = args
        print("Hello, ", name)
        print(os.geteuid())
        val = "greet " + args
        put(val)

    def do_exit(self, args):
        """Quits the program.\n
        Syntax: exit"""
        print("Bye.")
        val = "exit " + args
        put(val)
        f.close()
        raise SystemExit

    def do_ps(self, args):
        """returns the process id ,parent process id and the effective user id for the current process \n
        Syntax: ps"""
        print("Process id: ", os.getpid())

        print("parent process id: ", os.getppid())
        print("effective user id: ", os.geteuid())
        val = "ps " + args
        put(val)
        # print(os.path.getatime(d))
        # print(os.path.getmtime(d))
        # print(os.path.getsize(d))

    # def do_checklocation(self,args):
    #     """return the status whether the path exists or not \n
    #     syntax: checklocation <path_name>"""
    #     if(os.path.exists(args)):
    #         return True

    def do_size(self,args):
        """return thes size of the path in Bytes \n
        syntax: size <path_name>"""
        print("size: "+str(os.path.getsize(args))+" Bytes")
        val = "size " + args
        put(val)

    def do_modname(self,args):
        """returns the name of the system dependent module imported"""
        print("module imported:",os.name)
        val = "modname " + args
        put(val)

    def do_cd(self,args):
        """changes the current working directory to the one mentions as the argument \n
        syntax: cd<parameter> \n
        ======================== \n
        parameter: ..(for previous directory)\n
                   path_name(for new location)"""
        if(args==".."):
            os.chdir(os.path.abspath(os.getcwd()))


        if(os.path.exists(args)):
            print("true")
            os.chdir(args)
            print(os.getcwd())
        else:
            print("error: no such file or directory exists.")
        val = "cd" + args
        put(val)


    def do_current(self,args):
        """return the current working directory"""
        print(os.getcwd())
        val = "current " + args
        put(val)

    def do_info(self,args):
        """returns the information about the operating system and the machine the user is currently working on"""
        print(os.uname())
        val = "info " + args
        put(val)

    def do_list(self, args):
        """list all the files in the current working directory, as a list. \n
            Syntax:     list      // represent all the files and folders
                        list -<character set>       // filter the result of the list command on the basis of the given character set"""
        x = (os.listdir(os.getcwd()))
        print("\n")
        if args == "":
            for i in x:
                # print(os.listdir(os.getcwd()))
                print(i)
        else:
            s=args.strip("-")
            for i in x:
                if s in i:
                    print(i)
        print("\n")
        val="list"+args
        put(val)


    def do_copyright(self,args):
        """print the members holding the copyright of the shell and other information"""
        print("SARA Shell\n")
        print("Copyright 2018- SARA Team \n All rights reserved")
        print("Team members: ==================================")
        print("SARA Shell created using Python\n copyrights")
        print(sys.copyright)
        val = "copyright " + args
        put(val)

    def do_platform(self,args):
        """returns the current working platform such as windows, linux, etc."""
        print(sys.platform)
        val = "platform " + args
        put(val)


    def do_createdir(self,args1):
        """creates a new directory in the current working directory with the dafault permission set to 0777(in oct)
        mode format: 0777,0666,0555 etc \n
        Syntax: createdir <directory name>
        """
        print("please refer to help for the mode format")
        s=input("press y  to continue: ")
        if s is "y" or s is "Y":
            x=input("Enter the mode of directory creation in int: ")
            os.mkdir(args1,int(x))
            print("\ndirectory successfully created")
        val = "createdir " + args1
        put(val)

    def do_history(self,args):
        """list all the used commands till date,including the latest history one, in the old to new order."""
        get()
        val = "history " + args
        put(val)

    def do_open(self,args):
        """open the file_name given as the argument, in the GEDIT editor, if the file exits \n
        if the file mentioned does not exists, creates and open the new file by the name \n
        given in the basename of the argument \n
        NOTE::  if no changes are made to the new file created, i.e the file remains empty,\n
                then the file is not saved to the locaiton"""
        if (os.path.exists(args) == False):
            print("new file created by the name: ",os.path.basename(args))
            subprocess.Popen(["vi", args])
            # print("no such file or directory exists")
            # print("if ypu are confident about the filename, pls try again by entering the complete location")
        if (os.path.exists(args) == True):
            subprocess.Popen(["gedit",args])

        val = "open " + args
        put(val)

    def do_exec(self,args):
        """executes or runs the given argument with the help of the associated application."""
        if ".py" in args:
            os.system("python3 "+args)
        val="exec"+args
        put(val)

    def do_mailto(self,args):
        """send a mail to the person mentioned as the argument of the function"""
        # global contacts
        contacts={}

        co=open("contacts.txt","a+")
        co.seek(0, 0)
        x = co.read().splitlines()
        for i in x:
            d=i.split(" ")
            contacts.update({d[0]:d[1]})



        def sendmail(receiver):
            body = input("please enter the text body of the mail: \n")
            print("\n")
            sender = "============email==========="

            msg = MIMEText(body)
            msg["From"] = sender
            msg["To"] = receiver
            msg["Subject"] = "Greetings from SARA"

            ss = smtplib.SMTP("smtp.gmail.com", 587)
            ss.starttls()
            ss.login("=========email==========", "=============password============")

            ss.send_message(msg)

            print("your mail has been sent")
            ss.quit()


        if args in contacts:
            receiver = contacts[args]
            sendmail(receiver)
        elif args=="":
            print("no receiver mentioned")
            exit()
        else:
            print("the receiver entered is not registered, press Y to register: ")
            choice2=input()
            if choice2 =="Y" or choice2 =="y":
                detail=input("please enter the email id: ")
                contacts.update({args:detail})
                co.write(args + " " + detail + "\n")
                print("contact regsitered \n")
                choice=input("would you like to continue?\n Press Y/N \n")
                if choice=="y" or choice=="Y":
                    receiver=contacts[args]
                    sendmail(receiver)
        co.close()




    # def do_contacts(self,args):
    #     print(contacts)




    #
    #
    #
    # def do_run(self,args):
    #     if os.path.exists(args):
    #         # f=os.open(args)
    #         # fd=fileinput.fileno()
    #         os.chmod(args,0o777)
    #         sb=subprocess.call(os.path.abspath(args))
    #         return sb.communicate()
    #


    # def do_pwd(self,sys.argv[1],):
    #     """returns the complete information about the user's password database \n
    #     SYNTAX: pwd<space>USERNAME \n
    #     OUTPUT FORMAT:  user_home_name
    #                     user_encrypted_password
    #                     user_id
    #                     user_group_id
    #                     user_host_name
    #                     user_home_directory
    #                     user_home_shell_used"""
    #     print(pwd.getpwnam(args))
    #     print("pls consider the help for the command to understand the output in a better way")
    #     print("\n")
    #     print(type(pwd.getpwnam(args)))
    #     for i in pwd.getpwnam(args):
    #         # if
    #         print(i)







if __name__ == '__main__':
    prompt = MyPrompt()
    f=open("history.txt","a+")

    p=getpass.getuser()
    prompt.prompt = "[" + p + "]:"
    prompt.cmdloop('Starting prompt...')
    f.close()

