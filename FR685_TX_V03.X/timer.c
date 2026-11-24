/*
 * File:   timer.c
 * Author: T00904
 *
 * Created on November 13, 2026, 10:22 AM
 */
#include "timer.h"
#include "mcc_generated_files/tmr2.h"

// 物件屬性
static volatile uint8_t R_Cnt = 0U; // 單位:1ms
static volatile uint8_t L_Cnt = 0U; // 單位:1ms

// 物件方法
static void R_CNT_SET(uint8_t data) {
  R_Cnt = data;
}

static uint8_t R_CNT_GET(void) {
  return R_Cnt;
}

static void L_CNT_SET(uint8_t data) {
  L_Cnt = data;
}

static uint8_t L_CNT_GET(void) {
  return L_Cnt;
}

// 物件
TMR2_t const tmr2 = {
    .R_CNT = {.set = R_CNT_SET, .get = R_CNT_GET},
    .L_CNT = {.set = L_CNT_SET, .get = L_CNT_GET},
};

void TMR2_EvenHandler(void) {
  if (R_Cnt > 0U) {
    R_Cnt--;
  }

  if (L_Cnt > 0U) {
    L_Cnt--;
  }
}

void TMR2_init(void) {
  TMR2_SetInterruptHandler(TMR2_EvenHandler);
}
