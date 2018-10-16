int Fibonacci(int number){
  if (number < 2) {
    return number;
  } 
  
  return Fibonacci(number - 2) + Fibonacci(number - 1);
}

void main() {
  print("Input sequence number to find Fibonacci number: ");
  String inputLine = stdin.readLineSync();

  int number;
  
  try {
    number = int.parse(inputLine);
  } on FormatException {
    print("You need to input the number.");
    return;
  }
  
  print("fib($number) = ${fib(number)}");
}
