class InlineMethodsExample {

    /*
    * Inline Methods instruct the compiler to copy + paste code into the call site during compilation.
    * This contains some obvious benefits in that we can reduce overhead of certain methods by providing no-cost helper functions.
    * As we all know on Android, we look for ways to minimize method count impact to keep our precious apps under the 65K method limit.
    * */

    fun callExample() {
        val name = "John Doe"
        log("Tracking Name Calls") { "This $name is my name." }
    }

    inline fun log(tag: String, logMessage: () -> String) {
        if (BuildConfig.DEBUG) {
            Log.d(tag, logMessage())
        }
    }
}