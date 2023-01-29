# NIGHT-LIGHT-UINO

## Intro

### Overview
A DIY night light for my bedroom using an Arduino as the processing unit, 2 LED strips for illumination and 2 potentiometers for the user interface.


    [show pictures and videos]


Two LED strips are used to separate them into a left and right side so that me and my wife have our own separate light source which won't affect the other as much. 

Each LED strip is controlled by a potentiometer. By turning the potentiometer the user can adjust the brightness. A special potentiometer is used which has an integrated "twist switch" causing it to "click" when the user starts turning, giving the user a more haptic feedback.

The two LED strips and potentiometers are processed and controlled by a single Arduino Nano Every.


### Requirements
These are the requirements after which the project is build on:
- User friendly:
    - Easy to use (especially when dark)
    - intuitive
    - haptic feedback
- LED strips are hidden behind backboard, only visible when turned on
- Aluminium knobs which are integrated in the night stand
- Quality warm white light instead of rgb
- Using difusor channels to avoid seeing the individual leds and rather see one continuous light bar


### How it works
- how to on and off
- light animations


## Hardware
- Everything you need to know how to build the project for yourself

### Overview
- skizze

### The Components
- Controller - arduino nano every, why
- L1, L2, which type of led strips, why
- P1, P2, explain potentiometer type and its pins
- connection with audio jacks, divison into modules, better for maintenance
- I/O switch

### Shopping List
- Arduino nano every
- potis
- aux connections
- led strips
- led defuser
- power unit
- wood strip
- total cost

### Schematic
- connectors wiring
- wiring Overview
- pcb layout

### Assembly
- case
- potentiometer attachment to night stand
- led strips installement in defuser, doubleshot technique
- defuser attachment to bed back board


## Software
- adafruit neopixel library used

### Animation
- explaination of different animation stages
- using animations to justify using an arduino

### Testing
- why tests were used
- different led strip types
- prototype code snippets
    - potentiometer test
    - two potentiometers test
    - led strip test
    - two led strips test
    - control led strip with poti test

### Main
- main code file

## Unresolved Issues
- tail led flickering when other strip is changing brightness

## Conclusion
- last sentence: so this is it - an over engineered night light, because thats what i do
- dont hesitate to improve this project
