#include "GameController.h"
#include "Config.h"

GameController::GameController(LedAnimator& leds, ButtonManager& buttons, AudioPlayer& audio)
	: _state(STATE_STARTUP),
	  _stateStartTime(0),
	  _leds(leds),
	  _buttons(buttons),
	  _audio(audio) {
}

void GameController::begin() {
	// Het enige dat hier voorlopig gebeurd is 
	// dat de gameState op "GS_OPSTARTEN" wordt gezet.
	setState(GS_OPSTARTEN);
}

void GameController::tick() {
	unsigned long now = millis();

	switch (_state) {

		case GS_OPSTARTEN:
			// systemCheck: als alles OK is, dan naar 
			// GS_WAIT_FOR_GAME_SELECT
			if (true) {
				// setState(GS_WAIT_FOR_GAME_SELECT);
			}
			break;

		case GS_WAIT_FOR_GAME_SELECT:
			// Hier zou je later knopcontrole doen
			// Voorbeeld:
			// if (_buttons.hasNewPress()) { ... }

			// Tijdelijke test: ga na 3 seconden naar CORRECT
			if (now - _stateStartTime >= 3000) {
				setState(STATE_CORRECT);
			}
			break;

	}
		switch (_state) {
		case GS_OPSTARTEN:
			Serial.println("GS_OPSTARTEN");
			break;
		case GS_WAIT_FOR_GAME_SELECT:
			Serial.println("GS_WAIT_FOR_GAME_SELECT");
			break;
		case GS_PLANETS_SETUP:
			Serial.println("GS_PLANETS_SETUP");
			break;
		case GS_PLANETS_MISSION_SET:
			Serial.println("GS_PLANETS_MISSION_SET");
			break;
		case GS_PLANETS_MISSION_WAIT:
			Serial.println("GS_PLANETS_MISSION_WAIT");
			break;
		case GS_PLANETS_MISSION_WON:
			Serial.println("GS_PLANETS_MISSION_WON");
			break;
		case GS_PLANETS_MISSION_LOST:
			Serial.println("GS_PLANETS_MISSION_LOST");
			break;
		case GS_PLANETS_MISSION_COUNT:
			Serial.println("GS_PLANETS_MISSION_COUNT");
			break;
		case GS_PLANETS_MISSION_CHEER:
			Serial.println("GS_PLANETS_MISSION_CHEER");
			// Voorbeeld:
			// _leds.flash(0, 255, 0, 300);
			// _audio.play("correct.wav");
			break;
		case GS_PLANETS_MISSION_FAIL:
			Serial.println("GS_PLANETS_MISSION_FAIL");
			// Voorbeeld:
			// _leds.flash(255, 0, 0, 300);
			// _audio.play("wrong.wav");
			break;
		case GS_PLANETS_MOTOR_DOWN_WARNING:
			Serial.println("GS_PLANETS_MOTOR_DOWN_WARNING");
			break;
		case GS_PLANETS_MOTOR_DOWN:
			Serial.println("GS_PLANETS_MOTOR_DOWN");
			break;
		case GS_PLANETS_MOTOR_UP_WARNING:
			Serial.println("GS_PLANETS_MOTOR_UP_WARNING");
			break;
		case GS_PLANETS_MOTOR_UP:
			Serial.println("GS_PLANETS_MOTOR_UP");
			break;
	}
}

void GameController::setState(State newState) {
	_state = newState;
	_stateStartTime = millis();

	switch (_state) {
		case GS_OPSTARTEN:
			Serial.println("GS_OPSTARTEN");
			break;
		case GS_WAIT_FOR_GAME_SELECT:
			Serial.println("GS_WAIT_FOR_GAME_SELECT");
			break;
		case GS_PLANETS_SETUP:
			Serial.println("GS_PLANETS_SETUP");
			break;
		case GS_PLANETS_MISSION_SET:
			Serial.println("GS_PLANETS_MISSION_SET");
			break;
		case GS_PLANETS_MISSION_WAIT:
			Serial.println("GS_PLANETS_MISSION_WAIT");
			break;
		case GS_PLANETS_MISSION_WON:
			Serial.println("GS_PLANETS_MISSION_WON");
			break;
		case GS_PLANETS_MISSION_LOST:
			Serial.println("GS_PLANETS_MISSION_LOST");
			break;
		case GS_PLANETS_MISSION_COUNT:
			Serial.println("GS_PLANETS_MISSION_COUNT");
			break;
		case GS_PLANETS_MISSION_CHEER:
			Serial.println("GS_PLANETS_MISSION_CHEER");
			// Voorbeeld:
			// _leds.flash(0, 255, 0, 300);
			// _audio.play("correct.wav");
			break;
		case GS_PLANETS_MISSION_FAIL:
			Serial.println("GS_PLANETS_MISSION_FAIL");
			// Voorbeeld:
			// _leds.flash(255, 0, 0, 300);
			// _audio.play("wrong.wav");
			break;
		case GS_PLANETS_MOTOR_DOWN_WARNING:
			Serial.println("GS_PLANETS_MOTOR_DOWN_WARNING");
			break;
		case GS_PLANETS_MOTOR_DOWN:
			Serial.println("GS_PLANETS_MOTOR_DOWN");
			break;
		case GS_PLANETS_MOTOR_UP_WARNING:
			Serial.println("GS_PLANETS_MOTOR_UP_WARNING");
			break;
		case GS_PLANETS_MOTOR_UP:
			Serial.println("GS_PLANETS_MOTOR_UP");
			break;
	}
}