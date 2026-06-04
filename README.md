# WaPo Walking-Pot

<img height="59px" alt="image" src="https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/pictures/WalkingPotHeaderWhite.png" />

A Pot on 6 Legs that walks towards the sun, to achive the best for it's flower.

While doing the project, I learned a lot of new Stuff. Before beginning this Project, I never touched a PCB modeling software. I did 3d Modelling a few time, but the best i got was a dice. So this Project is a step up. The Things I learned while doing this project, will help me a lot with other Projects.

## Key Facts
WaPo has 6 Legs with 3 Servo motors each to navigate the world.
To know where to go WaPo uses 8 light sensors/resistors to check the light levels around him.
WaPo will find the sensor with the most light, then it will rotate/move in the direction where the most light is registered. 

The PCB has a ESP Wroom chip and 2 PCA9685 LED/Servo Drivers, to be able to controll all 18 Servos at once.
The PCB fits into the bottom of the Pot.

## Why WaPo?
Besides that my plants are not living the best life (weak lightning), I want to explore Hexapods and the combination of all these servos to acctually move the robot.
Maybe that's the only way my plants can survive :)
My Idea was, to set WaPo on the Ground power it on and see where it goes to find the best Spot.

## Visuals
**Assembled 3D model**

<img width="50%" height="auto" alt="image" src="https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/Blender/renders/WaPo-1.png" />
<br>

**PCB 3D Model**

<img width="50%" height="auto" alt="image" src="https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/Blender/renders/PCB-2.png" />
<br>

**PCB Schematic**

[WaPo-Schematic.pdf](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/SCH_WaPo-Schematic_2026-05-25.pdf)
<br>

**PCB Layout**

[PCB_wapo.pdf](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/PCB_PCB_wapo.pdf)

<br>

## Zine

<img width="50%" max-width="540px" height="auto" alt="image" src="https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/zine.png" />

As a PDF: [Zine.pdf](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/zine.pdf)

---

## BOM
Name | Quantity | Price (for all) | Price in USD |Link
:------:|:-------:|:-------:|:-------:|:-------:
PCB (x5) | 1 (5) | ~22,73€ | ~26.44$ | [JLCPCB](https://jlcpcb.com) 
Servos sg90 | 18 | ~0,70€ | ~0.81$ | [AliExpress](https://de.aliexpress.com/item/1005007104370383.html)
Light Resistors | 8 | ~24,06€ | ~27.99$ | [AliExpress](https://de.aliexpress.com/item/32966282692.html)
M2 8mm Screws | 24 | ~0,79€ | ~0.92$ | [AliExpress](https://de.aliexpress.com/item/1005002247282771.html)
M2 10mm Screws | 12 | ~0,41€ | ~0.48$ | [AliExpress](https://de.aliexpress.com/item/1005002247282771.html)
M2 Nuts | 36 | ~1,13€ | ~1.31$ | [AliExpress](https://de.aliexpress.com/item/1005008314195033.html)  
Cables | 16 | ~2,11€ | ~2.45$ | [AliExpress](https://de.aliexpress.com/item/1005007046465880.html)
4.8V 3000mAh Battery | 1 | ~9,64€ | ~11.22$ | [AliExpress](https://de.aliexpress.com/item/1005006690430909.html)
PLA Filament Spool | 1 | ~15,43€ | ~17.95$ | [Amazon](https://www.amazon.com/dp/B0CD161SQR)
Total | | ~77,67€ | ~90.37$ | [BOM-all.csv](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/BOM-all.csv)
Actual Total* | | ~102,56€ | ~119.33$

*Actual Total: Cost including shipping and actual package size (Screws/Nuts come in 50PCS, Light resistors in 10)

View the PCB BOM as CSV: [BOM-PCB.csv](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/BOM-PCB.csv) <br>
View the BOM as CSV: [BOM-all.csv](https://github.com/hackTheWorldHappy/Walking-Pot/blob/main/BOM-all.csv)

---

## Firmware
### Libaries used in Firmware
https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library/tree/master

