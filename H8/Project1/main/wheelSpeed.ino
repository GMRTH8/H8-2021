
void wheelSpeed(byte encoderA, byte encoderB){
  
  //define pin encoder
  byte encA = encoderA;
  byte encB = encoderB;
  //define variable
  byte encAlast;
  //int duration;
  bool dir;
  
  volatile unsigned long now, lastTime, lastTime2;
  int counter;
  int currentPos, lastPos;
  long RPM;
  //Serial baudrate
  Serial.begin(115200);
  dir = true;
  //define pin
  pinMode(encB, INPUT);
  pinMode(encA, INPUT);
  attachInterrupt(encB, wheelPulse, CHANGE);
  
}

void wheelPulse(){
  byte encA, encB;
  //define variable
  byte encAlast;
  //int duration;
  bool dir;
  volatile unsigned long now, lastTime, lastTime2;
  int counter;
  int currentPos, lastPos;
  long RPM;
      int lastState = digitalRead(encA);
      if((encAlast == LOW)&&(lastState == HIGH)){
        int val = digitalRead(encB);
        if(val == LOW && dir){
          dir = false;
        }
        else if(val == HIGH && !dir){
          dir = true;
        }
      }
      encAlast = lastState;
    
      if(!dir) counter++;
      else counter--;
      //counter = duration;
      
      now = millis();
      if((now-lastTime) >= 100){
        currentPos = counter; // rotasi ke berapa
        RPM = (currentPos-lastPos)*0.7352941176470588;
        lastPos = currentPos;
        lastTime = now;
    }
    if((now-lastTime2)>=500){
      Serial.print("Currrent RPM:");
      Serial.println(RPM);
      Serial.print("pulse:");
      Serial.println(counter);
      //Serial.print("Currrent output:");
      //Serial.println(output);
      lastTime2 = now;
    }
  }
