
let arr=[5,3,2,7,34,23,56,78,90,12,34,56,87,35,1];

Array.prototype.myFilter= function(functionPassed){
	let newArr=[];
	//console.log(this);			//object by which filter function is called.
	//console.log(functionPassed);	//function passed as its argument.
	for(let key in this)
	{
	 // console.log(this[key]);					//object key values
   	// console.log(functionPassed(this[key])); // return true or false depending upon function
   	if(functionPassed(this[key]))
   	{
   		newArr.push(this[key]);
   	}
	}
	return newArr;
}

function check(a)
{
	return a>20;
}
let requiredArr = arr.myFilter(check);
console.log(requiredArr);

function pairElement(str) {
let arr=str.split("");
let ans=[];
for(let i in arr)
{let nestArr=[];
 switch(arr[i])
 {
   case "A":{nestArr.push(arr[i],"T");break;}

   case "T":{nestArr.push(arr[i],"A");break;}

   case "C":{nestArr.push(arr[i],"G");break;}

   case "G":{nestArr.push(arr[i],"C");break;}
 }
 ans.push(nestArr);
}
return ans;
}

console.log(pairElement("GCG"));
