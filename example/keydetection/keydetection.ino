
/*

An example for paraKeypad library.
Serial ouput the key pressed status, as followed:

		Key:0X1E down up
		Key:0X1E down up 
		Key:0X1E down up double 
		Key:0X1E down up double 
		Key:0X18 down hold ................. up 
		Key:0X18 down hold ........... up

down: 	key pressed down 
up 		key lift up 
hold 	key held 
. 		key bursting 
double 	key double pressed down

*/


// Do not remove the include below
#include "paraKeypad.h"

//key pins
#define KEY_IO_ADD	4	// + and -
#define KEY_IO_SUB	5
#define KEY_IO_XYZ	6
#define KEY_IO_SET	7

//key value;   varies from 0-31
#define		KEY_VALUE_ADD		0x01 
#define		KEY_VALUE_SUB		0x02
#define		KEY_VALUE_XYZ		0x18
#define		KEY_VALUE_SET		0x1E


#define		KEYNUMBERS		4		//define numbers of key


const uint8_t	keyPins[KEYNUMBERS]  = {
		KEY_IO_ADD,
		KEY_IO_SUB,
		KEY_IO_XYZ,
		KEY_IO_SET};

const uint8_t keyCodes[KEYNUMBERS] = {
		KEY_VALUE_ADD,
		KEY_VALUE_SUB,
		KEY_VALUE_XYZ,
		KEY_VALUE_SET};


paraKeypad keypad(keyPins,KEYNUMBERS,keyCodes);
//paraKeypad keypad(keyPins,KEYNUMBERS);


void setup()
{
    Serial.begin(115200);
    //keypad.debug();
}

void loop()
{
	uint8_t key=keypad.scanKey();

	if(key != NO_KEY)
	{
		switch(key & KEY_PR_MASK)
		{
		case KEY_PR_DW:	
			Serial.print("\nKey:0X");
			Serial.print( key & KEY_VL_MASK,HEX);
			Serial.print("	down");
			break;
		case KEY_PR_HD:
			Serial.print("  hold");
			break;
		case KEY_PR_BR:
			Serial.print(" .");
			break;
		case KEY_PR_UP:
			Serial.print("  up");
			break;

		case KEY_PR_DB:	// you need to enable the #define KEY_DOUBLE_DETECT_ENABLE 
			Serial.print("  double ");
			break;

		default:break;
		}//switch
	}
}
