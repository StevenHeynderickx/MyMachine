#include "LedController.h"

LedController::LedController()
	: _state(LS_OPSTARTEN),
	  _stateStartTime(0),
	  _lastBlinkTime(0),
	  _blinkPhaseOn(false),
	  _r(0),
	  _g(0),
	  _b(0),
	  _blinkIntervalMs(500),
	  _strip(NUMPIXELS, PIN_LEDSTRIP, NEO_GRB + NEO_KHZ800) {
}

void LedController::begin() {
	// Het _strip object dat in de header-file is aangemaakt wordt
	// hier gestart, de ledkleurenbuffer wordt op nul gezet (alle leds uit)
	// Deze buffer wordt dan naar de strip gestuurd.
	_strip.begin();
	allOff();

	if (DEBUG) {
		Serial.printf("Ledstrip met %d leds aangesloten op pin %d\n", NUMPIXELS, PIN_LEDSTRIP);
	}
	setLedState(LS_OPSTARTEN);
}

void LedController::tick() {
	unsigned long now = millis();

	switch (_state) {
		case LS_OPSTARTEN:
			// Herkenbare animatie om aan te geven dat de Ledstrips werken
			if (now - _stateStartTime > 3000){
				setLedState(LS_IDLE);
			}
			break;
		case LS_IDLE:
			// wacht gewoon
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
			Serial.print("In LedController tick(), state ");
			Serial.print(_state);
			Serial.println(" onbekend");
	}
		
}

void LedController::setLedState(LedState newState) {
	_state = newState;
	_stateStartTime = millis();
	
	switch (_state) {
		case LS_OPSTARTEN:
			Serial.println("LS_OPSTARTEN");
			break;
		case LS_IDLE:
			Serial.println("LS_IDLE");
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
			Serial.print("In LedController, state ");
			Serial.print(_state);
			Serial.println(" onbekend");
	}

}
void LedController::showColor(uint8_t r, uint8_t g, uint8_t b){
	Serial.printf("Volgende kleurcombinatie zit in het geheugen %d %d %d\n", r, g, b);
}

void LedController::allOff(){
	_strip.clear();
	_strip.show();
}
void LedController::allOn(uint8_t r, uint8_t g, uint8_t b){
	_strip.fill(_strip.Color(r, g, b));
	_strip.show();		
}
void LedController::blink(uint8_t r, uint8_t g, uint8_t b, unsigned long intervalMs){
	
}
void LedController::setLedStateOff(){
	
}
void LedController::setLedStateOnColor(uint8_t r, uint8_t g, uint8_t b){
	
}
void LedController::setLedStateBlinkColor(uint8_t r, uint8_t g, uint8_t b, unsigned long intervalMs){
	
}
