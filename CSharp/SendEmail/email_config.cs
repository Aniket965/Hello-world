using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SendEmail
{
    class email_config
    {
        public static Boolean save_config(String smtp_server_address,String smtp_port,String yourEmail,String yourPassword)
        {
            String config_file_data = smtp_server_address + "[" + smtp_port + "[" + yourEmail + "[" + yourPassword;
            String config_file_name = "email_configration_data.txt";
            File.WriteAllText(config_file_name, config_file_data);
            return true;
        }
    }
}
