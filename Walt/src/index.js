import makeGreeter from "./walt/greeter.walt";

const imports = {
  env: {
    greet: function() {
      console.log("hello, Walt!");
    }
  }
};

makeGreeter(imports)
  .then(({ instance }) => {
    instance.exports.greeter();
  })
  .catch(console.error);
