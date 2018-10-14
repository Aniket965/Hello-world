fun main(args: Array<String>) { //Prints out it's own code
	val s = """fun main(args: Array<String>) { //Prints out it's own code
	val s = """

	val a = """^s\"\"\"^s\"\"\"\n\n\tval a = \"\"\"^a\"\"\"\n\tprint(\"^{a.replace(']' + 1, '$')}\")\n}\n"""
	print("$s\"\"\"$s\"\"\"\n\n\tval a = \"\"\"$a\"\"\"\n\tprint(\"${a.replace(']' + 1, '$')}\")\n}\n")
}