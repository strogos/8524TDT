/*
 * sound_effect.c
 *
 *  Created on: Mar 7, 2015
 *      Author: kaptein kuk
 */
#include "sound_effect.h"
//#include "synthesizer.h"

static square_wave_synth_t test_sqr_notes1[] =
{
	{.initialPeriod = NOTE_C, .lastPeriod = NOTE_C, .octave = 3, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .duty_cycle = 50, .duration = 6615},
	{.initialPeriod = NOTE_C, .lastPeriod = NOTE_C, .octave = 1, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .duty_cycle = 50, .duration = 6615},
	{.initialPeriod = NOTE_C, .lastPeriod = NOTE_C, .octave = 0, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .duty_cycle = 50, .duration = 6615},
	{.initialPeriod = NOTE_D, .lastPeriod = NOTE_C, .octave = 1, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/10, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/30, .duty_cycle = 50, .duration = 6615},
	{.initialPeriod = NOTE_A, .lastPeriod = NOTE_C, .octave = 1, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/30, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/90, .duty_cycle = 50, .duration = 6615},
	{.initialPeriod = NOTE_Db, .lastPeriod = NOTE_Db, .octave = 1, .initialAmplitide = MAX_AMPLITUDE_PER_CHANNEL/90, .lastlAmplitide = MAX_AMPLITUDE_PER_CHANNEL/270, .duty_cycle = 50, .duration = 6615},
};

sound_t test =
{
	.note_count = 6,
	.note_duration = 50000,
	.sq1_notes = test_sqr_notes1,
};
