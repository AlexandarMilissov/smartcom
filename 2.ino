#define syn 0
#define data 1
void setup() {
}
int received = 0;
void loop() {
  if(digitalRead(syn))
  {
    received = digitalRead(data);
    delay(1);
  }
  digitalWrite(3,received);
}
