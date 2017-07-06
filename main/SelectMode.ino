unsigned char SelectMode() {
  unsigned char Mode;
  Serial.println("Selecting the mode!!");
  while (n == 1) {//When the code doesn't to relate with some mode
    n = 0;
    while (n == 0) {
      if (irrecv.decode(&results)) {
        if (millis() - last > 250) {
          RemoteControl(&results);
          last = millis();
          n = 1;
        }
        irrecv.resume();
      }
    }
    //IR Remote Mode
    if (code == modeIR) {
      Mode = 1;
      n = 0;
      Serial.println("IRremote mode selected!");
    }
    //Ultrasonic Mode
    if (code == modeUltra) {
      Mode = 2;
      n = 0;
      Serial.println("Ultrasonic mode selected!");
    }
  }
  return Mode;
}

void IRremoteMode() {
  unsigned char nBack = 0;
  while (nBack == 0) {
    while (n == 0) {
      if (irrecv.decode(&results)) {
        if (millis() - last > 250) {
          RemoteControl(&results);
          last = millis();
          n = 1;
        }
        irrecv.resume();
      }
    }
    if (code == forward) {
      Robot.GoingForward(speedMotor);
      //GoingForward(speedMotor);
      n = 0;
    }
    if (code == backward) {
      Robot.GoingBackward(speedMotor);
      //GoingBackward(speedMotor);
      n = 0;
    }
    if (code == left) {
      Robot.TurnLeft(speedMotor);
      //TurnLeft(speedMotor);
      n = 0;
    }
    if (code == right) {
      Robot.TurnRight(speedMotor);
      //TurnRight(speedMotor);
      n = 0;
    }
    if (code == brake) {
      Robot.Brake();
      //Brake();
      n = 0;
    }
    if (code == back) {
      nBack = 1;
    }
    n = 0;
  }
}

void UltrasonicMode(unsigned char mDistance) {
  long distance;
  while (code != back) {
    distance = ReadDistance();
    Robot.GoingForward(speedMotor);
    Serial.println("Going Forward!");
    
    while (distance > mDistance && code != back) {
      distance = ReadDistance();
      
      if (irrecv.decode(&results)) {
        if (millis() - last > 250) {
          RemoteControl(&results);
          last = millis();
          n = 1;
        }
        irrecv.resume();
      }
    }
    Serial.print("Distancia: ");
    Serial.println(distance);
    Serial.println("Brake!");
    Robot.Brake();
    Look(mDistance);
  }
}
