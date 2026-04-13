#include <Arduino.h>
#include "Config.h"
#include "GameController.h"
#include "LedAnimator.h"
#include "ButtonManager.h"
#include "AudioPlayer.h"
#include "BlinkerLed.h"

LedAnimator leds;
ButtonManager buttons;
AudioPlayer audio;
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