#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "proto.h"

///*define what sound mode to trigger*/
//const typedef enum {SONG, SOUND_EFFECT} sound_mode_t;
//static const sound_mode_t SOUND_MODE;
//
///*example sound effects to be made (should be moved to synthesizer .c-file)*/
//const typedef enum {INTRO_SONG, THEME_SONG, CANNON_FIRE, EXPLOSION,
//							GAME_OVER} sound_t;


/*private function declarations*/
static void handleGamepad();



/* TIMER1 interrupt handler */
void __attribute__ ((interrupt)) TIMER1_IRQHandler() 
{  
  /*
    TODO feed new samples to the DAC
    remember to clear the pending interrupt by writing 1 to TIMER1_IFC
  */  

	*TIMER1_IFC = *TIMER1_IF; /* clear interrupt flag */
	*GPIO_PA_DOUT = ~*GPIO_PA_DOUT;/*test*/

	/*TODO play intro song and/or sound effects!!*/

//	switch (SOUND_MODE)
//	{
//		case SONG:
//			//load_song();//TODO: just a thought
//			break;
//		case SOUND_EFFECT:
//			//load_sound_effect();
//			break;
//	}

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

	/*TODO: should map button to variable/enum by reading from either
	 * DIN or interrupt flag register. Then use a switch case:*/

	/*switch (gamepadButton)
	 * case SW0:
	 *--play a sound--
	 *	break;
	 *	etc...
	 * */
}
