var express = require('express');
var app = express();
app.set('view engine', 'pug');
app.get('/', function(req, res, next) {
 res.render('index', {world: 'World'});
})
app.listen(3000, function(){
 console.log('Express listen port: 3000');
})