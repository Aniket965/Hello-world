using System;
using System.IO;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace WebDriver
{
    public class WebDriverProvider
    {
        /// <summary>
        /// Get the Webdriver Instance based on the Browser.
        /// </summary>
        /// <param name="browser"></param>
        /// <returns></returns>
        public IWebDriver GetIWebDriverInstance(string browser)
        {
            
            if (browser.Equals("chrome"))
            {
                return CreateChromeDriver();
            }
            else if (browser.Equals("firefox"))
            {
                throw new Exception("No Support for Firefox Browser, Please run test on Chrome browser.");
            }
            else if (browser.Equals("ie"))
            {
                throw new Exception("No Support for Internet Explorer Browser, Please run test on Chrome browser.");
            }
            else
                throw new Exception("Please check the provided browser:" + browser + ", valid Values are chrome,firefox and ie");
        }

        /// <summary>
        ///  Create Chrome Driver Instance and return.
        /// </summary>
        /// <returns></returns>
        private IWebDriver CreateChromeDriver()
        {
            IWebDriver driver = new ChromeDriver(Directory.GetCurrentDirectory());
            driver.Manage().Window.Maximize();
            return driver;
        }
        

    }
}
