/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-05 .: 8 More LEDs :. (74HC595 Shift Register)   |
 *     ---------------------------------------------------------
 * 
 * We have already controlled 8 LEDs however this does it in a slightly
 * different manner. Rather than using 8 pins we will use just three
 * and an additional chip.
 *
 *
 */


//Pin Definitions
//Pin Definitions
//The 74HC595 uses a serial communication 
//link which has three pins
int data = 11; 
int clock = 13;
int latch = 12;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;


int ledDigitalOne[] = {10, 9, 8, 7, 6, 5, 4}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin
//Predefined Colors

const boolean One[] = {ON, OFF, OFF, OFF, OFF, OFF, ON};
const boolean Two[] = {OFF, ON, ON, ON, OFF, ON, ON}; 
const boolean Three[] = {ON, ON, OFF, ON, OFF, ON, ON}; 
const boolean Four[] = {ON, OFF, OFF, ON, ON, OFF, ON}; 
const boolean Five[] = {ON, ON, OFF, ON, ON, ON, OFF}; 
const boolean Six[] = {ON, ON, ON, ON, ON, ON, OFF}; 
const boolean Seven[] = {ON, OFF, OFF, OFF, OFF, ON, ON}; 
const boolean Eight[] = {ON, ON, ON, ON, ON, ON, ON};
const boolean Nine[] = {ON, ON, OFF, ON, ON, ON, ON};
const boolean Zero[] = {ON, ON, ON, OFF, ON, ON, ON};


//An Array that stores the predefined colors (allows us to later randomly display a color)
const boolean* NUMBERS[] = {One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Zero};


void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);  
  pinMode(latch, OUTPUT);  
  
  
  
  for(int i = 0; i < 9; i++)
  {
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
  
  
}

void loop()
{
  int delayTime = 500;
  for (int i = 0; i < 5; i++)
  {
    changeLED(0,ON);  // - 9
    changeLED(1,ON);
    changeLED(3,ON);
    changeLED(4,ON);
    changeLED(5,ON);
    changeLED(6,ON);
    setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
    
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
    changeLED(6,OFF);
    
   changeLED(0,ON);  // - 8
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(3,ON);
   changeLED(4,ON);
   changeLED(5,ON);
    changeLED(6,ON);
    setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
    
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
    changeLED(6,OFF);
    
   changeLED(3,ON);  // - 7
   changeLED(5,ON);
   changeLED(6,ON); 
   setNumber(ledDigitalOne, Nine);
   delay(1000);
   setNumber(ledDigitalOne, Eight);
   delay(1000);
   setNumber(ledDigitalOne, Seven);
   delay(1000);
   setNumber(ledDigitalOne, Six);
   delay(1000);
   setNumber(ledDigitalOne, Five);
   delay(1000);
   setNumber(ledDigitalOne, Four);
   delay(1000);
   setNumber(ledDigitalOne, Three);
   delay(1000);
   setNumber(ledDigitalOne, Two);
   delay(1000);
   setNumber(ledDigitalOne, One);
   delay(1000);
   setNumber(ledDigitalOne, Zero);
   delay(1000);
   
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(0,ON);  // - 6
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(3,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
   
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(0,ON);  // - 5
   changeLED(1,ON);
   changeLED(3,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);

   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(0,ON);  // - 4
   changeLED(3,ON);
   changeLED(4,ON);
   changeLED(6,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
   
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(0,ON);  // - 3
   changeLED(1,ON);
   changeLED(3,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
 
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(1,ON); // - 2
   changeLED(2,ON);
   changeLED(0,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
   
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(3,ON); // - 1
   changeLED(6,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);
  
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(3,ON); // - 0
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   setNumber(ledDigitalOne, Nine);
    delay(1000);
    setNumber(ledDigitalOne, Eight);
    delay(1000);
    setNumber(ledDigitalOne, Seven);
    delay(1000);
    setNumber(ledDigitalOne, Six);
    delay(1000);
    setNumber(ledDigitalOne, Five);
    delay(1000);
    setNumber(ledDigitalOne, Four);
    delay(1000);
    setNumber(ledDigitalOne, Three);
    delay(1000);
    setNumber(ledDigitalOne, Two);
    delay(1000);
    setNumber(ledDigitalOne, One);
    delay(1000);
    setNumber(ledDigitalOne, Zero);
    delay(1000);

   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   }  
}



/*
 * updateLEDs() - sends the LED states set in ledStates to the 74HC595
 * sequence
 */
void updateLEDs(int value){
  digitalWrite(latch, LOW);     //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH);   //Pulls the latch high displaying the data
}

/*
 * updateLEDsLong() - sends the LED states set in ledStates to the 74HC595
 * sequence. Same as updateLEDs except the shifting out is done in software
 * so you can see what is happening.
 */ 
void updateLEDsLong(int value){
  digitalWrite(latch, LOW);    //Pulls the chips latch low
  for(int i = 0; i < 8; i++){  //Will repeat 8 times (once for each bit)
  int bit = value & B10000000; //We use a "bitmask" to select only the eighth 
                               //bit in our number (the one we are addressing this time through
  value = value << 1;          //we move our number up one bit value so next time bit 7 will be
                               //bit 8 and we will do our math on it
  if(bit == 128){digitalWrite(data, HIGH);} //if bit 8 is set then set our data pin high
  else{digitalWrite(data, LOW);}            //if bit 8 is unset then set the data pin low
  digitalWrite(clock, HIGH);                //the next three lines pulse the clock pin
  delay(1);
  digitalWrite(clock, LOW);
  }
  digitalWrite(latch, HIGH);  //pulls the latch high shifting our data into being displayed
}


//These are used in the bitwise math that we use to change individual LEDs
//For more details http://en.wikipedia.org/wiki/Bitwise_operation
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};
/*
 * changeLED(int led, int state) - changes an individual LED 
 * LEDs are 0 to 7 and state is either 0 - OFF or 1 - ON
 */
 void changeLED(int led, int state){
   ledState = ledState & masks[led];  //clears ledState of the bit we are addressing
   if(state == ON){ledState = ledState | bits[led];} //if the bit is on we will add it to ledState
   updateLEDs(ledState);              //send the new LED state to the shift register
 }
 
 
 
 
 
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
