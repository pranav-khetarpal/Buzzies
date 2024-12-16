
int motor_l = 2;
int motor_r = 3;

int delay_time = 2000;
int motor_state = 0;
int last_time;

void setup()
{
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  last_time = millis();
}

void loop()
{
  digitalWrite(motor_l, LOW);
  digitalWrite(motor_r, HIGH);
  delay(delay_time);
  digitalWrite(motor_l, HIGH);
  digitalWrite(motor_r, LOW);
  delay(delay_time);
}
