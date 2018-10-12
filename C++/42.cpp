#include <iostream>
#include <unistd.h>

int Answer_to_the_Ultimate_Question_of_Life_The_Universe_and_Everything;

int main()
{
  // TODO: Implement calculation
  // ...

  // We already know the answer, just for demonstration
  long Time = 23562000000000;
  sleep(Time);
  Answer_to_the_Ultimate_Question_of_Life_The_Universe_and_Everything = 42;
  std::cout << Answer_to_the_Ultimate_Question_of_Life_The_Universe_and_Everything << std::endl;
}
