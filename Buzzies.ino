int motor_l = A1;
int motor_r = A3;
int pot = A2; // pin 2

int delay_time, analog_in;
int motor_state = 0;
int last_time;

void setup()
{
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  pinMode(pot, INPUT);
  last_time = millis();
}

int highOrLow = 0;

void loop()
{
  // analog_in = analogRead(pot);
  // delay_time = map(analog_in, 0, 1023, 1000, 6000);
  // digitalWrite(motor_l, LOW);
  // digitalWrite(motor_r, HIGH);
  // delay(delay_time);
  // digitalWrite(motor_l, HIGH);
  // digitalWrite(motor_r, LOW);
  // delay(delay_time);

  analog_in = analogRead(pot);
  delay_time = map(analog_in, 0, 1023, 1000, 6000);

  int analogValue = 0;

  if (highOrLow % 2 == 0) {
    highOrLow = 1;
    analogValue = 128;
  } else {
    highOrLow = 0;
    analogValue = 255;
  }

  analogWrite(motor_l, 0);
  analogWrite(motor_r, analogValue);
  delay(delay_time);
  analogWrite(motor_l, analogValue);
  analogWrite(motor_r, 0);
  delay(delay_time);

  
//  if (millis() - last_time > delay_time) {
//    last_time = millis();
//    if (motor_state == 0) {
//      digitalWrite(motor_l, HIGH);
//      digitalWrite(motor_r, LOW);
//      motor_state = 1;
//    }
//    else {
//      digitalWrite(motor_r, HIGH);
//      digitalWrite(motor_l, LOW);
//      motor_state = 0;
//    }
//  }
}