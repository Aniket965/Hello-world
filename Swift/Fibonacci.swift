import Foundation

func fibonacci(n: Int) -> Int {
    // Some temporary variables.
    var a = 0
    var b = 1
    // Add up numbers to the desired iteration.
    for _ in 0..<n {
        let temp = a
        a = b
        b = temp + b
    }
    return a
}

// Loop over values 0 through 14 inclusive.
for i in 0..<15 {
    // Call Fibonacci method.
    let result = fibonacci(n: i)
    print("Fibonacci \(i) = \(result)")
}
