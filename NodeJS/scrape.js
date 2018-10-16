var fs = require('fs');
var request = require('request');
var cheerio = require('cheerio');

url = 'http://www.imdb.com/title/tt1229340/';

request(url, function(error, response, html){
    if(!error){
        // Next, we'll utilize the cheerio library on the returned html which will essentially give us jQuery functionality
  console.log(html)
        var $ = cheerio.load(html);
        var title, release, rating;
            var json = { title : "", release : "", rating : ""}
            $('.header').filter(function(){

                // Let's store the data we filter into a variable so we can easily see what's going on.
     
                     var data = $(this);
     
                // In examining the DOM we notice that the title rests within the first child element of the header tag. 
                // Utilizing jQuery we can easily navigate and get the text by writing the following code:
     
                     title = data.children().next().text();
                       console.log(title)
                // Once we have our title, we'll store it to the our json object.
     
                     json.title = title;
                 })
    }
})
