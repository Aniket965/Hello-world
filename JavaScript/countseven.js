function count(n) {
    var ans = 0,
    value = 0;
    s = (n || '').toString(), // nにundefinedやnullを指定された場合の対処
    digits = s.length,
    values = s.split('').reverse();

    // nに1以上の整数値以外の値を指定された場合は0を返す仕様とした
    if(!s.match(/^[1-9]{1}[0-9]*$/g)) {
        console.log('nには1以上の整数を指定して下さい。');
        return ans;
    }

    while(0 <= --digits) {
        value = values[digits] - 0;
        ans += value * digits * Math.pow(10, digits - 1);
        if(value === 7) {
            ans += (n % Math.pow(10, digits)) + 1;
        } else if(8 <= value) {
            ans += Math.pow(10, digits);
        }
    }

    return ans;
}