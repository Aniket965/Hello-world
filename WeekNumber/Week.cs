#region Using statements

using System;
using System.Globalization;

#endregion Using statements

namespace WeekNumber
{
    internal class Week
    {
        #region Private variable that holds active week

        private int _week;

        #endregion Private variable that holds active week

        #region Constructor that initiates active week

        public Week() => _week = Current;

        #endregion Constructor that initiates active week

        #region Public function to check if week has changed

        public bool WasChanged()
        {
            var changed = _week != Current;
            if (changed)
            {
                _week = Current;
            }
            return changed;
        }

        #endregion Public function to check if week has changed

        #region Public static property that returns current week based on (hardcoded) calendar rule

        public static int Current => CultureInfo.CurrentCulture.Calendar.GetWeekOfYear(DateTime.Now,
            CalendarWeekRule.FirstFourDayWeek, DayOfWeek.Monday);

        #endregion Public static property that returns current week based on (hardcoded) calendar rule
    }
}