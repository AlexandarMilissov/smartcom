#define led0 0
#define led1 1
#define led2 2
#define led3 3

#define button 4

int randomNumber;
void setup() {

  Serial.begin(9600);

  
  pinMode(button,INPUT);
  randomSeed(analogRead(button));
  randomNumber  = random(1,6);

  Serial.println(randomNumber);

  pinMode(led0,OUTPUT);
  digitalWrite(led0,LOW);
  pinMode(led1,OUTPUT);
  digitalWrite(led1,LOW);
  pinMode(led2,OUTPUT);
  digitalWrite(led2,LOW);
  pinMode(led3,OUTPUT);
  digitalWrite(led3,LOW);
  
  switch(randomNumber)
  {
    case 1:
      {
        digitalWrite(led0,HIGH);
        break;
      }
    case 2:
      {
        digitalWrite(led1,HIGH);
        break;
      }
    case 3:
      {
        digitalWrite(led0,HIGH);
        digitalWrite(led1,HIGH);
        break;
      }
    case 4:
      {
        digitalWrite(led2,HIGH);
        break;
      }
    case 5:
      {
        digitalWrite(led0,HIGH);
        digitalWrite(led2,HIGH);
        break;
      }
    case 6:
      {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        break;
      }
    default:
    {
        digitalWrite(led0,HIGH);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        break;
    }
  }
}

void loop() {

}
