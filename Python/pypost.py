import pycurl
from faker import Faker

IP = "76.1.89.29"
PORT = "59378"

fckr = Faker()

try:
    from urllib.parse import urlencode
except ImportError:
        from urllib import urlencode


try:
    from StringIO import StringIO
except ImportError:
    from io import StringIO

URL="write url"


def get_method(curl, url):
    buffer = StringIO()
    curl.setopt(curl.URL,url)
    curl.setopt(curl.WRITEDATA, buffer)
    curl.perform()
    curl.close()
    body = buffer.getvalue()
    print(body)

def post_method(curl, url, argument):
    curl.setopt(curl.URL,url)
    post_data = argument
    postfields = urlencode(post_data)
    curl.setopt(curl.POSTFIELDS, postfields)
    # curl.setopt(pycurl.HTTPHEADER,['Content-Type: application/json'])
    # curl.setopt(pycurl.PROXY, "%s:%s" % (IP, PORT))
    # curl.setopt(pycurl.PROXYTYPE, pycurl.PROXYTYPE_SOCKS5)
    curl.setopt(curl.VERBOSE, True)
    curl.setopt(curl.USERAGENT, "Mozilla/5.0 (Windows; U; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)")
    curl.perform()
    curl.close()

def main():
    c = pycurl.Curl()
    post_method(c, URL, {"txt_name":fckr.name(), "txt_email": fckr.email(), "txt_company": fckr.address(), "txt_phone":fckr.phone_number() ,"txt_comment" : fckr.text() ,"submit": "submit"})


main()
# i = 0
# while i < 1000:
#     main()
#     i +=1
#     print("[+] Posting Request Number ",i)
#     sleep(1)
