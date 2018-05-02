I recently got a couple of MAFs from a friend who sold his SAAB. 
So I was wondering what to do with them and decided to hook up one of them to my PC. 
I fired up the Arduino and reused a small sketch. Currently it sends the data via serial to the PC, but of course you can easily hook up an LCD if you want and make it completely autonomous.
The wiring is fairly simple:
MAF pin F to Arduino pin 3
MAF - to Arduno barrel jack ground
MAF + to Arduino barrel jack +
Don't forget to connect 12ish V power supply to the barrel jack of the Arduino.
The pullup resistors in Arduino are weak sauce for this purpose, so hook up 0.5k-1k resistor from pin 3 to +5 (not vin!).

The thing works beautifully! I was amazed at how sensitive and quick the measurement is, its really mind-blowing! 
I still cant think of a project where to integrate this in, but I think that it can be quite useful to the right person. 
I took the table with conversion from frequency to g/s from WIS, so it should be accurate. Its scaled from 1 to 140 g/s. 
Which is ~0.7 to 100 l/s at normal T and  P, quite high range.

Here are some picture:
![](https://preview.ibb.co/bzwQoH/MAF1.jpg)
Handsfree specific:
Unsolder the wires of the microphone and solder longer leads on it. Then stick it in on of the holes of the face plate like so:
![](https://preview.ibb.co/gwTGvx/MAF2.jpg)
Handsfree specific:
Unsolder the wires of the microphone and solder longer leads on it. Then stick it in on of the holes of the face plate like so:
![](https://preview.ibb.co/mmVh2c/Mafdemo2.png)
Handsfree specific:
Unsolder the wires of the microphone and solder longer leads on it. Then stick it in on of the holes of the face plate like so:
![](https://preview.ibb.co/dC1Bvx/Mafdemo1.png)
