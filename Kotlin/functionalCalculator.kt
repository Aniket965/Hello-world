
fun sum (a: Int, b: Int) = a + b

fun minus (a: Int, b: Int) = a - b



fun calculator(a: Int, b: Int, op: (Int, Int) -> Int): Int {

    return op(a, b)

}

fun main (args: Array<String>){
    println(calculator(20, 10, ::sum))
    println(calculator(20, 10) { c, d ->
       c/d
    })
}