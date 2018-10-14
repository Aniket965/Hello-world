class Main
  def self.run
    arr = [93, 2, 47, 1, 902]
    puts merge_sort(arr, 0 , arr.length - 1)
  end

  def self.merge_sort(arr, left, right)
    return if left >= right
    middle = (left + right) / 2
    merge_sort(arr, left, middle)
    merge_sort(arr, middle + 1, right)
    merge(arr, middle, left, right)
    arr
  end

  def self.merge(arr, middle, left, right)
    leftArr = arr[(left)..(middle)]
    rightArr = arr[(middle + 1)..(right)]
    i = j = 0
    k = left

    while i < leftArr.length && j < rightArr.length
      if leftArr[i] < rightArr[j] 
        arr[k] = leftArr[i]
        i = i + 1
      else
        arr[k] = rightArr[j]
        j = j + 1  
      end
      k = k + 1
    end

    while i < leftArr.length 
      arr[k] = leftArr[i]
      i = i + 1
      k = k + 1
    end

    while j < rightArr.length 
      arr[k] = rightArr[j]
      j = j + 1
      k = k + 1
    end

  end

end


Main.run