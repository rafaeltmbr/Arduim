# Arduim
Arduino-like library for [Contim's board](https://sites.google.com/a/contim.eng.br/sccs2012/material-pic/Manual%20KIT%20PIC18F4550.pdf?attredirects=0 "Manual.pdf"). This board is based on [PIC16F4550](https://ww1.microchip.com/downloads/en/devicedoc/39632e.pdf "Datasheet") microcontroller. Available headers:
### [arduim.h](include/arduim.h "header file") - Equivalent to Arduino.h header.
- Currently implemented functions:
  - [pinMode](src/arduim.c "source file") - configures pinout direction
  - [digitalRead](src/arduim.c "source file") - write to a digital output pin
  - [digitalWrite](src/arduim.c "source file") - read from a digital output pin
  - [analogRead](src/arduim.c "source file") - read from a analog input pin (ADC)
  - [analogWrite](src/arduim.c "source file") - write to a analog output pin (PWM)
  - [delay](src/arduim.c "source file") - wait for a period of time
  - [map](src/arduim.c "source file") - map distinct ranges
  
### [lcd.h](include/lcd.h "header file") - LCD library. Partially compatible with Arduino's LiquidCrystal.h
- Currently implemented functions:
  - [lcd_get](src/lcd.c "source file") - get a lcd_t struct
  - [lcd_select](src/lcd.c "source file") - select a lcd_t struct
  
- Currently impemented methods:
  - [.clear](src/lcd.c "source file") - clears the display
  - [.setPosition](src/lcd.c "source file") - set the cursor to a given position
  - [.prints](src/lcd.c "source file") - prints a given string to the lcd
  - [.printl](src/lcd.c "source file") - prints a given long integer to the lcd
  - [.printi](src/lcd.c "source file") - prints a given integer to the lcd
  - [.printc](src/lcd.c "source file") - prints a given character to the lcd
