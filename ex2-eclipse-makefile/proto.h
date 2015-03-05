/*
 * proto.h
 *
 *  Created on: Mar 4, 2015
 *      Author: B.Hope
 *
 *	...given the size of the project, a single interface is deemed sufficient
 *
 */

#ifndef PROTO_H_
#define PROTO_H_

/* Include the standard library header files. */
//#ifdef HAVE_STDLIB_H
//#include <stdlib.h>
//#endif

/* From gpio.c */
void setupGPIO();
void clearInterruptGPIO();
void LEDupdateGPIO();

/* From dac.c */
void setupDAC();
void disableDAC();

/* From timer.c */
void setupTimer(uint16_t);
void startTimer();
void stopTimer();
void disableTimer();

/*TODO:From interrupt_handlers.c (if any)*/


/*TODO:From generateSong whatever sound or synthesizer.c*/
void loadSong();
void loadSoundEffect();
void stopSong();



#endif /* PROTO_H_ */
