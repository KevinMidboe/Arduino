int ledDigitalOne[] = {1, 2, 3, 4, 5, 6, 7}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON = HIGH;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = LOW;   //Define off as HIGH

//Predefined Colors

const boolean One[] = {OFF, ON, OFF, OFF, OFF, OFF, ON};
const boolean Two[] = {ON, OFF, ON, ON, OFF, ON, ON}; 
const boolean Three[] = {ON, ON, OFF, ON, OFF, ON, ON}; 
const boolean Four[] = {OFF, ON, OFF, ON, ON, OFF, ON}; 
const boolean Five[] = {ON, ON, OFF, ON, ON, ON, OFF}; 
const boolean Six[] = {ON, ON, ON, ON, ON, ON, OFF}; 
const boolean Seven[] = {OFF, ON, OFF, OFF, OFF, ON, ON}; 
const boolean Eight[] = {ON, ON, ON, ON, ON, ON, ON};
const boolean Nine[] = {ON, ON, OFF, ON, ON, ON, ON};
const boolean Zero[] = {ON, ON, ON, OFF, ON, ON, ON};

//An Array that stores the predefined colors (allows us to later randomly display a color)
const boolean* NUMBERS[] = {One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Zero};

void setup(){
  for(int i = 0; i < 9; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
}

void loop(){

/* Example - 1 Set a color
   Set the three LEDs to any predefined color
*/


   setNumber(ledDigitalOne, Eight);   //Set the color of LED one
   
   for (int i = 0; i < 10; i++)
   {
     setNumber(ledDigitalOne, Nine);
     delay (1000);
     setNumber(ledDigitalOne, Eight);
     delay (1000);
     setNumber(ledDigitalOne, Seven);
     delay (1000);
     setNumber(ledDigitalOne, Six);
     delay (1000);
     setNumber(ledDigitalOne, Five);
     delay (1000);
     setNumber(ledDigitalOne, Four);
     delay (1000);
     setNumber(ledDigitalOne, Three);
     delay (1000);
     setNumber(ledDigitalOne, Two);
     delay (1000);
     setNumber(ledDigitalOne, One);
     delay (1000);
     setNumber(ledDigitalOne, Zero);
     delay (1000);
   }

/* Example - 2 Go through Random Colors
  Set the LEDs to a random color
*/
   //randomNumber();

}

//void randomNumber(){
  //int rand = random(0, sizeof(NUMBER / 2);  //get a random number within the range of colors
  //setNumber(ledDigitalOne, NUMBER[rand]);  //Set the color of led one to a random color
  //delay(1000);
//}

/* Sets an led to any color
   led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin)
   color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)
*/

void setNumber(int* led, boolean* number)
{
 for(int i = 0; i < 7; i++)
 {
   digitalWrite(led[i], number[i]);
 }
}

/* A version of setColor that allows for using const boolean colors
*/

void setNumber(int* led, const boolean* number)
{
  boolean tempNumber[] = {number[0], number[1], number[2], number[3], number[4], number[5], number[6]};
  setNumber(led, tempNumber);
}
// the loop routine runs over and over again forever:

