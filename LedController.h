#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"

class LedController {
public:
	// Constructor:
	LedController();

	void begin();
	void tick();

private:
	// Mogelijke toestanden van het spel
	enum LedState {
		LS_OPSTARTEN,
		LS_ALL_OFF,
		LS_OFF,
		LS_ON_COLOR,
		LS_BLINK_COLOR,
		LS_DROP_EFFECT
	};
	// De "Globale" variabelen voor dit object:
	// Alle methodes in deze class kunnen gebruik maken van deze
	// "private" globale variabelen. Vandaar dat ze starten met "_".
	// Dit is een afspraak en is niet noodzakelijk.

	LedState 			_state; // Dit is de LedState
	unsigned long 		_stateStartTime; // is de millis bij aanvang van een gameState

	// In deze class is er deze hulpfunctie die om debuggen en controle
	// wat makkelijker te maken, telkens de nieuwe gameState print en 
	// de State-timer reset.
	void setLedState(LedState newState);
};
