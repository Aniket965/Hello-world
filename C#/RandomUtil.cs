using System.IO;

namespace Frontend_Automated_Tests.Util
{
    public class RandomUtil
    {   
        /// <summary>
        /// Get the Random String.
        /// </summary>
        /// <returns></returns>
        public static string GetRandomString()
        {
           return Path.GetRandomFileName();
        }
    }
}
