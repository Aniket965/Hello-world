const app = require('express')();

app.get('/', (req, res)=>{
    res.send("Hello, World!");
})

app.listen(3000, ()=>{
    console.log("Listening on port 3000");
})