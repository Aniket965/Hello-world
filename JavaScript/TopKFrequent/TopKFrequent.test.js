const topKFrequent = require('./TopKFrequent');

describe('top k frequent numbers in list', () => {
    test('', () => {
        expect(topKFrequent([1,1,1,2,2,3], 2)).toEqual([1,2])
    })
})