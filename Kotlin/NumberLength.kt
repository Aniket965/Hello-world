/**
* Extension fot Int to return the length of the number
*/
fun Int.length() = when(this) {
    0 -> 1
    else -> Math.log10(Math.abs(toDouble())).toInt() + 1
}


