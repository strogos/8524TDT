/*
 * sound_effect.h
 *
 *  Created on: Mar 7, 2015
 *      Author: admin
 */

#ifndef SOUND_EFFECT_H_
#define SOUND_EFFECT_H_

#include "synthesizer.h"

typedef struct
{
  uint16_t note_count;
  uint16_t note_duration;
  square_wave_synth_t *sq1_notes;

} sound_effect_t;

extern sound_effect_t test;

#endif /* SOUND_EFFECT_H_ */
