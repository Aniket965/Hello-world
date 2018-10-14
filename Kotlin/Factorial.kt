fun main(args: Array<String>) {

    println("Enter the value you want to find factorial of: ")
    val factorialOf: String = readLine().orEmpty()
    var num = factorialOf.toInt()
    var result = 1

    while (num > 0) {
        result *= num
        num--
    }

    println("The factorial of $factorialOf is: $result")
}