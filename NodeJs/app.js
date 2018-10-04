const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const path = require('path');

const server = app.listen(8080, "localhost", () => {
    const port = server.address().port;
    const hostname = server.address().address;
    console.log(`Server running at ${hostname}:${port}`);
});
