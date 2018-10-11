using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace SendEmail
{
    class send_email
    {
        public static Boolean Send_new_mail(String to,String subject,String body)
        {
            var email_information = File.ReadAllText("email_configration_data.txt");
            var config_splits = email_information.Split('[');

            string smtp_address = config_splits[0];
            string smtp_port = config_splits[1];
            string your_email = config_splits[2];
            string your_password = config_splits[3];

            try {
                SmtpClient client = new SmtpClient(smtp_address, Convert.ToInt32(smtp_port));
                client.EnableSsl = true;
                client.Timeout = 10000;
                client.DeliveryMethod = SmtpDeliveryMethod.Network;
                client.UseDefaultCredentials = false;
                client.Credentials = new NetworkCredential(your_email, your_password);
                MailMessage stuml = new MailMessage();
                stuml.To.Add(to);
                stuml.From = new MailAddress(your_email);
                stuml.Subject = (subject);
                stuml.Body = (body);
                client.Send(stuml);
                if(stuml.IsBodyHtml == true)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            catch(Exception ex)
            {
               Console.WriteLine(ex);
            }
            return false;
        }
    }
}
