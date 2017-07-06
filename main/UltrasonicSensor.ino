long ReadDistance() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration / 58.2;

  if (distance >= maxRange || distance <= minRange) {
    Serial.println("OUT OF RANGE");
  }
  else {
    //Serial.print("Distancia: ");
    //Serial.println(distance);
  }
  return distance;
}

void Look(unsigned char mDistance) {
  long distanceRight, distanceLeft;

  servo.write(0);
  delay(500);
  distanceRight = ReadDistance();

  servo.write(180);
  delay(500);
  distanceLeft = ReadDistance();
  servo.write(88);

  if (distanceLeft > distanceRight) {
    Robot.TurnLeft(speedMotor);
    Serial.println("Turn Left!");
    Serial.print("Distancia: ");
    Serial.println(distanceLeft);
  }
  if (distanceRight > distanceLeft) {
    Robot.TurnRight(speedMotor);
    Serial.println("Turn Right!");
    Serial.print("Distancia: ");
    Serial.println(distanceRight);
  }
  if (distanceLeft < mDistance && distanceRight < mDistance) {
    //Robot.TurnAround();
    Serial.println("Turn Around!");
  }
}

