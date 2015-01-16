# Arduino-library-paraKeypad
A keypad library for Arduino.

with which you can detect your keypad with a Key Vaule and key type, meaning Pressed Down,Up,Hold,or double.


##1.Return format: 
<br>..Return values contains information of two parts
<br>........0b  xxx yyyyy
<br>................yyyyy:----indicate the key value, from 0-31
<br>............xxx-----------indicate the key parameter:
<br>............1. key pressed down
<br>............2. key pressed hold
<br>............3. then key bursting 
<br>............4. key pressed up