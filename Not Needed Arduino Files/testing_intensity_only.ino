int motor_l = A1;
int motor_r = A3;
int pot = A2; // pin 2

int delay_time, analog_in;

void setup()
{
  pinMode(motor_l, OUTPUT);
  pinMode(motor_r, OUTPUT);
  pinMode(pot, INPUT);
}

void loop()
{
  // Read the potentiometer value
  analog_in = analogRead(pot);

  // Map the potentiometer value to a PWM range (0-255)
  int pwmValue = map(analog_in, 0, 1023, 0, 255);

  // Apply the PWM value to control the buzzing intensity of both motors
  analogWrite(motor_l, pwmValue);
  analogWrite(motor_r, pwmValue);

  // You can keep a short delay to stabilize the loop
  delay(100); // Adjust this value if needed
}
