#include "Arduino.h"

#define PIN7 12
#define PIN6 11
#define PIN5 10
#define PIN4 9
#define PIN3 8
#define PIN2 7
#define PIN1 6
#define PIN0 5

static int PINS[] = {
    PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN1, PIN0};

unsigned short count = 0;
int delay_ms = 100;

void setup() {
	for (int i = 0; i < sizeof(PINS)/sizeof(int); i++)
		pinMode(PINS[i], OUTPUT);
}

void displayBits(int n) {
    for (int k = 0; k < 8; k++) {
        int mask = 1 << k;
        int masked_n = n & mask;
        int bit = masked_n >> k;
        digitalWrite(PINS[k], bit);
    }
}

void loop() {
    displayBits(count);
    count++;
    delay(delay_ms);
}
