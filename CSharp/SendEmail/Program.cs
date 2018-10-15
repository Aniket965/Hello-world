using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using SendEmail;
using System.IO;

namespace SendEmail
{

    class Program
    {
        
        static void Main(string[] args)
        {
            if (File.Exists("email_configration_data.txt"))
            {
                bool fileInfo = check_config_file();
                if(fileInfo == true)
                {
                    edite_email_config();
                }
                else
                {

                    String user_input;
                    Console.WriteLine("|-------------------------------------------|");
                    Console.WriteLine("|                  SEND EMAILS              |");
                    Console.WriteLine("|-------------------------------------------|");
                    Console.WriteLine("|                                           |");
                    Console.WriteLine("|    SEND EMAIL              -> 1           |");
                    Console.WriteLine("|    CHANGE EMAIL CONFIG     -> 2           |");
                    Console.WriteLine("|    EXIT                    -> 3           |");
                    Console.WriteLine("|                                           |");
                    Console.WriteLine("|-------------------------------------------|");
                    Console.Write("    ENTER YOUR CHOICE -> ");
                    user_input = Console.ReadLine();
                    decision(user_input);
                }
            }
            else
            {
                var myFile = File.Create("email_configration_data.txt");
                myFile.Close();
                Console.Clear();
                Main(args);
            }
        }

        static void decision(String choice)
        {
            String[] args = new String[0];
            switch (choice)
            {
                case "1":
                    if(new_email_body() == true)
                    {
                        Console.WriteLine("|    Email sent successfully                |");
                        Send_email_again();
                    }
                    else
                    {
                        Console.WriteLine("|    Email sent unsuccessfully              |");
                        Send_email_again();
                    }
                    break;
                case "2":
                    edite_email_config();
                    break;
                case "3":
                    Console.Write("    ARE YOU SURE ? (Y)es -> ");
                    String exit_choice = Console.ReadLine();
                    if(exit_choice == "Y" || exit_choice == "y")
                    {
                        Environment.Exit(0);
                    }
                    else
                    {
                        Console.Clear();
                        Main(args);
                    }
                    break;
                default:
                    Console.Clear();
                    Main(args);
                    break;
            }
        }

        private static Boolean new_email_body()
        {
            Console.WriteLine("|                                           |");
            Console.WriteLine("|-------------------------------------------|");
            Console.WriteLine("|                                           |");

            Console.Write("    Subject -> ");
            String to_subject = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");

            Console.Write("    To -> ");
            String to_email = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");

            Console.Write("    Body -> ");
            String to_body = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");

            if(send_email.Send_new_mail(to_email, to_subject, to_body) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private static void Send_email_again()
        {
            String[] args = new String[0];
            Console.WriteLine("|                                           |");
            Console.WriteLine("|-------------------------------------------|");
            Console.WriteLine("|                                           |");
            Console.Write("    SEND EMAIL AGAIN (Y)es / (N)o ");
            String exit_choice = Console.ReadLine();
            if (exit_choice == "Y" || exit_choice == "y")
            {
                Console.Clear();
                new_email_body();
            }
            else
            {
                Console.Clear();
                Main(args);
            }
        }

        private static Boolean check_config_file()
        {
                if(new FileInfo("email_configration_data.txt").Length == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
        }

        private static void edite_email_config()
        {
            String[] args = new String[0];
            Console.WriteLine("|-------------------------------------------|");
            Console.WriteLine("|   ENTER YOUR EMAIL CONFIGRATION DETAILS   |");
            Console.WriteLine("|-------------------------------------------|");
            Console.WriteLine("|                                           |");
            Console.Write("    Enter SMTP server address -> ");
            String smtp_server_add = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");
            Console.Write("    Enter SMTP port -> ");
            String smtp_server_port = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");
            Console.Write("    Your Email -> ");
            String your_email = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");
            Console.Write("    Your Password -> ");
            String your_password = Console.ReadLine();
            Console.WriteLine("|-------------------------------------------|");
            Console.Write("   All set ? (Y)es (N) -> ");
            String exit_choice = Console.ReadLine();
            if (exit_choice == "Y" || exit_choice == "y")
            {
                bool config_create = email_config.save_config(smtp_server_add, smtp_server_port, your_email, your_password);
                if(config_create == true)
                {
                    Console.WriteLine("|-------------------------------------------|");
                    Console.WriteLine("| Config Save Successful. press any key     |");
                    Console.WriteLine("|-------------------------------------------|");
                    Console.ReadKey();
                    Console.Clear();
                    Main(args);
                }
            }
            else
            {
            }
        }
    }
}
