import org.joda.time.DateTime


object HelloHacktoberfest {
   /*
   * This will print 'Hello, Hacktoberfest YEAR' as the output
   */
   def main(args: Array[String]) {
		val year: Int = DateTime.now().getYear
      	println("Hello, Hacktoberfest " + year) // prints Hello World
   }
}
