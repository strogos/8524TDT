/*
 * synthesizer.h
 *
 *  Created on: Mar 7, 2015
 *      Author: admin
 */

#ifndef SYNTHESIZER_H_
#define SYNTHESIZER_H_

#include <stdint.h>

/* Tone lengths (seconds) */
#define S 0.02			// 1/50
#define QQ 0.0625		// 1/16
#define E 0.125			// 1/8
#define Q 0.25			// 1/4
#define H 0.5			// 1/2
#define F 1
#define L 5
#define VL 10

/*Samples for 44.1 kHz [starting @ C1]*/
#define NOTE_C  674 //65Hz
#define NOTE_Db 633 //~69Hz
#define NOTE_D  601 //~73Hz
#define NOTE_Eb 567 //etc
#define NOTE_E  535
#define NOTE_F  505
#define NOTE_Gb 477
#define NOTE_G  450
#define NOTE_Ab 425
#define NOTE_A  401
#define NOTE_Bb 378
#define NOTE_B  357

#define MAX_AMPLITUDE 0x3F
#define MAX_BIAS 0x7F

typedef struct
{
	uint16_t octave;/*0 = C1 D1 etc--*/
    uint16_t initialPeriod;
    uint16_t lastPeriod;
    uint16_t initialAmplitide;
    uint16_t lastAmplitide;
    uint16_t dutyCycle;
    int32_t duration;
} square_wave_synth_t;


void generateSquareWave(square_wave_synth_t note);
uint16_t getSample();

#endif /* SYNTHESIZER_H_ */
