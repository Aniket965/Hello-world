object Fibonacci {
	def sequence(remaining: Int, last: Int = 1, secondLast: Int = 0): Unit = {
		println(last)
		if (remaining > 1) {
			sequence(remaining - 1, last + secondLast, last)
		}
	}
	def main(args: List[String]): Unit = {
		sequence(args(0).toInt)
	}
}
