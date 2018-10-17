func findNumber(arr:[Int], k:Int) -> String {
  let isAvailable = arr.contains(k)
  var result:String = "NO"
  if isAvailable {
    result = "YES"
  }
  return result
}

let testArr = [1,2,3,4,5,6,7,8,9,10]

print(findNumber(arr: testArr, k: 10))
