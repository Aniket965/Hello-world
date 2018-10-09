const express = require("express");
const app = express();
app.set('view engine', 'ejs');

app.get("/", (req, res) => {
    res.render('index.ejs');
})

port = 3000 || process.env.port;
app.listen(port,() =>
    console.log(`running on port ${port}`)
    )

