/*
 Name:		irx.ino
 Created:	4/15/2023 6:40:39 PM
 Author:	Deci
*/

// the setup function runs once when you press reset or power the board
#include <IRremote.hpp>
#include <limits.h>
#include <stdint.h>
#include <IRremote.h> // include the IRremote library
#include  <string.h>
static constexpr uint8_t RECEIVER_PIN = 2;

void setup()
{
	Serial.begin(9600); // begin serial communication with a baud rate of 9600
	IrReceiver.setReceivePin(RECEIVER_PIN);
	IrReceiver.enableIRIn();
	IrReceiver.blink13(true);
	
}

void loop()
{
	if (IrReceiver.decode()) {
		const auto d = IrReceiver.decodedIRData;
		char s[128];

/*#ifdef __cplusplus
#define PSTR
#endif*/

		snprintf_P(s, sizeof(s), PSTR("%p | %d | %d"), d.address, d.decodedRawData,d.protocol);
		Serial.println(s);
		IrReceiver.resume();
	}
}
