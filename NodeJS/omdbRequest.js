// Include the request npm package (Don't forget to run "npm install request" in this folder first!)
var request = require("request");

// Then run a request to the OMDB API with the movie specified
request("http://www.omdbapi.com/?t=halloween&y=&plot=short&apikey=96837c43", function(error, response, body) {

  // If the request is successful (i.e. if the response status code is 200)
  if (!error && response.statusCode === 200) {

  //parse the response to retrieve data pertaining to request
    console.log("The title is: " + JSON.parse(body).Title + "\nThe year the movie came out is: " + JSON.parse(body).Year 
    + "\nThe IMDB Rating is: " + JSON.parse(body).imdbRating + "\nRotten Tomatoes Rating: " + JSON.parse(body).Ratings[1].Value 
    + "\nCountry of production: " + JSON.parse(body).Country + "\nLanguage of movie: " + JSON.parse(body).Language
    + "\nPlot: " + JSON.parse(body).Plot + "\nActors in movie: " + JSON.parse(body).Actors);
  }
});