let language = window.navigator.language||navigator.browserLanguage; 
 if (language === "nl-BE"){
	document.write("Hallo wereld, maar in het Vlaams");
}
else if (language === "nl-NL"){
	document.write("Hallo wereld, maar in het Nederlands");
}else{
	document.write("Hello World");
}
