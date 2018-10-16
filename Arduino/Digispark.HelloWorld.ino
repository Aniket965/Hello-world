#include"DigiKeyboard.h"
#include <avr/pgmspace.h>

const char line1[] PROGMEM = "cmd\n";
const char line2[] PROGMEM = "echo \"Hello World\"\n";
char buffer[100];
#define GetPsz(x) (strcpy_P(buffer,(char*)x))

void printText(char*txt) {
	int l = strlen(txt);
	for (int i = 0; i < l; i++) {
		DigiKeyboard.print(txt[i]);
		DigiKeyboard.update();
	}
}
void setup() {
	//Opens command prompt and echos Hello World
	DigiKeyboard.sendKeyStroke(21,MOD_GUI_LEFT);
	DigiKeyboard.delay(200);
	printText(GetPsz(line1));
	DigiKeyboard.delay(200);
	printText(GetPsz(line2));
}

void loop() {
}
