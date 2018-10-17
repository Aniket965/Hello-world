class MaxSubArray {
    func maxSubArray(_ nums: [Int]) -> Int {
        
        var maxEnd = 0
        var maxSliceSum = Int.min
        var positiveSliceExist = false
        
        for num in nums {
            if num >= 0 && !positiveSliceExist {
                positiveSliceExist = true
                maxEnd = 0
            }
            
            if positiveSliceExist {
                maxEnd = max(0, num + maxEnd)
            } else {
                maxEnd = num
            }
            
            maxSliceSum = max(maxSliceSum, maxEnd);
        }
        
        return maxSliceSum
    }
}