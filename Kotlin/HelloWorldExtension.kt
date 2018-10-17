// An extension function to send a "Hello" from any object in Kotlin!

fun Any.helloWorld() {
    println("""Hello from ${this::class.java}""")
}

// Demo

fun main(args: Array<String>) {
    val t = Test()
    t.helloWorld()
}

class Test
