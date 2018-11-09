#include <Keyboard.h>

const int joystick_x = A0;
const int joystick_y = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  
  sendKey(6, 'w', 150);
  sendKey(7, 's', 150);
  sendKey(9, 'd', 150);
  sendKey(5, 'b', 150);
  sendKey(2, 'a', 150);

  int x_Read = analogRead(joystick_x);
    if( x_Read <= 300 ){
      Keyboard.press(KEY_UP_ARROW);  
    }
    else if( x_Read >= 700 ){
      Keyboard.press(KEY_DOWN_ARROW);  
    }
    else{
      Keyboard.release(KEY_UP_ARROW);
      Keyboard.release(KEY_DOWN_ARROW);
    }

  int y_Read = analogRead(joystick_y);
    if( y_Read <= 300 ){
      Keyboard.press(KEY_RIGHT_ARROW);  
    }
    else if( y_Read >= 700 ){
      Keyboard.press(KEY_LEFT_ARROW);  
    }
    else{
      Keyboard.release( KEY_RIGHT_ARROW);
      Keyboard.release( KEY_LEFT_ARROW);
    }
}

void sendKey(int pin, char key, int wait){
  if(digitalRead(pin) == LOW){
    Keyboard.press(key);
    delay(wait);
    Keyboard.release(key);   
  }
}
