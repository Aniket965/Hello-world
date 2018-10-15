function reverseInt(n) {
    const reversed =  n.toString().split('').reverse().join('');
   
    return parseInt(reversed) * Math.sign(n);
    
   }
   
   const numb = -900;
   console.log(reverseInt(numb))