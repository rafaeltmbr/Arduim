# Arduim
Arduino-like library for [Contim's board](doc/Manual-KIT-PIC18F4550.pdf "Manual.pdf"). This board is based on [PIC18F4550](doc/PIC18F4550.pdf "Datasheet") microcontroller. Available headers:
### [arduim.h](include/arduim.h#L1 "header file") - Equivalent to Arduino.h header.
- Currently implemented functions:
  - pinMode - configures pinout direction
  - digitalRead - read from a digital input pin
  - digitalWrite - write to a digital output pin
  - analogRead - read from an analog input pin (ADC)
  - analogWrite - write to an analog output pin (PWM)
  - delay - wait the specified amount of milliseconds
  - delayMicroseconds - wait the specified amount of microseconds
  - map - convert a number from a given range into another
  - attachInterrupt - attach a callback function to a pin interrupt event
  - detachInterrupt - dettach interrupt events for the specified pin
  
### [lcd.h](include/lcd.h#L1 "header file") - LCD library.
- Currently implemented functions:
  - lcd_get - get a lcd_t struct
  - lcd_select - select and initialize the lcd_t struct
  
- Currently implemented methods:
  - .clear - clears the display
  - .setPosition - set the cursor at the specified position (column, line)
  - .prints  - prints a string
  - .printi  - prints a integer/long interger
  - .printui - prints a unsigned integer/unsigned long interger
  - .printc  - prints a character
  - .printd  - prints a double/float
