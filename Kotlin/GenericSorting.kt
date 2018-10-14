fun main(args: Array<String>) {

    val numbers = mutableListOf(13, 4, 5, 6, 7, 1, 2)
    val names = mutableListOf("Jason", "Frank", "Sam", "Annabeth", "Percy", "Leo")

    sort(numbers)
    sort(names)

    println(numbers)
    println(names)
}

fun <T> sort(list: MutableList<T>) where T : Comparable<T> {

    for (i in 0 until list.size) {
        for (j in 0 until list.size) {
            if (list[i] < list[j]) {
                val temp = list[i]
                list[i] = list[j]
                list[j] = temp
            }
        }
    }
}