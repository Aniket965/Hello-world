object BeerSong {
    fun verses(from: Int, to: Int): String {
        return (to..from).reversed().map {
            when (it) {
                0 -> "${it.bottles().capitalize()} of beer on the wall, ${it.bottles()} of beer.\n" +
                        "Go to the store and buy some more, ${99.bottles()} of beer on the wall.\n"
                else -> "${it.bottles()} of beer on the wall, ${it.bottles()} of beer.\n" +
                        "Take ${it.one()} down and pass it around, ${(it - 1).bottles()} of beer on the wall.\n"
            }
        }.joinToString("\n")
    }

    private fun Int.bottles() = when (this) {
        0 -> "no more bottles"
        1 -> "1 bottle"
        else -> "$this bottles"
    }

    private fun Int.one() = if (this == 1) "it" else "one"
}

fun main(args: Array<String>) {
    println(BeerSong.verses(99, 0))
}