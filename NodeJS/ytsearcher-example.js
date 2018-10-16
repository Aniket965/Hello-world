const { YTSearcher } = require('ytsearcher');
const search = new YTSearcher({
  key: process.env.YTAPIKEY || '[redacted]',
});

search.search('oHg5SJYRHA0', { type: 'video' }).then(searchResult => {
  let result = searchResult.first;
  console.log(result);
  console.log(`You just got ${result.title}`);
  process.exit(0);
}).catch(console.error);
