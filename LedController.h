#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LedController {
public:
	// Constructor:
	LedController(uint8_t NUMPIXELS,uint8_t _PIN_LEDSTRIP, NEO_GRB + NEO_KHZ800);

	void begin();
	void tick();

private:
	// Mogelijke toestanden van het spel
	/* enum State {
		GS_OPSTARTEN,
		GS_WAIT_FOR_GAME_SELECT,

	};
	*/
	// De "Globale" variabelen voor dit object:
	// Alle methodes in deze class kunnen gebruik maken van deze
	// "private" globale variabelen. Vandaar dat ze starten met "_".
	// Dit is een afspraak en is niet noodzakelijk.
	
constexpr uint8_t _NUMPIXELS = 30;
constexpr uint8_t _PIN_LEDSTRIP = 4;
};
