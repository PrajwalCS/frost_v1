int light;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(A2,INPUT);
  Serial.begin(9600);

}

void loop() {
  light = analogRead(A2);
    Serial.println(light);
 /* if(digitalRead(A2)==LOW)
  {
    Serial.write("LOW  ");
    light = analogRead(A2);
    Serial.println(light);
    digitalWrite(13,HIGH);
    delay(2000);
  }
  else
  {
    Serial.write("HIGH  ");
    light = analogRead(A2);
    Serial.println(light);
    digitalWrite(13,LOW);
    delay(2000);
  }
  */

}
