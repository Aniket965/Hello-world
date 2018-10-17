var x = ['a','b','c','d','e','f'],
	possibleCombinations = [];

x.forEach(function(elmt){
	possibleCombinations.push(elmt)
	var rest = x.slice( x.indexOf(elmt) + 1);
	myCombinationGeneration(elmt,rest)
})
function myCombinationGeneration(current,rest){	
	rest.forEach( function( restEle ){
		possibleCombinations.push( current + restEle )
		var rest2 = x.slice( x.indexOf(restEle) + 1);
		myCombinationGeneration( current + restEle, rest2)
	})
}
console.log( possibleCombinations )
