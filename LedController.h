#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


// --- OBJECTEN


class LedController {
public:
	// Constructor:
	LedController(uint8_t NUMPIXELS,uint8_t _PIN_LEDSTRIP, NEO_GRB + NEO_KHZ800);

	void begin();
	void tick();

private:
	// Mogelijke toestanden van het spel
	enum State {
		GS_OPSTARTEN,
		GS_WAIT_FOR_GAME_SELECT,
		GS_PLANETS_SETUP,
		GS_PLANETS_MISSION_SET,
		GS_PLANETS_MISSION_WAIT,
		GS_PLANETS_MISSION_WON,
		GS_PLANETS_MISSION_LOST,
		GS_PLANETS_MISSION_COUNT,
		GS_PLANETS_MISSION_CHEER,
		GS_PLANETS_MISSION_FAIL,
		GS_PLANETS_MOTOR_DOWN_WARNING,
		GS_PLANETS_MOTOR_DOWN,
		GS_PLANETS_MOTOR_UP_WARNING,
		GS_PLANETS_MOTOR_UP
	};
	// De "Globale" variabelen voor dit object:
	// Alle methodes in deze class kunnen gebruik maken van deze
	// "private" globale variabelen. Vandaar dat ze starten met "_".
	// Dit is een afspraak en is niet noodzakelijk.
	
constexpr uint8_t _NUMPIXELS = 30;
constexpr uint8_t _PIN_LEDSTRIP = 4;

	// In deze class is er deze hulpfunctie die om debuggen en controle
	// wat makkelijker te maken, telkens de nieuwe gameState print en 
	// de State-timer reset.
	void setState(State newState);
};