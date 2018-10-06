/**
 * Text pyramid generator. First argument is the height of the pyramid;
 * otherwise a default height of 5 will be used. Second argument is
 * the pyramid's composition; if no string specified, defaults to `^`.
 *
 * Compile:
 * kotlinc pyramid.kt -o pyramid
 *
 * Run:
 * ./pyramid.kexe <height> <composition>
 *
 * Example:
 * ./pyramid.kexe 4 itooshallkotlin!
 *    i
 *   too
 *  shall
 * kotlin!
 */

 const val BLOCK = "^"
 const val DEFAULT_HEIGHT = 5

fun main(args: Array<String>) {

    val height = readHeightArgument(args)
    val block = if (args.size > 1) args[1] else BLOCK 

    var currentCharIndex = -1
    val nextChar: () -> Char = {
        currentCharIndex = if (currentCharIndex + 1 < block.length) currentCharIndex + 1 else 0
        block[currentCharIndex]
    }

    (1..height step 2).forEach {
        repeat((height - it) / 2) {
            print(" ")
        }
        repeat(it) {
            print(nextChar())
        }
        println()
    }
}

private fun readHeightArgument(args: Array<String>): Int {
    return if (!args.isEmpty()) {
        try {
            args[0].toInt()
        } catch (ex: Exception) {
            println("Failed to understand argument. Using $DEFAULT_HEIGHT for height.\n")
            DEFAULT_HEIGHT
        }
    } else {
        println("No pyramid height specified. Using $DEFAULT_HEIGHT for height.\n")
        DEFAULT_HEIGHT
    } * 2
}