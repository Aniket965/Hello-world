const Json2csvParser = require('json2csv').Parser;
const fields = ['field1', 'field2', 'field3'];
const opts = { fields };
 
try {
  const parser = new Json2csvParser(opts);
  const csv = parser.parse(myData);
  console.log(csv);
} catch (err) {
  console.error(err);
}