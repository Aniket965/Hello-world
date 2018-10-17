fun main(args: Array<String>) {
    val numbers = 1..10
    var sum = 0
    numbers.forEach {
        if (it % 2 != 0) {

            val square = it * it
            sum += square

        }
    }
    println(sum)

    println(
            numbers
                    .filter { it % 2 != 0 }
                    .map { it * it }
                    .sum()
    )
}