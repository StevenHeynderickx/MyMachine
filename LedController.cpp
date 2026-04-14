#include "LedController.h"
#include "Config.h"

LedController::LedController()
	: _state(LS_OPSTARTEN),
	  _stateStartTime(0) {
}

void LedController::begin() {
	Adafruit_NeoPixel pixels(NUMPIXELS, PIN_LEDSTRIP, NEO_GRB + NEO_KHZ800);
	if (DEBUG) {
		printf("Ledstrip met %d leds aangesloten op pin %d", NUMPIXELS, PIN_LEDSTRIP);
	}
	setState(LS_OPSTARTEN);
}

void LedController::tick() {
	unsigned long now = millis();

	switch (_state) {
		case LS_OPSTARTEN:
			// Herkenbare animatie om aan te geven dat de Ledstrips werken
			break;
		case LS_ALL_OFF:
			// Zet alle ledStrips uit
			break;
		case LS_OFF:
			// Zet een ledStrips uit
			break;
		case LS_ON_COLOR:
			// Zet een Ledstrip aan
			break;
		case LS_BLINK_COLOR:
			// Laat een ledstrip knipperen
			break;
		case LS_DROP_EFFECT:
			// Laat 'vallende' animatie zien
			// Kan gebruikt worden als tijdsaanduiding
			break;
		default:
			Serial.print("In LedController tick(), state");
			Serial.print(_state);
			Serial.println("onbekend");
	}
		
}

void LedController::setLedState(LedState newState) {
	_state = newState;
	_stateStartTime = millis();
	
	switch (_state) {
		case LS_OPSTARTEN:
			Serial.println("LS_OPSTARTEN");
			break;
		case LS_ALL_OFF:
			Serial.println("LS_ALL_OFF");
			break;
		case LS_OFF:
			Serial.println("LS_OFF");
			break;
		case LS_ON_COLOR:
			Serial.println("LS_ON_COLOR");
			break;
		case LS_BLINK_COLOR:
			Serial.println("LS_BLINK_COLOR");
			break;
		case LS_DROP_EFFECT:
			Serial.println("LS_DROP_EFFECT");
			break;
		default:
			Serial.print("In LedController, state");
			Serial.print(_state);
			Serial.println("onbekend");
	}
}
