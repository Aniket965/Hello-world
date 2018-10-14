import Foundation

func isPrime(number: Int) -> Bool {
    if number <  2 { return false }
    let squareRoot = Int(sqrt(Double(number)))
    if squareRoot * squareRoot == number { return false }
    for i in 2..<Int(ceil(sqrt(Double(number)))) where number % i == 0 {
       return false
    }
    return true
}
