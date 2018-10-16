import org.joda.time.DateTime

object HiHf {
   def main(args: Array[String]) {
		val year: Int = DateTime.now().getYear
      	println("Hi, Hacktoberfest " + year + "!!") 
   }
}
