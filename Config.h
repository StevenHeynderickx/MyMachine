#pragma once

// ---------------- PINNEN ----------------
//                      +-------------------+
//                      |o 3V3         GND O| 
//                      |o EN  +-----+ G23 O| 
//                      |o SP  |     | G22 O| I2S_DOUT
//                      |o SN  |     | TX0 O| 
//                      |o G34 |ESP32| RX0 O| 
//                      |o G35 |     | G21 O| 
//                      |o G32 |     | GND O| 
//                      |o G33 |     | G19 O| 
//                      |o G25 +-----+ G18 O| 
//                      |o G26          G5 O| 
//                      |o G27         G17 O| 
//             I2S_BCLK |o G14         G16 O| 
//     PIN_CONTROLE_LED |o G12          G4 O| PIN_LEDSTRIP1
//                      |o GND          G0 O| 
//                      |o G13          G2 O| 
//                      |o SD2         G15 O| I2S_LRC
//                      |o SD3         SD1 O| 
//                      |o CHD         SD0 O| 
//                      |o 5V          CLK O| 
//                      +-------------------+
// Pinsetup Led/Ledstrips
constexpr uint8_t PIN_CONTROLE_LED = 12;
constexpr uint8_t PIN_LEDSTRIP = 4;
// Pinsetup Geluid
constexpr uint8_t I2S_BCLK = 14;
constexpr uint8_t I2S_LRC  = 15;
constexpr uint8_t I2S_DOUT = 22;
// Pinsetup Motoren

// Pinsetup Motorsensoren (endstop)



// ---------------- TIMERS/INTERVAL ----------
constexpr uint16_t STARTUP_TIMER_MS = 1000;
constexpr uint16_t RESULT_TIMER_MS  = 800;

// ---------------- LEDSTRIPS ----------------
constexpr uint8_t NUMPIXELS = 30;

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

constexpr Color COLOR_CORRECT = {0, 255, 0};
constexpr Color COLOR_WRONG   = {255, 0, 0};
constexpr Color COLOR_IDLE    = {0, 0, 30};

// ---------------- DEBUG ----------------
constexpr bool DEBUG = true;