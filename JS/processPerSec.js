function doProcessing1(i){
	setTimeout(function get30FrequeciesInCurrentSecond(){
		for(var j=0;j<2;j++){
			doProcessing2(i,j)
		}
	}, i*5000);
}

function doProcessing2(i,j){
	setTimeout(function getFrequencyPer30(){
		//console.log('Hello-'+(i+1)+'-'+(j+1))
		var d = new Date();
		console.log(d.getMinutes(),d.getSeconds(),d.getMilliseconds())
	//},5000 * i +  2500 * j );
	  }, 2500 * j );
}

for(var i=0;i<10;i++){
doProcessing1(i);
}
