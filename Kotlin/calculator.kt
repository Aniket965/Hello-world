package main

fun main(args: Array<String>) {
	println("Hi welcome to calcy the calculator. \nYou can only use +, -. * and /, and only 2 numbers at total\nAnd only integers :)");

	val input = readLine();

	input?.let {
		val delimiter =
			when {
				input.contains("+") -> "+"
				input.contains("-") -> "-"
				input.contains("*") -> "*"
				input.contains("/") -> "/"
				else -> ""
			}

		val values = input.split(delimiter) as ArrayList<String>;

		val firstValue = values[0].trim().toInt()
		val secondValue = values[1].trim().toInt()

		when (delimiter) {
			"+" -> println(firstValue + secondValue)
			"-" -> println(firstValue - secondValue)
			"*" -> println(firstValue * secondValue)
			"/" -> println(firstValue / secondValue)
		}
	}
}
