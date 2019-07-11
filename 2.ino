#define synPin 0
#define dataPin 1

const bool id[] = {0,0,0,1};
//const bool id[] = {0,0,1,1};
int isMe = 0;
bool isReceiving = false;
bool sentID[4];
int bits = 0;
bool receivedData = 0;
unsigned long lastTime = 0;

//Functions for sending data
void SendID(bool id0,bool id1,bool id2,bool id3)
{
  Send(id0);
  Send(id1);
  Send(id2);
  Send(id3);
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

//Main functions
void setup() {
  
  pinMode(synPin,INPUT);
  pinMode(dataPin,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  lastTime = millis();
}
void loop() {

  //sending data
  if(!isReceiving)
  {
    delay(1000*2);
    SendID(0,0,1,1);
    Send(1);
    Send(1);
  }



  //receive data
  unsigned long nowT = millis();
  if(nowT - lastTime > 50  && isReceiving == true )
  {
    isReceiving = false;
    bits = 0;
    isMe = 0;
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  
  if(digitalRead(synPin))
  {
    receivedData = digitalRead(dataPin);
    if(bits<4)
    {
      sentID[bits] = receivedData;
    }
    isReceiving = true;
    lastTime = millis();
    bits++;
    delay(1);
  }
  if(isReceiving == true)
  {
    if(bits==4)
    {
      if(sentID[0]==id[0]
      &&sentID[1]==id[1]
      &&sentID[2]==id[2]
      &&sentID[3]==id[3])
      {
        isMe = 1;
      }
      else
      {
        isMe = 0;
      }
    }
    if(isMe)
    {
      
      if(bits == 5)
      {
        digitalWrite(2,receivedData);
      }
      if(bits == 6)
      {
        digitalWrite(3,receivedData);
      }
    }
  }
}
