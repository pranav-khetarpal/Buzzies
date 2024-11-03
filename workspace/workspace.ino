
int motor_l = A1;
int motor_r = A3;
int pot_interval = A2;  // Potentiometer for time interval
int pot_intensity = A0; // Potentiometer for intensity

int delay_time, analog_in_interval, analog_in_intensity;
int last_time;

void setup() {
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  pinMode(pot_interval, INPUT);
  pinMode(pot_intensity, INPUT);
  last_time = millis();
}

void loop() {
  // Read potentiometer values
  analog_in_interval = analogRead(pot_interval);   // Interval control
  analog_in_intensity = analogRead(pot_intensity); // Intensity control

  // Map values to control interval and intensity
  delay_time = map(analog_in_interval, 0, 1023, 1000, 6000); // Interval (time)
  int pwmValue = map(analog_in_intensity, 0, 1023, 128, 255); // Intensity (PWM)
  
  // Alternate buzzing with intensity and interval controls
  analogWrite(motor_l, 0);
  analogWrite(motor_r, pwmValue);
  delay(delay_time);
  
  analogWrite(motor_l, pwmValue);
  analogWrite(motor_r, 0);
  delay(delay_time);
}
