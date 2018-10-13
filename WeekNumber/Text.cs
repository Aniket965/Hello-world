#region Using statement

using System.Windows.Forms;

#endregion Using statement

namespace WeekNumber
{
    internal static class Text
    {
        #region Static string variables

        internal static readonly string About = Application.ProductName + " by Voltura AB\r\rhttps://github.com/voltura/VolturaTools\r\rFree for all.";
        internal static readonly string ApplicationNameAndVersion = Application.ProductName + " version " + Application.ProductVersion;
        internal static readonly string AboutMenu = "About " + Application.ProductName;
        internal static readonly string ExitMenu = "Exit " + Application.ProductName;
        internal static readonly string FailedToSetIcon = "Could not set Icon. Please report to feedback@voltura.se!\r\r";
        internal static readonly string FailedToUpdateRegistry = "Could not update registry. Please report to feedback@voltura.se!\r\r";
        internal static readonly string StartWithWindowsMenu = "Start with Windows";
        internal static readonly string SeparatorMenu = "-";
        internal static readonly string UnhandledException = "Something went wrong. Please report to feedback@voltura.se!\r\r";
        internal static readonly string Week = "Week ";

        #endregion Static string variables
    }
}