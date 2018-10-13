#region Using statements

using Microsoft.Win32;
using System.Windows.Forms;

#endregion Using statements

namespace WeekNumber
{
    internal static class Settings
    {
        #region Internal static property that updates registry for application to start when Windows start

        internal static bool StartWithWindows
        {
            get => Registry.GetValue("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", Application.ProductName, null) != null;
            set
            {
                using (var registryKey = Registry.CurrentUser)
                using (var regRun = registryKey?.OpenSubKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", true))
                {
                    if (value)
                    {
                        regRun?.SetValue(Application.ProductName, Application.ExecutablePath);
                    }
                    else
                    {
                        regRun?.DeleteValue(Application.ProductName);
                    }
                    registryKey?.Flush();
                }
            }
        }

        #endregion Internal static property that updates registry for application to start when Windows start
    }
}