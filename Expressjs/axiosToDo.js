let express = require("express");
let axios = require("axios");

let app = express();

app.get("/todo", (req, res) => {
  return axios
    .get("https://jsonplaceholder.typicode.com/todos/1")
    .then(response => res.send(response.data))
    .catch(err => res.send(err));
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, console.log(`Server has started on port ${PORT}`));
