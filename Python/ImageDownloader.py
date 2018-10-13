import os
import urllib.request as ur
import sys
import bs4 as bs
def write_image(response):
    soup = bs.BeautifulSoup(response ,"lxml")
    i = 0
    for img in soup.find_all('img'):
        try:
            imglink = img.get('src')
        except:
            imglink = img.get('data-src')
        if(str(imglink)!='None'):
            try:
                name = "Image_"+str(i)+'.jpg'
                f = open(name,'wb')
                f.write(ur.urlopen(str(imglink)).read())
                f.close()
            except:
                pass
            print(imglink)
            i+=1
    print("Total images found : ",i)
    print("All images downloaded to current working directory")

def main():
    imtype = input("Enter the Name of the folder to save image ")
    url = input("Enter the url you want to scrap images from : ")
    os.chdir(os.path.dirname(os.path.abspath('__file__')))
    try:
        os.mkdir(imtype)
    except:
        pass
    os.chdir(imtype)

    headers = {}
    headers['User-Agent'] = "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.27 Safari/537.17"
    req = ur.Request(url,headers=headers)
    res = ur.urlopen(req).read()
    write_image(res)

    
if __name__ == "__main__" :
    main()