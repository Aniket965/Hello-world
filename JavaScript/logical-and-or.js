let isGuestOneVegan = true
let isGuestTwoVegan = false

if (isGuestOneVegan && isGuestTwoVegan){
    console.log('Only offer up vegan Dishes.')
}
else if(isGuestOneVegan || isGuestTwoVegan){
    console.log('Make Sure to offer up some vegan options');
}
else{
    console.log('offer up anything on the menue');
    
}