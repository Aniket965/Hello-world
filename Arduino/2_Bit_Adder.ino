
int a1,a2,b1,b2,s1,s2,c1,c2;
void setup() {
  // This code Sets up the GPIO pins for input and output respectively.
 pinMode(1, INPUT);
 pinMode(2, INPUT);
 pinMode(3, INPUT);
 pinMode(4, INPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);

 
}

void loop() {
  // 2 Bits of A are given to GPIO Pin 1 and 2
  // 2 Bits of B are given to GPIO Pin 3 and 4
  a1 = digitalRead(1);
  a2 = digitalRead(2);
  b1 = digitalRead(3);
  b2 = digitalRead(4);
  
  //The Calculation of the bits for adder is done in the following chunk of code
  s1 = a1^b1;
  c1 = a1&b1;
  s2 = a2^b2^c1;;
  c2 = ((a2^b2)&c1)|(a2&b2);
  
  //Output
  // 3 output values are given to GPIO pins 5,6 and 7
  digitalWrite(5, s1);
  digitalWrite(6, s2);
  digitalWrite(7, c2);

}
