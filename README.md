# Analog-to-Digital-Converter
Use of ADC in AVR microcontrollers

## Introduction
The program was written to demonstrate the working of Analog to Digital Converters in AVR microcontrollers. A light dependent resistor (LDR) was used at the input of the ADC port.
The resistance of the LDR is inversly proportional to the intensity of light. As the intensity of light changes, different LEDs light depending on the intensity. Also, more light
results in less LEDs being switched on and vice versa. The program is used to mimic the operation of lighting controls for street lamps.

## Technologies
#### Software
* Arduino IDE
* C language

#### Hardware
* Atmega328pu microcontroller
* USB to Serial converter (used PL2303 USB to UART converter)
* 16 MHZ crystal
* 22pf capacitors (2)
* 220ohm resistors (3)
* LEDS (3)
* 10kohm resistor (for reset button)
* button (for reset)
* light dependent resistor (LDR)

## Launch
When using Arduino IDE with Atmega328pu microcontroller ensure that under Tools menu the following are selected before uploading:
* Board: "Arduino Nano"
* Processor: "ATmega328P(Old Bootloader)"
* Port: (choose appropriate port in which USB to Serial Converter is connected)

## Illustrations
<div align="center">
  <a href="https://drive.google.com/file/d/1-A1Ns_NN1Rjx8O30CO4Nim65amHZVZRz/view?usp=sharing"><img src="https://drive.google.com/file/d/1-A1Ns_NN1Rjx8O30CO4Nim65amHZVZRz/view?usp=sharing" alt="IMAGE ALT TEXT"></a>
</div>
