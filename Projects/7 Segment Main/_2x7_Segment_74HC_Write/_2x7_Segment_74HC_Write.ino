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
int data = 2; 
int clock = 3;
int latch = 4;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;
                        




int ledDigitalOne[] = {13, 12, 11, 10, 9, 8, 7, 6}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON1 = HIGH;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF1 = LOW;   //Define off as HIGH

//Predefined Colors

const boolean One[] = {ON1, OFF1, OFF1, OFF1, OFF1, OFF1, ON1};
const boolean Two[] = {OFF1, ON1, ON1, ON1, OFF1, ON1, ON1}; 
const boolean Three[] = {ON1, ON1, OFF1, ON1, OFF1, ON1, ON1}; 
const boolean Four[] = {ON1, OFF1, OFF1, ON1, ON1, OFF1, ON1}; 
const boolean Five[] = {ON1, ON1, OFF1, ON1, ON1, ON1, OFF1}; 
const boolean Six[] = {ON1, ON1, ON1, ON1, ON1, ON1, OFF1}; 
const boolean Seven[] = {ON1, OFF1, OFF1, OFF1, OFF1, ON1, ON1}; 
const boolean Eight[] = {ON1, ON1, ON1, ON1, ON1, ON1, ON1};
const boolean Nine[] = {ON1, ON1, OFF1, ON1, ON1, ON1, ON1};
const boolean Zero[] = {ON1, ON1, ON1, OFF1, ON1, ON1, ON1};

const boolean A[] = {OFF1, ON1, OFF1, OFF1, OFF1, ON1, OFF1};
const boolean B[] = {ON1, ON1, ON1, OFF1, ON1, ON1, ON1};
const boolean C[] = {ON1, ON1, OFF1, OFF1, OFF1, OFF1, ON1};
const boolean D[] = {ON1, ON1, OFF1, ON1, OFF1, OFF1, OFF1};
const boolean E[] = {ON1, ON1, ON1, OFF1, OFF1, OFF1, ON1};
const boolean F[] = {OFF1, ON1, OFF1, OFF1, OFF1, OFF1, OFF1};
const boolean G[] = {ON1, ON1, OFF1, OFF1, ON1, ON1, ON1};
const boolean H[] = {OFF1, ON1, ON1, OFF1, ON1, ON1, OFF1};
const boolean I[] = {OFF1, OFF1, OFF1, ON1, OFF1, OFF1, OFF1};
const boolean J[] = {ON1, ON1, OFF1, OFF1, OFF1, ON1, ON1};
const boolean K[] = {OFF1, ON1, ON1, ON1, OFF1, OFF1, ON1};
const boolean L[] = {ON1, ON1, OFF1, OFF1, OFF1, OFF1, ON1};
const boolean M[] = {OFF1, ON1, OFF1, OFF1, OFF1, ON1, OFF1};
const boolean N[] = {OFF1, ON1, OFF1, ON1, OFF1, ON1, ON1};
const boolean O[] = {ON1, ON1, OFF1, OFF1, OFF1, ON1, ON1};
const boolean P[] = {OFF1, ON1, OFF1, OFF1, OFF1, OFF1, OFF1};
const boolean Q[] = {ON1, ON1, OFF1, OFF1, OFF1, ON1, OFF1};
const boolean R[] = {OFF1, ON1, OFF1, ON1, OFF1, OFF1, ON1};
const boolean S[] = {ON1, OFF1, OFF1, OFF1, OFF1, ON1, ON1};
const boolean T[] = {OFF1, OFF1, OFF1, ON1, OFF1, OFF1, OFF1};
const boolean U[] = {ON1, ON1, OFF1, OFF1, OFF1, ON1, ON1};
const boolean V[] = {OFF1, OFF1, OFF1, ON1, OFF1, OFF1, OFF1};
const boolean W[] = {ON1, ON1, OFF1, ON1, OFF1, ON1, ON1};
const boolean X[] = {OFF1, ON1, OFF1, OFF1, OFF1, ON1, OFF1};
const boolean Y[] = {OFF1, OFF1, OFF1, ON1, OFF1, OFF1, OFF1};
const boolean Z[] = {ON1, ON1, ON1, OFF1, OFF1, OFF1, ON1};
const boolean EXCLA[] = {OFF1, ON1, OFF1, OFF1, OFF1, OFF1, OFF1, ON1};


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

/*
 * loop() - this function will start after setup finishes and then repeat
 * we set which LEDs we want on then call a routine which sends the states to the 74HC595
 */
void loop()                     // run over and over again
{
  int delayTime = 500;
  for (int i = 0; i < 31; i++)
  {
    changeLED(0,ON);  // - A
    changeLED(1,ON);
    changeLED(2,ON);
    changeLED(4,ON);
    changeLED(5,ON);
    changeLED(6,ON);
    
    setNumber(ledDigitalOne, A);
    
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
    changeLED(6,OFF);
    
   changeLED(0,ON);  // - B
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   changeLED(6,ON);
    
   setNumber(ledDigitalOne, B);
    
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
    
   changeLED(1,ON);  // - C
   changeLED(2,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, C);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - D
   changeLED(2,ON);
   changeLED(3,ON);
   
   setNumber(ledDigitalOne, D);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);

   changeLED(0,ON);  // -- E
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, E);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- F
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, F);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // -- G
   changeLED(2,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, G);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- H
   changeLED(1,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, H);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(3,ON);  // - I
   
   setNumber(ledDigitalOne, I);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(5,ON);  // - j
   
   setNumber(ledDigitalOne, J);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- K
   changeLED(1,ON);
   changeLED(3,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, K);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - L
   
   setNumber(ledDigitalOne, L);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - M
   changeLED(2,ON);
   changeLED(3,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, M);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - N
   changeLED(2,ON);
   changeLED(3,ON);
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, N);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - 0
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, O);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- P
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, P);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - Q
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, Q);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- R
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, R);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- S
   changeLED(1,ON);
   changeLED(2,ON);
   changeLED(4,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, S);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(2,ON);  // - T
   changeLED(3,ON);
   changeLED(4,ON);
   
   setNumber(ledDigitalOne, T);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - U
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, U);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - V
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, V);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - W
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, W);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - X
   changeLED(5,ON);
   
   setNumber(ledDigitalOne, X);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(0,ON);  // -- Y
   changeLED(1,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, Y);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(2,ON);  // - Z
   changeLED(4,ON);
   changeLED(5,ON);
   changeLED(6,ON);
   
   setNumber(ledDigitalOne, Z);
   
   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   
   changeLED(1,ON);  // - EXCLA
   changeLED(7,ON);
   
   setNumber(ledDigitalOne, EXCLA);

   delay(1000);
   changeLED(0,OFF);
   changeLED(1,OFF);
   changeLED(2,OFF);
   changeLED(3,OFF);
   changeLED(4,OFF);
   changeLED(5,OFF);
   changeLED(6,OFF);
   changeLED(7,OFF);
  
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
