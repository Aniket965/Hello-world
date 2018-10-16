const int trigger = 8;
const int eco = 7;
int led = 13;

long duracao;
int dist;

void setup() {
 pinMode(trigger, OUTPUT); 
 pinMode(eco, INPUT); 
 Serial.begin(9600); 
 pinMode(led, OUTPUT);
}

void loop() {
 digitalWrite(trigger, LOW);
 delayMicroseconds(5);

 digitalWrite(trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger, LOW);

 duracao = pulseIn(eco, HIGH);

 dist= duracao*0.034/2;

 Serial.print("Distancia em cm: ");
 Serial.println(dist);

  if (dist > 20){
  digitalWrite(led, HIGH); 
  }             
  else{
   digitalWrite(led, LOW); 
  }             
                
 delay(100);
}
