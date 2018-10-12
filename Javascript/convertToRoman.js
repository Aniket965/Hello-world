function convertToRoman(num) {
    let arr = [];
    let tmp;
    if (num >= 1000) {
        let times = parseInt(num / 1000);
        tmp = times;
        while (tmp > 0) {
            arr.push('M');
            tmp = tmp - 1;
        }
        num = num - (1000 * times);

    }
    if (num > 100) {
        let times = parseInt(num / 100);
        tmp = times;
        if (tmp == 4) {
            arr.push('C', 'D');
        } else if (tmp == 5) {
            arr.push('D');
        } else if (tmp == 9) {
            arr.push('C', 'M');
        } else if (tmp > 0 && tmp < 4) {
            while (tmp > 0) {
                arr.push('C');
                tmp = tmp - 1;
            }
        } else {
            arr.push('D');
            tmp = tmp - 5;
            while (tmp > 0) {
                arr.push('C');
                tmp = tmp - 1;
            }
        }
        num = num - (100 * times);
    }
    if (num > 10) {
        let times = parseInt(num / 10);
        tmp = times;
        if (tmp == 4) {
            arr.push('X', 'L');
        } else if (tmp == 5) {
            arr.push('L');
        } else if (tmp == 9) {
            arr.push('X', 'C');
        } else if (tmp > 0 && tmp < 4) {
            while (tmp > 0) {
                arr.push('X');
                tmp = tmp - 1;
            }
        } else {
            arr.push('L');
            tmp = tmp - 5;
            while (tmp > 0) {
                arr.push('X');
                tmp = tmp - 1;
            }
        }
        num = num - (10 * times);
    }
    if (num > 0) {
        let times = parseInt(num);
        tmp = times;
        if (tmp == 4) {
            arr.push('I', 'V');
        } else if (tmp == 5) {
            arr.push('V');
        } else if (tmp == 9) {
            arr.push('I', 'X');
        } else if (tmp > 0 && tmp < 4) {
            while (tmp > 0) {
                arr.push('I');
                tmp = tmp - 1;
            }
        } else {
            arr.push('V');
            tmp = tmp - 5;
            while (tmp > 0) {
                arr.push('I');
                tmp = tmp - 1;
            }
        }
    }
    return arr.join('');
}

console.log(convertToRoman(1000));
