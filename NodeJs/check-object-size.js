var sizeof = require('sizeof'); 
var anyObject = {
	'key': {
		name: 'abc', 
		age: 123, 
		active: true
	}
}
console.log(sizeof.sizeof(anyObject));	// 50
console.log(sizeof.sizeof(anyObject, true));	// 50B