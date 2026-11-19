#include "SWITCH.h"

#include "mcc_generated_files/pin_manager.h"
extern void swSetModeControl(void);
// 1. 定義私有開關索引，方便統一管理狀態陣列
// typedef enum {
//   POS = 0U,
//   DRL,
//   LO_BEAM,
//   HI_BEAM,
//   TURN_LEFT,
//   TURN_RIGHT,
//   LED_COUNT,
// } Led_t;

#define ON (1U)
#define OFF (0U)

// 2. 【真正的 Private 狀態變數】僅佔用 6 Bytes RAM，外部完全無法直接修改
static SW_STATE_t sw_states = {
    .pos = OFF,
    .drl = OFF,
    .loBeam = OFF,
    .hiBeam = OFF,
    .turnLeft = OFF,
    .turnRight = OFF};

// 3. 內部硬體操作函式（加上 static 隱藏於此檔案內部）
static uint8_t
SW_POS_GET(void) {
  // return (uint8_t)(!!(SW1_GetValue() == OFF));
  return (uint8_t)(!!(SW1_GetValue() == OFF));
}

static uint8_t SW_DRL_GET(void) {
  return (uint8_t)(!!(SW2_GetValue() == OFF));
}

static uint8_t SW_LO_BEAM_GET(void) {
  return (uint8_t)(!!(SW3_GetValue() == OFF));
}

static uint8_t SW_HI_BEAM_GET(void) {
  return (uint8_t)(!!(SW4_GetValue() == OFF));
}

static uint8_t SW_TURN_LEFT_GET(void) {
  return (uint8_t)(!!(SW5_GetValue() == OFF));
}

static uint8_t SW_TURN_RIGHT_GET(void) {
  return (uint8_t)(!!(SW6_GetValue() == OFF));
}

static uint8_t SW_POS_IS_ON(void) {
  return sw_states.pos;
}

static uint8_t SW_DRL_IS_ON(void) {
  return sw_states.drl;
}

static uint8_t SW_LO_BEAM_IS_ON(void) {
  return sw_states.loBeam;
}

static uint8_t SW_HI_BEAM_IS_ON(void) {
  return sw_states.hiBeam;
}

static uint8_t SW_TURN_LEFT_IS_ON(void) {
  return sw_states.turnLeft;
}

static uint8_t SW_TURN_RIGHT_IS_ON(void) {
  return sw_states.turnRight;
}

// 4. 編譯期靜態初始化物件（存放於 Flash 唯讀區）
const SWITCHs_t sw = {
    .pos = {.get = SW_POS_GET, .is_on = SW_POS_IS_ON},
    .drl = {.get = SW_DRL_GET, .is_on = SW_DRL_IS_ON},
    .loBeam = {.get = SW_LO_BEAM_GET, .is_on = SW_LO_BEAM_IS_ON},
    .hiBeam = {.get = SW_HI_BEAM_GET, .is_on = SW_HI_BEAM_IS_ON},
    .turnLeft = {.get = SW_TURN_LEFT_GET, .is_on = SW_TURN_LEFT_IS_ON},
    .turnRight = {.get = SW_TURN_RIGHT_GET, .is_on = SW_TURN_RIGHT_IS_ON}};

void swState_update(void) {
  sw_states.pos = sw.pos.get();
  sw_states.drl = sw.drl.get();
  sw_states.loBeam = sw.loBeam.get();
  sw_states.hiBeam = sw.hiBeam.get();
  sw_states.turnLeft = sw.turnLeft.get();
  sw_states.turnRight = sw.turnRight.get();
}