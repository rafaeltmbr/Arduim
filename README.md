# Arduim
Arduino-like library for [Contim's board](https://sites.google.com/a/contim.eng.br/sccs2012/material-pic/Manual%20KIT%20PIC18F4550.pdf?attredirects=0 "Manual.pdf"). This board is based on [PIC16F4550](https://ww1.microchip.com/downloads/en/devicedoc/39632e.pdf "Datasheet") microcontroller. Available functions:
* [arduim.h](include/arduim.h "header file") - Equivalent to Arduino.h header. Current support:
  - [pinMode](src/arduim.c "source file")
  - [digitalRead](src/arduim.c "source file")
  - [digitalWrite](src/arduim.c "source file")
  - [analogRead](src/arduim.c "source file")
  - [analogWrite](src/arduim.c "source file")
  - [delay](src/arduim.c "source file")
  - [map](src/arduim.c "source file")
  
* [lcd.h](include/arduim.h "header file") - LCD library. Current support:
  - [print](src/lcd.c "source file")
