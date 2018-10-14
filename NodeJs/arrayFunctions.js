//forEach
 const forEach = (array, fn) => {
 	for(let i=0; i<array.length; i++){
 		fn(array[i], i)
 	}
 }

 forEach([1,2,3], el => console.log(el))

 const map = (array, fn) => {
 	const newArray = []
 	forEach(array, el => newArray.push(fn(el)))
 	return newArray
 }

 console.log(map([1,2,3], el => el*3))

 const filter = (array, fn) => {
 	const newArray = []
 	forEach(array, el => {
 		if(fn(el)) newArray.push(el)
 	})
 	return newArray
 }

 console.log(filter(["nickname", "user", "game", "gamer"], el => /er$/.test(el)))