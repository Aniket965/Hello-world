var instance1 = "hello-world";
var instance2 = "Hello_world";

function toCamelCase(str){
  
    var strAns = '';
    
    for(var i = 0; i < str.length; i++){
      
      if(str[i] == '-' || str[i] == '_'){
        continue;
      }
      
      else {
        
        if(str[i-1] == '-' || str[i-1] == '_'){
          strAns = strAns + str[i].toUpperCase();
        }  
        else{
          strAns = strAns + str[i];
        }
        
      }
      
    };
    
    return strAns;
  }

  var ans1 = toCamelCase(instance1);
  var ans2 = toCamelCase(instance2);

  console.log(ans1); // helloWorld
  console.log(ans2); // HelloWorld
