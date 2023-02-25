int ldr = A0;
int buzzer =A3;
void setup()
 {
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(buzzer,OUTPUT);
  
 }

void loop()
 {
  int value = digitalRead(ldr);

 Serial.write(analogRead(ldr));
 Serial.println("");
 Serial.println(" Value = ");
 Serial.println(value);

if(value ==0)
{
  digitalWrite(buzzer,LOW);

}
else{
  digitalWrite(buzzer,HIGH);
}
delay(50);
 }
