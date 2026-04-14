#include <Arduino.h>
#include "Config.h"
#include "GameController.h"
#include "LedController.h"
#include "ButtonController.h"
#include "AudioController.h"
#include "BlinkerLed.h"

LedController leds;
ButtonController buttons;
AudioController audio;
BlinkerLed controleLed;

void setupSerial();

// GameController krijgt toegang tot leds, buttons en audio
GameController game(leds, buttons, audio);

void setup() {
	setupSerial();
	buttons.begin();
	leds.begin();
	audio.begin();
	game.begin();
	controleLed.begin();
}

void loop() {
	buttons.tick();
	audio.tick();
	leds.tick();
	game.tick();
	controleLed.tick();
}

void setupSerial(){
	Serial.begin(115200);
	delay(100);
	Serial.println("System start...");
}
