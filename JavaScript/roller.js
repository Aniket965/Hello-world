// This is a simple script to flatten a given json object
// author - Kshitij Mhatre
// run on node by
// $node roller.js
// test objects
a = `
{
    "a": "bcd",
    "b": {
      "c": "efg"
    }
  } 

`;
b = `
{
    "nails": [
      {
        "summer": "already",
        "arrangement": false,
        "tears": "factor",
        "come": -1068746490,
        "shelf": "front",
        "thou": "putting"
      },
      "fill",
      true,
      "beautiful",
      489479050,
      "charge"
    ],
    "manufacturing": "dig",
    "selection": false,
    "railroad": true,
    "eight": 416446621.87269616
  }
`;

ob = JSON.parse(b);
// ob.hasOwnProperty();

console.log(ob);

flat = [];

parent = "";
isa = false;
function fun(parent, ob, isa) {
  for (let prop in ob) {
    //console.log(ob[prop]);

    //flat.push(parent + " -> ", ob[prop]);

    if (typeof ob[prop] == "object")
      if (isa)
        fun(parent.concat(`[${prop}]`), ob[prop], Array.isArray(ob[prop]));
      else fun(parent.concat(".", prop), ob[prop], Array.isArray(ob[prop]));
    else {
      if (isa) flat.push(parent.concat(`[${prop}] -> ${ob[prop]}`));
      else flat.push(parent.concat(`.${prop} -> ${ob[prop]}`));
    }
  }
}

fun(parent, ob);

console.log("-------------------Flat jsonofaB--------------");
for (item in flat) {
  console.log(flat[item]);
}
