int motor_l = 2;
int motor_r = 3;
int pot = A2;

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

void loop()
{
  analog_in = analogRead(pot);
  delay_time = map(analog_in, 0, 1023, 1000, 6000);
  digitalWrite(motor_l, LOW);
  digitalWrite(motor_r, HIGH);
  delay(delay_time);
  digitalWrite(motor_l, HIGH);
  digitalWrite(motor_r, LOW);
  delay(delay_time);
}
