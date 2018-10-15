'use strict'

const sort = function insertionSort (items) {
    for (let i = 0; i < items.length; i++) {
        let value = items[i]
        for (let j = i - 1; j > -1 && items[j] > value; j--) {
            items[j + 1] = items[j]
        }
        items[j + 1] = value
    }

    return list
}

const list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
console.log(sort(list))