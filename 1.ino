const bool id[] = {0,0,1,0};
#define synPin 0
#define dataPin 1

void setup() {
  pinMode(synPin,INPUT);
  pinMode(dataPin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

bool receiver[] = {0,0,0,1};
bool data[] = {0};

void loop() {
  delay(1000*2);
  Send(0);
  Send(0);
  Send(1);
  Send(1);
}

void Send(bool state)
{
  pinMode(synPin, OUTPUT);
  pinMode(dataPin,OUTPUT);

  digitalWrite(dataPin,state);

  digitalWrite(synPin,HIGH);
  delay(1);
  digitalWrite(synPin,LOW);
  delay(2);
  
  pinMode(synPin, INPUT);
  pinMode(dataPin,INPUT);
}


void SendData(bool id[],bool data[])
{ 
  Send(id[0]);
  Send(id[1]);
  Send(id[2]);
  Send(id[3]);

  int len = sizeof(data)/sizeof(bool);

  for(int i = 0; i < len; i++)
  {
    Send(data[i]);
  }
}
