#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "efm32gg.h"
#include "proto.h"
#include "synthesizer.h"
#include "sound_effect.h"
#include "sound/sineTones.h"


/*define what sound mode to trigger*/
const typedef enum {SONG, SOUND_EFFECT} sound_mode_t;
static const sound_mode_t SOUND_MODE=SOUND_EFFECT;

/*copydick*/
static volatile uint16_t playing = 0;
static volatile int16_t note_idx = -1;
static volatile uint16_t sample_idx = 0;
static volatile uint16_t sample = 0;

volatile static sound_t current_sound;
static volatile uint16_t test_boom = 0;


/*private function declarations*/
static void handleGamepad();


/* TIMER1 interrupt handler */
void __attribute__ ((interrupt)) TIMER1_IRQHandler() 
{  
  *TIMER1_IFC = *TIMER1_IF; /* clear interrupt flag */
  current_sound=test;
  
	switch (SOUND_MODE)
	{
		case SONG:
			//load_song();//TODO: just a thought
			break;
		case SOUND_EFFECT:
			if (sample_idx % current_sound.note_duration == 0) // Check if sample is done
			{
				sample_idx = 0;
				note_idx++;
				if (note_idx < current_sound.note_count) // Check if there are more notes to play
				{
					// Prepare next note
					square1_play_note(current_sound.sq1_notes[note_idx]);

				}
				else
				{
					// Disable stuff and go back to sleep
					*GPIO_PA_DOUT = 0xFF00;
					playing = 0;
					*TIMER1_CMD = 2;
					*DAC0_CH0CTRL = 0;
					*DAC0_CH1CTRL = 0;
					*SCR = 0b0110;
				}
			}
			//load_sound_effect();
			break;
	}
	// Get next sample and write do DAC
	sample = get_sample();
	sample_idx++;
  
	dataDAC(sample);
  
 // dataDac(boom[test_boom]);
 // test_boom++;
 // if (test_boom == boomLen)
    //test = 0;
 //   disableDAC();
}

/* LETIMER0 interrupt handler */
void __attribute__ ((interrupt)) LETIMER0_IRQHandler() 
{  
  *LETIMER0_IFC = *LETIMER0_IF; /* clear interrupt flag */
  /* TODO IF TIME */
}

/* GPIO even pin interrupt handler */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler() 
{
	clearInterruptGPIO();
	handleGamepad();
}

/* GPIO odd pin interrupt handler */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler() 
{
    /* TODO handle button pressed event, remember to clear pending interrupt */
	clearInterruptGPIO();
	handleGamepad();
}

void handleGamepad()
{
	LEDupdateGPIO();/*test*/
//	current_sound=test;
	/*TODO: should map button to variable/enum by reading from either
	 * DIN or interrupt flag register. Then use a switch case:*/

	/*switch (gamepadButton)
	 * case SW0:
	 *--play a sound--
	 *	break;
	 *	etc...
	 * */
}
