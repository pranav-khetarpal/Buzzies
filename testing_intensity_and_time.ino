int motor_l = A1;
int motor_r = A3;
int pot = A2; // pin for potentiometer

int delay_time, analog_in;

void setup() {
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  // Read the potentiometer value
  analog_in = analogRead(pot);

  // Map the potentiometer value to control both intensity and delay
  int pwmValue = map(analog_in, 0, 1023, 0, 255);  // For intensity
  delay_time = map(analog_in, 0, 1023, 1000, 6000); // For time between buzzes

  // Apply the PWM value to the motors for intensity control
  analogWrite(motor_l, pwmValue);
  analogWrite(motor_r, pwmValue);

  // Control the delay for time between buzzes
  delay(delay_time);
  
  // Swap motor states to simulate alternating buzzes
  analogWrite(motor_l, 0);
  analogWrite(motor_r, pwmValue);
  delay(delay_time);
  
  analogWrite(motor_l, pwmValue);
  analogWrite(motor_r, 0);
  delay(delay_time);
}
