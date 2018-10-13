#region Using statements

using System;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

#endregion Using statements

namespace WeekNumber
{
    internal class Program
    {
        #region Private variable to allow only one instance of application

        private static readonly Mutex Mutex = new Mutex(true, "550adc75-8afb-4813-ac91-8c8c6cb681ae");

        #endregion Private variable to allow only one instance of application

        #region Application starting point

        [STAThread]
        private static void Main()
        {
            if (!Mutex.WaitOne(TimeSpan.Zero, true))
            {
                return;
            }
            Application.EnableVisualStyles();
            Application.VisualStyleState = VisualStyleState.ClientAndNonClientAreasEnabled;
            var context = new WeekApplicationContext();
            if (context?.Gui != null)
            {
                Application.Run(context);
            }
            Mutex.ReleaseMutex();
        }

        #endregion Application starting point
    }
}