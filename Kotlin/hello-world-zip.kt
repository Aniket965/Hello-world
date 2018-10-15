/**
 *  Kotlin hello world ZIP
 */
fun main(args: Array<String>) {
    val A = listOf("Hello", " ", ",", "World")
    val B = listOf(",", "hello", " ", "!")

    println(A.zip(B) { a, b -> "$a$b" }.joinToString(""))
}
