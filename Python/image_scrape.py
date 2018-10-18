from selenium import webdriver
import urllib
"""
Minimal image scraper using selenium, defaulted to the Chrome driver
"""
class ChromefoxTest:
    def __init__(self,url):
        self.url=url
        self.uri = []
        self.folder = '/scraped/images/folder/'

    def chromeTest(self):
        self.driver=webdriver.Chrome()
        self.driver.get(self.url)
        self.r=self.driver.find_elements_by_tag_name('img')
        for v in self.r:
            src = v.get_attribute("src")
            self.uri.append(src)
            pos = len(src) - src[::-1].index('/')
            print src[pos:]
            self.g=urllib.urlretrieve(src, "/".join([self.folder, src[pos:]]))

FT=ChromefoxTest("Webpage.to/scrape.html")
FT.chromeTest()
