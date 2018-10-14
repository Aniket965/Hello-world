class KotlinExtensionsExample {

    fun exampleMethod(input: String) {
        if (input.isBiggerThan(4)) {

        }
    }

}

private fun String.isBiggerThan(length: Int): Boolean {
    return this.length > length
}