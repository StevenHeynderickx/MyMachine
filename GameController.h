#pragma once

#include <Arduino.h>

// de GameController is de dirigent van heel het spel/programma.
// Deze moet de andere delen kunnen gebruiken en aansturen.
// De controller moet daarom al de methodes kennen die de specifieke
// controllers (zoals audio, leds en buttons) ter beschikking hebben.
// Daarom wordt in dit stuk code de header-bestanden opnieuw ingeladen.

#include "LedController.h"
#include "ButtonController.h"
#include "AudioController.h"


class GameController {
public:
	// Constructor: GameController krijgt de andere modules mee
	GameController(LedAnimator& leds, ButtonManager& buttons, AudioPlayer& audio);

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
	
	State 			_state; // Dit is de gameState
	unsigned long 	_stateStartTime; // is de millis bij aanvang van een gameState
	LedAnimator& 	_leds; // Een verwijzing naar de ledController
	ButtonManager& 	_buttons; // Een verwijzing naar de buttonController
	AudioPlayer& 	_audio; // Een verwijzing naar de audioController

	// In deze class is er deze hulpfunctie die om debuggen en controle
	// wat makkelijker te maken, telkens de nieuwe gameState print en 
	// de State-timer reset.
	void setState(State newState);
};