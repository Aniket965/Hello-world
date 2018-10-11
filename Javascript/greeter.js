function greeter(name) {
  if (typeof name === "string") {
    console.log(`Hey there ${name}! I hope you have a great day today!`);
  }
  else {
    console.log("Oops, looks like you didn't pass me a string!");
  }
}

console.log(greeter("Alex"));