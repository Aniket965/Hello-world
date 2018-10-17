fun String.Companion.sayHello() : String{
    return "Hello World"
}

fun String.print() {
    println(this)
}

fun main (args : Array<String>){
    String.sayHello().print()
}