/**
 * for loop that iterates up to given no n 
 * while outputting 
 * "fizz" at multiples of 3, "buzz" at multiples of 5 and "fizzbuzz" at multiples of 3 and 5
 */


const funPrint = (n)=>{
    for(i=1;i<=n;i++){
        let s = '';
        if(i%3==0)
        s+='fizz';
        if(i%5==0)
        s+='buzz';
        if(s==='')
        console.log(i);
        else
        console.log(s);
    }
}

funPrint(n);
 