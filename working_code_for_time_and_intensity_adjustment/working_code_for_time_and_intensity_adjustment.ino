
int motor_l = A1;
int motor_r = A3;
int pot_interval = A2;  // Potentiometer for time interval
int pot_intensity = A0; // New potentiometer for intensity

int delay_time, analog_in_interval, analog_in_intensity;

void setup() {
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  pinMode(pot_interval, INPUT);
  pinMode(pot_intensity, INPUT);
}

void loop() {
  // Read the potentiometer values
  analog_in_interval = analogRead(pot_interval);   // For time interval control
  analog_in_intensity = analogRead(pot_intensity); // For intensity control

  // Map the potentiometer values
  delay_time = map(analog_in_interval, 0, 1023, 1000, 6000);    // Interval between buzzes
  int pwmValue = map(analog_in_intensity, 0, 1023, 128, 255);     // Intensity of buzzes

  // Apply the PWM value for intensity control
  // analogWrite(motor_l, pwmValue);
  // analogWrite(motor_r, pwmValue);

  // Delay for time between buzzes
  // delay(delay_time);
  
  // Swap motor states to simulate alternating buzzes
  analogWrite(motor_l, 0);
  analogWrite(motor_r, pwmValue);
  delay(delay_time);
  
  analogWrite(motor_l, pwmValue);
  analogWrite(motor_r, 0);
  delay(delay_time);
}
