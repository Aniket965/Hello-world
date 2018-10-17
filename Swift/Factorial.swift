func factorial(for number: UInt) -> UInt {
    if number == 0 {
        return 1
    } else {
        return number * factorial(for: number - 1)
    }
}

let x = factorial(for: 10)
print(x)
