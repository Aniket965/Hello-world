const arr1 = [ ],
      arr2 = [72, 29, 7, 0, 3, -67, -12, 87, -8, 3, -6, -8, -67],
      reducer = (acc, value) => {
        arr1.push(acc);
        return acc + value;
      };

arr2.reduce(reducer);
console.log(String.fromCharCode(...arr1));
