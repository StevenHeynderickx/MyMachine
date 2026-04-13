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

// GameController krijgt toegang tot leds, buttons en audio
GameController game(leds, buttons, audio);

void setup() {
	Serial.begin(115200);

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
