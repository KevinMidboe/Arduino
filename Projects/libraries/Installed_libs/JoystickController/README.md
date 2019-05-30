# JoystickController

Fully compatible with SparkFun's [Arduino joystick shield](https://www.sparkfun.com/products/9760?). The library lets you easily fetch the current status of the joystick (demo video is [here](https://vimeo.com/49010406)). Implementation is quite simple;

	JoystickController(int low = DEFAULT_LOW, int high = DEFAULT_HIGH)

is a constructor. The first argument specifies the lower threshold value for the directional key pad, below which the controller is assumed to set left/down in the horizontal/vertical direction. The second argument specifies the upper threshold value, above which the controller is assumed to set right/up in the horizontal/vertical direction. If arguments are not specified, the following default values will be used:

	static const int DEFAULT_LOW   = 490;
	static const int DEFAULT_HIGH  = 530;

For more information about the threshold see the following article; [How do I find the current direction of the joystick?](http://www.sparkfun.com/tutorials/171#direction)

	void update()

must get called in the main loop in order for the library to communicate with the joystick.

	int getDirection()

returns the current direction of the directional keypad as integer values that are defined as class static variables:

	static const int DIRECTION_NONE       = 0;
	static const int DIRECTION_UP         = 1;
	static const int DIRECTION_UP_RIGHT   = 2;
	static const int DIRECTION_RIGHT      = 3;
	static const int DIRECTION_DOWN_RIGHT = 4;
	static const int DIRECTION_DOWN       = 5;
	static const int DIRECTION_DOWN_LEFT  = 6;
	static const int DIRECTION_LEFT       = 7;
	static const int DIRECTION_UP_LEFT    = 8;

Finally buttons' status can be fetched from the following functions:

	bool upButtonPressed()
	bool downButtonPressed()
	bool leftButtonPressed()
	bool rightButtonPressed()
	bool selectButtonPressed()

They return true if a button is being pressed, otherwise false.

## Example

Here is a simple example for the library implementation.

	#include "JoystickController.h"

	JoystickController controller;

	void setup(){
		Serial.begin(9600);
	}
	
	void loop(){
		controller.update();

		if (controller.selectButtonPressed()){
			Serial.println("S");
		}
	
		if (controller.upButtonPressed()){
			Serial.println("U");
		}

		if (controller.downButtonPressed()){
			Serial.println("D");
		}

		if (controller.leftButtonPressed()){
			Serial.println("L");
		}
	
		if (controller.rightButtonPressed()){
			Serial.println("R");
		}

		int direct = controller.getDirection();
	
		switch (direct){
			case  JoystickController::DIRECTION_UP:
				Serial.println("UP");
				break;
			case  JoystickController::DIRECTION_UP_RIGHT:
				Serial.println("UP-RIGHT");
				break;
			case  JoystickController::DIRECTION_RIGHT:
				Serial.println("RIGHT");
				break;
			case  JoystickController::DIRECTION_DOWN_RIGHT:
				Serial.println("DOWN-RIGHT");
				break;
			case  JoystickController::DIRECTION_DOWN:
				Serial.println("DOWN");
				break;
			case  JoystickController::DIRECTION_DOWN_LEFT:
				Serial.println("DOWN-LEFT");
				break;
			case  JoystickController::DIRECTION_LEFT:
				Serial.println("LEFT");
				break;
			case  JoystickController::DIRECTION_UP_LEFT:
				Serial.println("UP-LEFT");
				break;
		}

		delay(100);
	}

## Related articles

* [Arduino joystick controller library](http://blog.boreal-kiss.net/2012/09/07/arduino-joystick-controller-library/)

## License

This project is provided under the terms of the [MIT License](http://www.opensource.org/licenses/mit-license.php).

## Contact

* [http://blog.boreal-kiss.net/](http://blog.boreal-kiss.net/)
* [http://twitter.com/borealkiss](http://twitter.com/borealkiss)