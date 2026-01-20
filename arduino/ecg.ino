Kel_ier
kel_ier
Invisible

This is the start of the #code channel. 
Kel_ier — 8/18/23, 10:20 PM
Image
long instance1=0, timer;
long timer1;
bool st = 0;
char incval = '0';

Expand
2 KB
rayhan — 8/18/23, 10:47 PM
Attachment file type: unknown
ecgN.aia
690.31 KB
rayhan — 8/19/23, 12:00 AM
Attachment file type: unknown
ecgN_1.aia
691.42 KB
Kel_ier — 8/20/23, 11:31 PM
Attachment file type: unknown
ecgN_postbt.aia
693.67 KB
long instance1=0, timer;
long timer1;
bool st = 0;
char incval = '0';


double hrv =0, hr = 72, interval = 0, t1 =1;;

int value = 0, count = 0, c = 0;  

bool flag = 0;

#define shutdown_pin 10 

#define threshold 100 // to identify R peak

#define timer_value 10000 // 10 seconds timer to calculate hr


void setup() {

  Serial.begin(9600);

  pinMode(8, INPUT); // Setup for leads off detection LO +

  pinMode(9, INPUT); // Setup for leads off detection LO -

}

void loop() { 

if(Serial.available())
{
    incval = Serial.read();
    if(incval == '1')
    {
      while(1){
        Serial.println(hr);
        delay(325);
      }
      delay(5000);
      Serial.println(hr);
      delay(99999999999999999999999999999);
      

    timer1 = millis();
    st = 1;
    }
}
  /*if(millis()-timer1>10000)
  {
    
    t1 = c*6;
    Serial.print(t1);
    delay(1000);
    exit(0);
  }*/
  



  if((digitalRead(8) == 1)||(digitalRead(9) == 1)){

    Serial.println("leads off!");

    digitalWrite(shutdown_pin, LOW); //standby mode

    instance1 = micros();

    timer = millis();

  }

  else {

    digitalWrite(shutdown_pin, HIGH); //normal mode

    value = analogRead(A0);

    value = map(value, 250, 400, 0, 100); //to flatten the ecg values a bit

    if((value > threshold) && (!flag)) {

      count++;  

      Serial.println("in");

      flag = 1;

      interval = micros() - instance1; //RR interval

      instance1 = micros();
      if(st==1){
      c++;}

    }

    else if((value < threshold)) {

      flag = 0;
... (37 lines left)
Collapse
2 KB
Kel_ier — 8/21/23, 9:47 PM
Attachment file type: unknown
ecgN_1.aia
693.68 KB
﻿
long instance1=0, timer;
long timer1;
bool st = 0;
char incval = '0';


double hrv =0, hr = 72, interval = 0, t1 =1;;

int value = 0, count = 0, c = 0;  

bool flag = 0;

#define shutdown_pin 10 

#define threshold 100 // to identify R peak

#define timer_value 10000 // 10 seconds timer to calculate hr


void setup() {

  Serial.begin(9600);

  pinMode(8, INPUT); // Setup for leads off detection LO +

  pinMode(9, INPUT); // Setup for leads off detection LO -

}

void loop() { 

if(Serial.available())
{
    incval = Serial.read();
    if(incval == '1')
    {
      while(1){
        Serial.println(hr);
        delay(325);
      }
      delay(5000);
      Serial.println(hr);
      delay(99999999999999999999999999999);
      

    timer1 = millis();
    st = 1;
    }
}
  /*if(millis()-timer1>10000)
  {
    
    t1 = c*6;
    Serial.print(t1);
    delay(1000);
    exit(0);
  }*/
  



  if((digitalRead(8) == 1)||(digitalRead(9) == 1)){

    Serial.println("leads off!");

    digitalWrite(shutdown_pin, LOW); //standby mode

    instance1 = micros();

    timer = millis();

  }

  else {

    digitalWrite(shutdown_pin, HIGH); //normal mode

    value = analogRead(A0);

    value = map(value, 250, 400, 0, 100); //to flatten the ecg values a bit

    if((value > threshold) && (!flag)) {

      count++;  

      Serial.println("in");

      flag = 1;

      interval = micros() - instance1; //RR interval

      instance1 = micros();
      if(st==1){
      c++;}

    }

    else if((value < threshold)) {

      flag = 0;

    }

    if ((millis() - timer) > 10000) {

      hr = count*6;

      timer = millis();

      count = 0; 

      }
    
    
      hrv = hr/60 - interval/1000000;

      Serial.print(hr);

      Serial.print(",");

      Serial.print(hrv);

      Serial.print(",");

      Serial.println(value);
    
    

    delay(1);
    

  }

 
}

Final.txt
2 KB
