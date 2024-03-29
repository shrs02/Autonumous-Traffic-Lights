// C++ code
//
int sen1=A0;
int sen2=A3;
int ledPin=9;
unsigned long t1=0;
unsigned long t2=0; 
float velocity;
float velocity_real;
float timeFirst;
float timeScnd;
float diff;
float speedConst=10;  
void setup()
{
  Serial.begin(9600);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  analogWrite(11,LOW);
  analogWrite(10,HIGH);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}
  void loop()
  { 
    int i = 0;
     while(i<10000)
     {
      
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
   
    
    if (digitalRead(sen1)==1)
    {
      timeFirst = millis();
      digitalWrite(ledPin, LOW);
    }
  
    if (digitalRead(sen2)==1)
  {
    timeScnd = millis();
    diff = timeScnd - timeFirst; 
    velocity = speedConst / diff;
    int velocity_real = (velocity*360)/100;     
  }
    digitalWrite(ledPin, HIGH);
    if (velocity_real>50)
    {
  Serial.print("\n ALEART HIGH SPEED ");
    }
    else if (velocity_real==0)
    {
   Serial.print("\n no car present");
    }
  digitalWrite(ledPin,LOW);
       delay(10);
         i=i+110;
       if(i>10000)
         break;
     }
   
    
  Serial.println();
   delay(500);
     
     
    int j = 0;
    
     while(j<5000)
     {
  digitalWrite(3, HIGH);
  delay(100); 
  digitalWrite(3, LOW);
 
    
    if (digitalRead(sen1)==1)
    {
      timeFirst = millis();
      digitalWrite(ledPin, LOW);
    }
    
  if (digitalRead(sen2)==1)
  {
    timeScnd = millis();
    diff = timeScnd - timeFirst; 
    velocity = speedConst / diff;
    int velocity_real = (velocity*360)/100;   
  }
    digitalWrite(ledPin, HIGH);
    if (velocity_real>50)
    {
  Serial.print("\n ALEART HIGH SPEED ");
    }
    else if (velocity_real==0)
    {
   Serial.print("\n no car present");
    }
  digitalWrite(ledPin,LOW);
       delay(10);
   j=j+110; 
    if (j>5000)
      break;
     }
    
   

   Serial.println();
    delay(500);
      
      
  int count = 0;
  while (count<13000)
 {
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
      
   
    if (digitalRead(sen1)==1)
    {
      timeFirst = millis();
      digitalWrite(ledPin, LOW);
    }
    
  if (digitalRead(sen2)==1)
  {
    timeScnd = millis();
    diff = timeScnd - timeFirst; 
    velocity = speedConst / diff;
    int velocity_real = (velocity*360)/100;     
  }
    digitalWrite(ledPin, HIGH);
    if (velocity_real>50)
    {
  Serial.print("\n ALEART HIGH SPEED ");
    }
    else if (velocity_real==0)
    {
   Serial.print("\n no car present");
    }
  digitalWrite(ledPin,LOW);
    delay(10);
      
  count = count+110;
  }
  Serial.println();
   delay(500);
    
}  