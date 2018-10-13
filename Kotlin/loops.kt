//Different Ways to Iterate A For Loop in Kotlin

package main

fun main(args: Array<String>) {

    for (i in 1..5) {
        println(i)
    }
       print("for (i in 1..5) print(i) = ")
    for (i in 1..5) print(i)

    println()

    print("for (i in 5..1) print(i) = ")
    for (i in 5..1) print(i)             // prints nothing

    println()

    print("for (i in 5 downTo 1) print(i) = ")
    for (i in 5 downTo 1) print(i)

    println()

    print("for (i in 1..4 step 2) print(i) = ")
    for (i in 1..5 step 2) print(i)

    println()

    print("for (i in 4 downTo 1 step 2) print(i) = ")
    for (i in 5 downTo 1 step 2) print(i)
    
        var language = arrayOf("Ruby", "Koltin", "Python", "Java")
    println()
    for (item in language.indices) {

        // printing array elements having even index only
        if (item%2 == 0)
            println(language[item])
    }
    
        var text= "Kotlin"

    for (letter in text) {
        println(letter)
    }
    // ForEach
    (0..10).forEach { println(it) }
}