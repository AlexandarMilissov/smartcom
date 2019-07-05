#define synPin 0
#define dataPin 1

const bool id[] = {0,0,0,1};
int isMe = 0;
bool isReceiving = false;
bool sentID[4];
int bits = 0;
bool receivedData = 0;
int timeSinceLast = 0;

void setup() {
  pinMode(synPin,INPUT);
  pinMode(dataPin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}
void loop() {
  if(digitalRead(synPin))
  {
    receivedData = digitalRead(dataPin);
    sentID[bits] = receivedData;
    isReceiving = true;
    bits++;
    delay(1);
  }
    if(sentID[0]==id[0]
    &&sentID[1]==id[1]
    &&sentID[2]==id[2]
    &&sentID[3]==id[3])
    {
      digitalWrite(3,HIGH);
    }
    else
    {
      if(isReceiving && bits>=4)
      {
        digitalWrite(2,HIGH);
      }
    }
}
