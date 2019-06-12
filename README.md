# Arduim
Arduino-like library for [Contim's board](https://sites.google.com/a/contim.eng.br/sccs2012/material-pic/Manual%20KIT%20PIC18F4550.pdf?attredirects=0 "Manual.pdf"). This board is based on [PIC18F4550](https://ww1.microchip.com/downloads/en/devicedoc/39632e.pdf "Datasheet") microcontroller. Available headers:
### [arduim.h](include/arduim.h#L1 "header file") - Equivalent to Arduino.h header.
- Currently implemented functions:
  - pinMode - configures pinout direction
  - digitalRead - write to a digital output pin
  - digitalWrite - read from a digital output pin
  - analogRead - read from a analog input pin (ADC)
  - analogWrite - write to a analog output pin (PWM)
  - delay - wait the specified amount of milliseconds
  - delayMicroseconds - wait the specified amount of microseconds
  - map - convert a number from a given range to another
  - attachInterrupt - attach a callback function to a pin interrupt event
  - detachInterrupt - dettach any interrupt to the given pin
  
### [lcd.h](include/lcd.h#L1 "header file") - LCD library. Partially compatible with Arduino's LiquidCrystal.h
- Currently implemented functions:
  - lcd_get - get a lcd_t struct
  - lcd_select - select a lcd_t struct
  
- Currently implemented methods:
  - .clear - clears the display
  - .setPosition - set the cursor to a given position
  - .prints - prints a given string to the lcd
  - .printl - prints a given long integer to the lcd
  - .printi - prints a given integer to the lcd
  - .printc - prints a given character to the lcd
  - .printf - prints formatted text (like stdio printf)
