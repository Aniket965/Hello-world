import 'dart:async';


/// Simple dart program showcasing the asynchornous nature of dart

/// Prints the passed message after a fixed delay
/// enclosing parametes within {} makes them optional and named
void lazy_print({message = 'Hello,World!', wait = false}) async {
  /// Dart 2.0 no longer requires new keyword,
  /// so we can write Duration... instead of new Duration...
  const waitDuration = Duration(milliseconds: 300);
  if(wait) {
    await Future.delayed(waitDuration);
  } else {
    Future.delayed(waitDuration);
  }
  print(message);
}

void main() async {
  await lazy_print();
  lazy_print(message: 'Hello 1');
  lazy_print(message: 'Hello 2', wait: true);
  lazy_print(message: 'Hello 3');
}

/* Output
 *
 * Hello,World!
 * Hello 1
 * Hello 3
 * Hello 2
 */
