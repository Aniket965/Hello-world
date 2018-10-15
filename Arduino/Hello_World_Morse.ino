void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // blinks pin13 LED "Hello World" in morse, repeatedly

  //H
  dot();
  character_gap();
  dot();
  character_gap();
  dot();
  character_gap();
  dot();

  letter_gap();
 
  //E
  dot();

  letter_gap();

  //L
  dot();
  character_gap();
  dash();
  character_gap();
  dot();
  character_gap();
  dot();
  
  letter_gap();
  
  //L
  dot();
  character_gap();
  dash();
  character_gap();
  dot();
  character_gap();
  dot();

  letter_gap();

  //O
  dash();
  character_gap();
  dash();
  character_gap();
  dash();

  word_gap();
  
  //W
  dot();
  character_gap();
  dash();
  character_gap();
  dash();

  letter_gap();

  //O
  dash();
  character_gap();
  dash();
  character_gap();
  dash();

  letter_gap();

  //R
  dot();
  character_gap();
  dash();
  character_gap();
  dot();

  letter_gap();

  //L
  dot();
  character_gap();
  dash();
  character_gap();
  dot();
  character_gap();
  dot();

  letter_gap();

  //D
  dash();
  character_gap();
  dot();
  character_gap();
  dot();

  word_gap();
}

//dot duration: 500ms
//dash duration: 1500ms
//gap duration within a character: 500ms
//gap between letters: 1500ms
//gap between words: 3500ms

void dot()  {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void dash() {
  digitalWrite(13, HIGH);
  delay(1500);
  digitalWrite(13, LOW);
}

void character_gap()  {
  delay(500);
}

void letter_gap() {
  delay(1500);
}

void word_gap() {
  delay(3500);
}



