import os
dirname = input("Project dir name: ")

os.makedirs(dirname)
index = open(dirname + "/index.html", "w")
index.write("<html>" + \
            "\n\t<head>" + \
                "\n\t\t<title>" + dirname + "</title>" + \
                "\n\t\t<link rel='stylesheet' type='text/css' href='css/style.css'>" + \
                "\n\t\t<script type='text/javascript' src='js/script.js'></script>" + \
            "\n\t</head>" + \
            "\n\t<body>" + \
            "\n\t</body>" + \
            "\n</html>")
index.close()

os.makedirs(dirname + '/css')
css = open(dirname + "/css/style.css", "w")
css.close()

os.makedirs(dirname + '/js')
js = open(dirname + "/js/script.js", "w")
js.write("window.onload = function() {\n\n}")
js.close()

