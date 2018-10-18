#!/usr/bin/env python3

import requests
import string

from urllib3.util import parse_url
from bs4 import BeautifulSoup

def get_web_title(hyperlink):
    """Get title of given hyperlink.

    :param hyperlink: target url
    :type hyperlink: str
    :return: title of the website
    :rtype: str
    """
    web_schemes = ["http", "https"]
    given_scheme = parse_url(hyperlink).scheme.lower()
    if given_scheme in web_schemes:
        resp = requests.get(hyperlink)
        if resp.status_code == requests.codes.ok:
            soup = BeautifulSoup(resp.text, 'lxml')
            title = soup.title.string
            return title
        else:
            return "<Unnamed>"
    else:
        return "<Not allowed>"

targ = input("Please enter your target url:\n")
print(get_web_title(targ))
