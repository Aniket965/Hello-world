object HelloYou {
  def main(args: Array[String]): Unit = {
    if (args.size == 0) println("Hello, You!")
    else println("Hello, " + args.head)
  }
}
