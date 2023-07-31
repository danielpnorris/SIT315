// I did some research into temperature sensors and found
// https://www.tutorialspoint.com/arduino/arduino_temperature_sensor.htm
// which has guided some of my code (specifically analogRead(), which is
// mentioned in the task sheet and https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
// I also employed naming conventions found in the week 2 seminar code
// https://www.tinkercad.com/things/74bg4scXgEi-copy-of-sit315-seminar-2/editel?tenant=circuits


//Set up a variable to track the current temperature value, as well
// as the pin for the temperature sensor input and LED output
int currentTemperature;
const uint8_t TEMP_PIN = 3;
const uint8_t LED_PIN = 13;

void setup()
{
  //Register the LED_PIN as output and set data rate
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //SENSE -Read the temperature to get current value, print it to the 
  //Serial Monitor 
  //THINK - check if it is over 500
  //ACT - Turn the LED on or off
  
  //Wait 1 second so I can see the LED is responding
  
  currentTemperature = analogRead(TEMP_PIN);
  Serial.print(currentTemperature); 
  Serial.println("");
  if(currentTemperature > 500){
  	digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
  delay(1000); 
}
