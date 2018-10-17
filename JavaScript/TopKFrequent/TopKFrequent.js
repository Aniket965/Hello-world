const Heap = require('./Heap');

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const map = new Map();
    nums.forEach(num => {
        map.has(num) ?
            map.set(num, map.get(num) + 1)
            :
            map.set(num, 1)
    });

    const maxHeap = new Heap(function(a,b) {
        return b.value - a.value;
    });

    map.forEach((value, key) => {
        maxHeap.add({key, value})
    });
    
    const res = [];
    while(res.length < k) {
        res.push(maxHeap.poll().key);
    }
    
    return res;
};

module.exports = topKFrequent;