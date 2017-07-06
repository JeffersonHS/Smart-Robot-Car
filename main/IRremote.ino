//REMOTE CONTROL 1
/* On/Off - FFA25D
   Menu - FFE21D
   Test - FF22DD
   +(Plus) - FF02FD
   Back - FFC23D
   Previous - FFE01F
   Play - FFA857
   Next - FF906F
   0(Zero) - FF6897
   -(Minus) - FF9867
   C - FFB04F
   1(One) - FF30CF
   2(Two) - FF18E7
   3(Three) - FF7A85
   4(Four) - FF10EF
   5(Five) - FF38C7
   6(Six) - FF5AA5
   7(Seven) - FF42BD
   8(Eight) - FF4AB5
   9(Nine) - FF52AD
*/

//REMOTE CONTROL 2
/* Forward - FF629D
   Left - FF22DD
   OK - FF02FD
   Rigth - FFC23D
   Backward - A3C8EDDB
   1(One) - FF6897
   2(Two) - FF9867
   3(Three) - FFB04F
   4(Four) - FF30CF
   5(Five) - FF18E7
   6(Six) - FF7A85
   7(Seven) - FF10EF
   8(Eight) - FF38C7
   9(Nine) - FF5AA5
   0(Zero) - FF4AB5
   (*) - FF42BD
   (#) - FF52AD
*/

void RemoteControl(decode_results *results) {
  if (results->decode_type == UNKNOWN) {
    Serial.println("Could not decode the message!");
  }
  else {
    if (results->decode_type == NEC) {
      Serial.println("Decoded NEC: ");
    }
  }
  Serial.print(results->value, HEX);
  code = results->value;
  Serial.println("");
}
