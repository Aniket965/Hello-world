/**
 *  Kotlin delegation pattern example.
 */
interface Greeter {
    fun greet()
}

class GreetLoudlyBehavior(val n:String): Greeter {
    override fun greet() = println("${n.toUpperCase()} !!!")
}

class MyGreeter(n:String): Greeter by GreetLoudlyBehavior(n)

fun main(args: Array<String>) {
    val greeter = MyGreeter("Hello world")
    greeter.greet()
}
