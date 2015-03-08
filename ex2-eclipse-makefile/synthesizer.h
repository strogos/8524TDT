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
#define NOTE_Eb 567 //
#define NOTE_E  535
#define NOTE_F  505
#define NOTE_Gb 477
#define NOTE_G  450
#define NOTE_Ab 425
#define NOTE_A  401
#define NOTE_Bb 378
#define NOTE_B  357

#define MAX_AMPLITUDE_PER_CHANNEL 0x3F
#define MAX_BIAS 0x7F

typedef struct
{
    uint16_t period_begin;
    uint16_t octave;
    uint16_t amp_begin;

    uint16_t period_end;
    uint16_t amp_end;
    uint16_t duty_cycle;
    int32_t duration;
} square_note_t;



void generateSquareWave (int,int);
void square1_play_note(square_note_t note);

/*setters 'n getters*/
uint16_t get_sample();

#endif /* SYNTHESIZER_H_ */
