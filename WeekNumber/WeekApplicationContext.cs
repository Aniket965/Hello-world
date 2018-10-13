#region Using statements

using System;
using System.Windows.Forms;

#endregion Using statements

namespace WeekNumber
{
    internal class WeekApplicationContext : ApplicationContext
    {
        #region Internal Taskbar GUI

        internal IGui Gui;

        #endregion Internal Taskbar GUI

        #region Private variables

        private readonly Week _week;
        private readonly Timer _timer;

        #endregion Private variables

        #region Constructor

        internal WeekApplicationContext()
        {
            try
            {
                Application.ApplicationExit += OnApplicationExit;
                _week = new Week();
                Gui = new TaskbarGui(Week.Current);
                _timer = GetTimer;
            }
            catch (Exception ex)
            {
                _timer?.Stop();
                Message.Show(Text.UnhandledException, ex);
                Application.Exit();
            }
        }

        #endregion Constructor

        #region Private Timer property

        private Timer GetTimer
        {
            get
            {
                var timer = new Timer
                {
                    Interval = 60000,
                    Enabled = true
                };
                timer.Tick += OnTimerTick;
                return timer;
            }
        }

        #endregion Private Timer property

        #region Private event handlers

        private void OnApplicationExit(object sender, EventArgs e) => Cleanup(false);

        private void OnTimerTick(object sender, EventArgs e)
        {
            if (!_week.WasChanged())
            {
                return;
            }
            var timer = (Timer)sender;
            timer?.Stop();
            Application.DoEvents();
            try
            {
                Gui?.UpdateIcon(Week.Current);
            }
            catch (Exception ex)
            {
                Message.Show(Text.FailedToSetIcon, ex);
                Cleanup();
                return;
            }
            timer?.Start();
        }

        #endregion Private event handlers

        #region Private Cleanup method

        private void Cleanup(bool forceExit = true)
        {
            _timer?.Stop();
            _timer?.Dispose();
            Gui?.Dispose();
            Gui = null;
            if (forceExit)
            {
                Application.Exit();
            }
        }

        #endregion Private Cleanup method
    }
}