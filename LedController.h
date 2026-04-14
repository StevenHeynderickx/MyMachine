#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Config.h"

class LedController {
public:
	// Constructor
	LedController();

	void begin();
	void tick();

	// Basisacties
	void allOff();
	void allOn(uint8_t r, uint8_t g, uint8_t b);
	void blink(uint8_t r, uint8_t g, uint8_t b, unsigned long intervalMs);
	void setLedStateOff();
	void setLedStateOnColor(uint8_t r, uint8_t g, uint8_t b);
	void setLedStateBlinkColor(uint8_t r, uint8_t g, uint8_t b, unsigned long intervalMs);

private:
	// Mogelijke toestanden van de ledcontroller
	enum LedState {
		LS_OPSTARTEN,
		LS_ALL_OFF,
		LS_DROP_EFFECT
		LS_OFF,
		LS_ON_COLOR,
		LS_BLINK_COLOR
	};

	// De "Globale" variabelen voor dit object:
	// Alle methodes in deze class kunnen gebruik maken van deze
	// "private" globale variabelen. Vandaar dat ze starten met "_".
	// Dit is een afspraak en is niet noodzakelijk.
	LedState 		_state;
	unsigned long 	_stateStartTime;
	unsigned long 	_lastBlinkTime;
	bool 			_blinkPhaseOn;

	uint8_t 		_r;
	uint8_t 		_g;
	uint8_t 		_b;
	unsigned long 	_blinkIntervalMs;

	// Ledstripobject
	Adafruit_NeoPixel _strip;

	// In deze class is er deze hulpfunctie die om debuggen en controle
	// wat makkelijker te maken, telkens er een nieuwe ledState is
	// printen we de state en wordt de State-timer gereset.
	void setLedState(LedState newState);
	void showColor(uint8_t r, uint8_t g, uint8_t b);
};
