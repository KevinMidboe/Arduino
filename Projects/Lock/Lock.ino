// Keypad_Lock.ino
#include <Servo.h>
#include <Keypad.h>

// Output
int led = 2;

// Input
char passphrase[] = {'1', '2', '3', '4'};
int pass_length = sizeof(passphrase);
bool locked = true;
int i = 0;
int angle = 0;

const byte rows = 4;
const byte cols = 3;
char keys[rows][cols] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3};

Servo myservo;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void unlock() {
	locked = false;

	for(int i=0; i<5; i++) {
		digitalWrite(led, HIGH);
		delay(250);
		digitalWrite(led, LOW);   
		delay(250);
	}

	myservo.write(160);
}

void lock() {
	locked = true;
	i = 0;

	myservo.write(40);
}

void correct_entry() {
	i++;
	
	if (i!=pass_length) {
		//digitalWrite(led, HIGH);
		//delay(250);
		//digitalWrite(led, LOW);
	}
	else {
		unlock();
	}
}

void setup() {
	Serial.begin(9600);

	// Output
	pinMode(led, OUTPUT);
	myservo.attach(10, 0, 2000);
}

void loop() {
	char key = keypad.getKey();

	if (key) {
		// Debug
		Serial.print(key);
		Serial.println(passphrase[i]);

		// key_pressed();

		if (locked==false) {
			if (key=='*') {
				lock();
			} 
		}
		else {
			if (i==0) {
				if (key==passphrase[i]) {
					correct_entry();
				}
			}
			else if (i>0) {
				if (key==passphrase[i]) {
					correct_entry();
				}
				else {
					i=0;
				}
			}
		}
	}
}


