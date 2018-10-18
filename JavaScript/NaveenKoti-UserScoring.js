    <html>
        <head>
            <title>sKoring</title>
        </head>
        <body>
            <center>
                    <h1 name="heading" point="10">This click will reward 10 points</h1>
                    <h3 name="subheading" point="5">This click will reward 5 points</h3>
            </center>
            <p>Current Visitor points:</p><input id="leadScore" type="number" value="0"/>
            
        </body>
        <script>
            var x = 0;
            document.addEventListener("click", function(event){
                // debugger;
                if(event && event.srcElement && event.srcElement.attributes && event.srcElement.attributes.point){
                    event.stopPropagation();
                    if(typeof x !== 'undefined'){
                        x += parseInt(event.srcElement.attributes.point.value);
                        document.getElementById("leadScore").value = x;
                        if(x > 15){
                            alert("Hooorayyy!!!");
                        }else{
                            alert("Cross 15 points and get a Hooray meassage");
                        }
                    }else{
                        alert("Please restart since the value is not configured")
                    }
                    // document.getElementById("demo").innerHTML = "Hello World";
                }
            });
        </script>
    </html>
