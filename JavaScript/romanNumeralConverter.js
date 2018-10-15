function convertToRoman(num) {
    // assuming num does not exceed 3999
    var letters = ["I", "V", "X", "L", "C", "D", "M"];
    var numerals = "";
    var digits = [];
    
    digits.push( Math.floor( num / 1000 ) ); 
    digits.push( Math.floor( (num % 1000) / 100 ) );
    digits.push( Math.floor( (num % 100) / 10 ) );
    digits.push( num % 10 );
    
    numerals += repeatString("M", digits[0]);
    for(var i = 1; i < digits.length; i++){
        var letterIndex = 4 - ( (i - 1) * 2 );
        numerals += numeralsFromDigit(digits[i], letters.slice(letterIndex, letterIndex + 3));
    }
    
    return numerals;
}

function repeatString(_string, _repeats){
    var result = "";
    for(var i = 0; i < _repeats; i++){
        result += _string;
    }
    return result;
}

function numeralsFromDigit(_digitValue, _numeralArray){
    var result = "";
    if(_digitValue < 4){
        result += repeatString(_numeralArray[0], _digitValue);
    }
    else if(_digitValue == 4){
        result += _numeralArray[0] + _numeralArray[1];
    }
    else if(_digitValue < 9){
        result += _numeralArray[1] + repeatString(_numeralArray[0], _digitValue - 5);
    }
    else{
         result += _numeralArray[0] + _numeralArray[2];
    }
    return result;
}
