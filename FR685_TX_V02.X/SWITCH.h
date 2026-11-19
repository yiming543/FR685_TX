#ifndef SWITCH_H
#define SWITCH_H

#include "LED.h"
#include <stdint.h>

// 範例
// sw.pos.get();

typedef struct {
  uint8_t (*const get)(void);
  uint8_t (*const is_on)(void);
} SWITCH_t;

typedef struct {
  SWITCH_t pos;
  SWITCH_t drl;
  SWITCH_t loBeam;
  SWITCH_t hiBeam;
  SWITCH_t turnLeft;
  SWITCH_t turnRight;
} SWITCHs_t;

typedef struct {
  uint8_t pos;
  uint8_t drl;
  uint8_t loBeam;
  uint8_t hiBeam;
  uint8_t turnLeft;
  uint8_t turnRight;
} SW_STATE_t;

// 初始化函數
// extern const SWITCH_GROUP_t sw;
extern const SWITCHs_t sw;
extern void swState_update(void);

#endif // SWITCH_H
