

int potPin = 2;   //sets potentiometer pin at analog 2
int potVal = 0;   //holds the value read in from the potentiometer
int led1 = 11;    //pin number 11 has led1
int led2 = 10;    //pin number 10 has led2
int led3 = 9;     //pin number 9 has led3
int led4 = 6;     //pin number 6 has led4
int led5 = 5;     //pin number 5 has led5
int led6 = 3;     //pin number 5 has led5
byte full= 255;   //the highest brightness is 255
byte low = 155;   //the low brightness is 155
byte dim = 35;    //the dim is set to 55
byte off = LOW;   //and off has no voltage

void setup(){
  Serial.begin(9600);
  pinMode(potPin, INPUT); //potentiometer is an input
  pinMode(led1, OUTPUT);  //led1 is an output
  pinMode(led2, OUTPUT);  //led2 is an output  
  pinMode(led3, OUTPUT);  //led3 is an output
  pinMode(led4, OUTPUT);  //led4 is an outut
  pinMode(led5, OUTPUT);  //led5 is an outut
}//end setup()

void loop(){
  //read in analog value from potentiometer and stores into potVal
  potVal = analogRead(potPin);
  //prints the value in the serial monitor
  Serial.print(potVal);
  //displays the brightness of each led based on the position of the potentiometer
  if(potVal>=0&&potVal<205)
  {
    digitalWrite(led1,full);
    digitalWrite(led2,low);
    digitalWrite(led3,dim);
    digitalWrite(led4,off);
    digitalWrite(led5,off);
  }
  if(potVal>=205&&potVal<410)
  {
    digitalWrite(led1,low);
    digitalWrite(led2,full);
    digitalWrite(led3,low);
    digitalWrite(led4,dim);
    digitalWrite(led5,off); 
  }
  if(potVal>=410&&potVal<615)
  {
    digitalWrite(led1,dim);
    digitalWrite(led2,low);
    digitalWrite(led3,full);
    digitalWrite(led4,low);
    digitalWrite(led5,dim);
  }
  if(potVal>=615&&potVal<820)
  {
    digitalWrite(led1,off);
    digitalWrite(led2,dim);
    digitalWrite(led3,low);
    digitalWrite(led4,full);
    digitalWrite(led5,low);
  }
  if(potVal>=820&&potVal<1023)
  {
    digitalWrite(led1,off);
    digitalWrite(led2,off);
    digitalWrite(led3,dim);
    digitalWrite(led4,low);
    digitalWrite(led5,full);
  }
  //waits 100 ms
  delay(100);
}//end loop

