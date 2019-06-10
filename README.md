# Arduim
Arduino-like library for [Contim's board](https://sites.google.com/a/contim.eng.br/sccs2012/material-pic/Manual%20KIT%20PIC18F4550.pdf?attredirects=0 "Manual.pdf"). This board is based on [PIC16F4550](https://ww1.microchip.com/downloads/en/devicedoc/39632e.pdf "Datasheet") microcontroller. Available headers:
### [arduim.h](include/arduim.h#L1 "header file") - Equivalent to Arduino.h header.
- Currently implemented functions:
  - [pinMode](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L35 "source file") - configures pinout direction
  - [digitalRead](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L87 "source file") - write to a digital output pin
  - [digitalWrite](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L135 "source file") - read from a digital output pin
  - [analogRead](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L189 "source file") - read from a analog input pin (ADC)
  - [analogWrite](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L228 "source file") - write to a analog output pin (PWM)
  - [delay](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L260 "source file") - wait for a period of time
  - [map](https://github.com/rafaeltmbr/Arduim/blob/442623a7e0893f3a1807250b0f704c4fda4b9c6c/src/arduim.c#L254 "source file") - convert a number from a given range to another
  
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
