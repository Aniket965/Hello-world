const express = require('express');
const app = express();
var port = 3000 || process.env.PORT;

app.set('view engine', 'ejs');

app.get("/", (req, res) => {
    res.render('index.ejs');
});

app.listen(port, function() {
    console.log('running on port ${port}');
}
