// Demo of callbacks
// 1. callback solution 1
// 2. promises solution 2


// sample delay - or can use setTimeout
const sleep = (milliseconds) => {
    var start = new Date().getTime();
    for (var i = 0; i < 1e7; i++) {
      if ((new Date().getTime() - start) > milliseconds){
        break;
      }
    }
  }
  
  const fetchData = (callback) => {
    const person = {
      id: 20,
      name: "Lenny",
    };
  
    // simulate 2seconds delay on a network
    console.log("Fetching...");
    sleep(3000);
    callback(person);
  }
  
  /* solution 1 */
  // callback - called when data is available
  const callback = (object) => {
    console.log("Your data is here: ", object);
  }
  
  console.log("----- callback -----");
  fetchData(callback);
  
  // ################################################################
  /* solution 2 */
  // Promises
  // no more callback, the async function returns a Promise
  
  const fetchData2 = () => {
    const person = {
      id: 20,
      name: "Lenny",
    };
  
    // simulate 2seconds delay on a network with setTimeout
    return new Promise((resolve, reject) => {
      // simulate 2seconds delay on a network
      console.log("Fetching...");
      sleep(3000);
      resolve(person);    // return response with resolve
      // reject if there is any error
    });
  }
  
  console.log("----- promises -----");
  
  fetchData2().then(results => {
    console.log("Your data is here: ", results);
  });
  
  
  /*
  NOTE:
  doing this logs the actual Promise itself
  console.log("Your data is here: ", fetchData2());
  and Promises can be chained = then().then()
  */
  
  
  //========== SCRATCH section ================//
  
  // fetch('https://jsonplaceholder.typicode.com/users')
  //   .then(response => response.json())
  //   .then(json => console.log(json))
  
  // alternative
  
  // setTimeout(() => {
  //   callback(person);  // return data
  // }, 3000);