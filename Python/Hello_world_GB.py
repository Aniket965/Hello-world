import webbrowser, os
content = ''' <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Hello world</title>
</head>
    <style>
        @import url('https://fonts.googleapis.com/css?family=Sarpanch:900');
        body
        {
            display: grid;
            grid-template-columns: 100%;
            text-align: center;
            background-image: radial-gradient( green, red);
        }
        h1
        {
            animation: type 10s infinite;
            overflow: hidden;
            white-space: nowrap;
            font-family: 'Sarpanch', sans-serif;
            font-size: 100px;
            color: #1d9099;
            text-shadow: 1vmin 1vmin 0 #E79C10, -1vmin -1vmin 0 #D53A33; 


        }
    
       @keyframes type 
        {
           from
           {
               width: 0%;
           }
           to 
           {
               width: 100%;
           }
       } 
    </style>
<body>
    <h1>HELLO WORLD!!!</h1>
</body>
</html>'''

def hello():
    opened_file = open('hello.html', 'w')
    opened_file.write(content)
    opened_file.close()
    url = os.path.abspath(opened_file.name)
    webbrowser.open('file://'+url)

hello()
