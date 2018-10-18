var express = require('express');
var bodyParser = require('body-parser')
var app = express();

app.use(bodyParser.urlencoded({ extended: false }))
 
// parse application/json
app.use(bodyParser.json())



app.get('/', function (req, res) {
  res.send('Hello World!');
});



// use port 3000 unless there exists a preconfigured port
var port = process.env.port || 8080;



app.listen(port,function(err){
    if(err){
        console.log(err);

    }
    else{
        console.log("server started");
    }
});
