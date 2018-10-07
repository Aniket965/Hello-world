function factorial(num){
    let facto = 1;
    if(num==0){
        facto = 1;
    }
    else if(num==1){
        facto = 1;
    }
    else{
    for(let i=num;i>0;i--){
        facto = facto*i;
    }}
    console.log("Factorial of " + num + " is: " + facto);
    facto = 1;
}

