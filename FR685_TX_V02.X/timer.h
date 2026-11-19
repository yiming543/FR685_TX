/* 
 * File:   timer.h
 * Author: yiming
 * Comments: 
 * Revision history: V1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TIMER_H
#define	TIMER_H
#include <stdint.h>


typedef struct {
  void (*const set)(uint8_t);
  uint8_t (*const get)(void);
} U8_t;

typedef struct {
  void (*const set)(uint16_t);
  uint16_t (*const get)(void);
} U16_t;

typedef struct{
  U8_t R_CNT;
  U8_t L_CNT;
}TMR2_t;

extern TMR2_t const tmr2;
extern void TMR2_init(void);
extern void TMR2_EvenHandler(void);
#endif	/* TIMER_H */

