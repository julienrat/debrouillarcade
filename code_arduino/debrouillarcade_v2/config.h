#pragma GCC optimize ("O2")
#pragma once
#define PAL 0
#define NTSC 1

/******************************************************************/
/*Some stats about where we spend our time*/
/******************************************************************/
#define PERF

/******************************************************************/
/*Choose one of the video standards: PAL or NTSC*/
/******************************************************************/
#define VIDEO_STANDARD PAL

#define threshold 20
/******************************************************************/
/*Choose one of the following emulators: EMU_NES,EMU_SMS,EMU_ATARI*/
/******************************************************** Nes**********/
#define EMULATOR EMU_NES
#define USE_SD_CARD
/******************************************************************/
/*Many emus work fine on a single core (S2), file system access can cause a little flickering*/
/******************************************************************/
//#define SINGLE_CORE

/****************************************************************/
/*ESP pin map*/
/****************************************************************/
#define VIDEO_PIN   25	// Both 25 and 26 are locked to video output
#define AUDIO_PIN   35  // can be any pin
#define IR_PIN      45  // TSOP4838 or equivalent on any pin if desired

//NES OR SNES classic controller (wire colors might be different, double check!)
//       ___
//DATA  |o o| NC
//LATCH |o o| NC
//CLOCK |o o/ 3V3
//GND   |o_/
//       _
//3V3   |o|
//CLOCK |o|
//LATCH |o|
//DATA  |o|
//      |-|
//NC    |o|
//NC    |o|
//GND   |o|
//       -  

//NES and SNES controllers share the same pins, therefore both types can not be used at the same time
//Only the DATA pin goes to different IO pins for the two controllers the other pins are shared
//3V3 (red) (NOT 5V!)
//GND (white)
/*
#define NES_CTRL_ADATA 20  //    # DATA controller A	(black)
#define NES_CTRL_BDATA 17  //    # DATA controller B	(black)
#define NES_CTRL_LATCH 27  //    # LATCH	(yellow)
#define NES_CTRL_CLK 1    //    # CLOCK 	(green)
*/
// Define this to enable SD card with FAT 8.3 filenames
// Note that each emulator has its own folder. Place ROMs under /nonfredo for NES, /smsplus for SMS and /atari800 for atari
//#define USE_SD_CARD
// SD card pin mapping
#define CONFIG_SD_CS 5
#define CONFIG_SD_MOSI 23
#define CONFIG_SD_SCK 18
#define CONFIG_SD_MISO 19


// For use with BUTTONS_CONTROLLER
// Define pins for buttons. The pins must not conflict with other options 
// and must be capable of input. Note: not all the pins I tried that were 
// documented as inputs, worked, I suspect that it's because we are forced 
// to use board manager 1.4
/*
#define A_FIRE_PIN 0
#define B_FIRE_PIN 21
#define A_START_PIN 4
#define A_UP_PIN 14
#define A_DOWN_PIN 15
#define A_LEFT_PIN 13
#define A_RIGHT_PIN 12
*/
/****************************************************************/
/*Controller support*/
/****************************************************************/
//#define WEBTV_KEYBOARD
//#define RETCON_CONTROLLER
//#define FLASHBACK_CONTROLLER
//#define APPLE_TV_CONTROLLER
//#define NES_CONTROLLER	//Enable only NES OR SNES not both!
#define BUTTONS_CONTROLLER // direct wired buttons 
//#define SNES_CONTROLLER	//Enable only NES OR SNES not both!

/****************************************************************/
/*Video levels*/
/****************************************************************/
#define SYNC_SIZE        35 //Lowering this to like 35 can help sync issues at times
#define IRE(_x)          ((uint32_t)(((_x)+SYNC_SIZE)*255/3.3/147.5) << 8)   // 3.3V DAC output
#define SYNC_LEVEL       IRE(-SYNC_SIZE)
#define BLANKING_LEVEL   IRE(0)
#define BLACK_LEVEL      IRE(7.5)
#define GRAY_LEVEL       IRE(50)
#define WHITE_LEVEL      IRE(100)
