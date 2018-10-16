const UrbanDictionary = require('easyurban');
const dictionary = new UrbanDictionary;
dictionary.lookup('\x52\x69\x63\x6b\x20\x52\x6f\x6c\x6c')
  .then(result => {
    console.log(result.list);
    console.log(`You just got ${result.list[0].word}ed!`);
  })
  .catch(console.error)
