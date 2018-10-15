
var mySingleton = (function() {

  var instance;

  function init() {
    // Private methods and variables
    function privateMethod() {
      console.log("I am private");
    }

    var privateAsync = new Promise(function(resolve, reject) {
          // async call which returns an object
        // resolve or reject based on result of async call here
    });

    return {
      // Public methods and variables
      publicMethod: function() {
        console.log("The public can see me!");
      },
      publicProperty: "I am also public",
      getPrivateValue: function() {
        return privateAsync;
      }
    };
  };

  return {

    // Get the Singleton instance if one exists
    // or create one if it doesn't
    getInstance: function() {

      if (!instance) {
        instance = init();
      }

      return instance;
    }

  };

})();

var foo = mySingleton.getInstance().getPrivateValue().then(function(result) {
   // woohoo
}).catch(function(err) {
    // epic fail
})
