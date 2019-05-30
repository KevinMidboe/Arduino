#ifndef __JOYSTICKCONTROLLER_H__
#define __JOYSTICKCONTROLLER_H__

class JoystickController{
  protected:
    static const int DEFAULT_LOW   = 490;
    static const int DEFAULT_HIGH  = 530;
    
    int _threshouldLow;
    int _threshouldHigh;
    
    int _direction;
    bool _selectButtonPressed;
    bool _upButtonPressed;
    bool _downButtonPressed;
    bool _leftButtonPressed;
    bool _rightButtonPressed;
    
    void _setup();
    void _reset();
    void _updateDirection();
    void _updateButtons();
    bool _buttonPressed(int state);
    
  public:
    /**
     * Directions in the integer format.
     */
    static const int DIRECTION_NONE       = 0;
    static const int DIRECTION_UP         = 1;
    static const int DIRECTION_UP_RIGHT   = 2;
    static const int DIRECTION_RIGHT      = 3;
    static const int DIRECTION_DOWN_RIGHT = 4;
    static const int DIRECTION_DOWN       = 5;
    static const int DIRECTION_DOWN_LEFT  = 6;
    static const int DIRECTION_LEFT       = 7;
    static const int DIRECTION_UP_LEFT    = 8;
    
    /**
     * Constructor. The first argument specifies the lower threshould value for the directional key pad, 
     * below which the controller is assumed to set left/down in the horizontal/vertical direction.
     * The second argument specifies the upper threshould value, 
     * above which the controller is assumed to set right/up in the horizontal/vertical direction.
     */
    JoystickController(int low = DEFAULT_LOW, int high = DEFAULT_HIGH);
    
    /**
     * Must get called in the main loop.
     */
    void update();
    
    /**
     * Returns the current direction in the integer format.
     */
    int getDirection();
    
    /**
     * Returns true if a button is being pressed, otherwise false.
     */
    bool upButtonPressed();
    bool downButtonPressed();
    bool leftButtonPressed();
    bool rightButtonPressed();
    
    /**
     * Returns true if the select button (directional keypad) is being pressed, otherwise false.
     */
    bool selectButtonPressed();
};

#endif
