fun main(args: Array<String>) {

    println(divideIfWhole(64, 7))
}

fun divideIfWhole(value: Int, divisor: Int): Int? {

    val quotient = value / divisor
    val remainder = value % divisor

    return if (remainder == 0) quotient else null
}