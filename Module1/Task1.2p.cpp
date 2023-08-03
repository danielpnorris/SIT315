// I tried a couple of things with the temperature sensor that I
// used for the first task but noticed a few issues. I had used
// the wrong input type on task 1 (digital instead of analog), which
// tricked me in to thinking it was generating random values as a 
// demonstration, but when I swapped to analog it only returned 0, no
// matter what changes I was making.
// As such, I have instead gone with a PIR sensor demonstration to 
// show interrupts in action, as that sensor is working correctly


const uint8_t PIR_PIN = 2;
const uint8_t LED_PIN = 13;

void setup()
{
  //Register the LED_PIN as output and set data rate
  pinMode(LED_PIN, OUTPUT);
  
  //Attach interrupt and set senseMotion as the function to run
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), senseMotion, CHANGE);
  Serial.begin(9600);
}

void senseMotion()
{
  //I have creatd this function to trigger when PIR_PIN value changes
  // It checks if it is 1 or 0, changes the LED and prints the appropriate output
  int motionValue = digitalRead(PIR_PIN);
  Serial.print(motionValue);
  Serial.println("");
  if(motionValue == 1)
  {
    Serial.print("Motion Detected");
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    Serial.print("Motion Ended");
    digitalWrite(LED_PIN, LOW);
  }
  Serial.println("");
}
  

void loop()
{
 // No need for loop as using interrupts
}

