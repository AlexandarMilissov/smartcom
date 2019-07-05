#define syn 0
#define data 1
int counter = 0;

void setup() {
}

void loop() {
  delay(1000 * 5);
  Send(HIGH);
  delay(1000 * 5);
  Send(LOW);
}

void Send(bool state)
{
  pinMode(syn, OUTPUT);
  pinMode(data,OUTPUT);

  digitalWrite(data,state);

  digitalWrite(syn,HIGH);
  delay(1);
  digitalWrite(syn,LOW);

  
  pinMode(syn, INPUT);
  pinMode(data,INPUT);
}
