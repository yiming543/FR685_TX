#include "BOARD.h"
#include "LED.h"
#include "SWITCH.h"
#include "Warning_ignored.h"
#include <xc.h>
#include "timer.h"


extern uint8_t ID_01_Data[8];

#define ON (1U)
#define OFF (0U)
#define DATA_LENGTH (8U)

#define HI_BEAM_MASK ((uint8_t)0x80U)
#define MODE_POS_MASK ((uint8_t)0x01U)
#define MODE_DRL_MASK ((uint8_t)0x02U)
#define CONTROL_LOW_BEAM_MASK ((uint8_t)0x01U)
#define CONTROL_HIGH_BEAM_MASK ((uint8_t)0x02U)

#define MODE_OFF (0U)
#define MODE_POS (1U)
#define MODE_AUTO (2U)
#define MODE_LO_BEAM (3U)
#define MODE_COUNT (4U)

#define CONTROL_NIGHT_P (0U)
#define CONTROL_DAY_P (1U)
#define CONTROL_NIGHT_N (2U)
#define CONTROL_DAY_N (3U)
#define CONTROL_COUNT (4U)

static uint8_t mode = MODE_OFF;
static uint8_t controlMode = CONTROL_NIGHT_P;
static uint8_t ledOff = OFF;
static uint8_t hiBeam = OFF;
static uint8_t linData[DATA_LENGTH];

uint16_t Rcount;
uint16_t Lcount;

static const uint8_t ledOffData[DATA_LENGTH] = {
    0x31U, 0x08U, 0x34U, 0x00U, 0x04U, 0xB0U, 0x87U, 0xBEU};

/* controlMode order: NIGHT_P, DAY_P, NIGHT_N, DAY_N. */
static const uint8_t
    linDataTable[MODE_COUNT][CONTROL_COUNT][DATA_LENGTH] = {
        /* MODE_OFF */
        {{0x24U, 0x08U, 0x31U, 0x00U, 0x04U, 0xB0U, 0x88U, 0xBEU},
         {0x24U, 0x08U, 0x29U, 0x00U, 0x04U, 0xB0U, 0xA3U, 0xBEU},
         {0x24U, 0x08U, 0x71U, 0x00U, 0x07U, 0xB0U, 0x88U, 0xBEU},
         {0x24U, 0x08U, 0x69U, 0x00U, 0x04U, 0xB0U, 0x99U, 0xBEU}},
        /* MODE_POS */
        {{0x24U, 0x08U, 0x32U, 0x00U, 0x07U, 0xB0U, 0x88U, 0xBEU},
         {0x24U, 0x08U, 0x2AU, 0x00U, 0x07U, 0xB0U, 0xA2U, 0xBEU},
         {0x24U, 0x08U, 0x72U, 0x00U, 0x07U, 0xB0U, 0x88U, 0xBFU},
         {0x24U, 0x08U, 0x6AU, 0x00U, 0x07U, 0xB0U, 0xA3U, 0xBEU}},
        /* MODE_AUTO */
        {{0x24U, 0x08U, 0xB4U, 0x00U, 0x0FU, 0xB0U, 0x74U, 0xBEU},
         {0x24U, 0x08U, 0x2CU, 0x00U, 0x04U, 0xB0U, 0x8CU, 0xBEU},
         {0x24U, 0x08U, 0xB4U, 0x00U, 0x0FU, 0xB0U, 0x74U, 0xBEU},
         {0x24U, 0x08U, 0x6CU, 0x00U, 0x04U, 0xB0U, 0x9EU, 0xBEU}},
        /* MODE_LO_BEAM */
        {{0x24U, 0x08U, 0x33U, 0x00U, 0x0FU, 0xB0U, 0x88U, 0xBEU},
         {0x24U, 0x08U, 0x2BU, 0x00U, 0x0FU, 0xB0U, 0x99U, 0xBEU},
         {0x24U, 0x08U, 0x33U, 0x00U, 0x0FU, 0xB0U, 0x88U, 0xBEU},
         {0x24U, 0x08U, 0x2BU, 0x00U, 0x0FU, 0xB0U, 0x99U, 0xBEU}}};

static void PublishLinData(const uint8_t *sourceData) {
  uint8_t index;
  uint8_t globalInterruptWasEnabled;

  globalInterruptWasEnabled = INTCONbits.GIE;
  INTCONbits.GIE = 0;
  for (index = 0U; index < DATA_LENGTH; ++index) {
    ID_01_Data[index] = sourceData[index];
  }
  INTCONbits.GIE = globalInterruptWasEnabled;
}

void board_init(void) {
  LED_Init();
  Clear_No_Call_Warning();
  swState_update();
  TMR2_init();
}

void swSetModeControl(void) {
  mode = MODE_OFF;
  controlMode = CONTROL_NIGHT_P;

  if (sw.pos.is_on() == ON) {
    mode |= MODE_POS_MASK;
  }

  if (sw.drl.is_on() == ON) {
    mode |= MODE_DRL_MASK;
  }

  if (sw.loBeam.is_on() == ON) {
    controlMode |= CONTROL_LOW_BEAM_MASK;
  }

  if (sw.hiBeam.is_on() == ON) {
    controlMode |= CONTROL_HIGH_BEAM_MASK;
  }

  ledOff = sw.turnLeft.is_on();
  hiBeam = sw.turnRight.is_on();
}

void swSetLED(void) {
  if (sw.pos.is_on() == ON) {
    led.pos.on();
  } else {
    led.pos.off();
  }

  if (sw.drl.is_on() == ON) {
    led.drl.on();
  } else {
    led.drl.off();
  }

  if (sw.loBeam.is_on() == ON) {
    led.loBeam.on();
  } else {
    led.loBeam.off();
  }

  if (sw.hiBeam.is_on() == ON) {
    led.hiBeam.on();
  } else {
    led.hiBeam.off();
  }

  if (sw.turnLeft.is_on() == ON) {
    led.turnLeft.on();
  } else {
    led.turnLeft.off();
  }

  if (sw.turnRight.is_on() == ON) {
    led.turnRight.on();
  } else {
    led.turnRight.off();
  }

  if (tmr2.R_CNT.get() > 0U) {
    led.turnLeftResponse.on();
  } else {
    led.turnLeftResponse.off();
  }

  if (tmr2.L_CNT.get() > 0U) {
    led.turnRightResponse.on();
  } else {
    led.turnRightResponse.off();
  }
}

void swSetDATA(void) {
  uint8_t index;
  const uint8_t *selectedData;

  if (ledOff == ON) {
    selectedData = ledOffData;
  } else if ((mode < MODE_COUNT) && (controlMode < CONTROL_COUNT)) {
    selectedData = linDataTable[mode][controlMode];
  } else {
    /* Deterministic fallback: OFF / NIGHT / P. */
    selectedData = linDataTable[MODE_OFF][CONTROL_NIGHT_P];
  }

  for (index = 0U; index < DATA_LENGTH; ++index) {
    linData[index] = selectedData[index];
  }

  if (ledOff != ON) {
    if (hiBeam == ON) {
      linData[1] = (uint8_t)(linData[1] | HI_BEAM_MASK);
    } else {
      linData[1] =
          (uint8_t)(linData[1] & (uint8_t)(~HI_BEAM_MASK));
    }
  }

  PublishLinData(linData);
}

void board_update(void) {
    swState_update();
    swSetModeControl();
    swSetDATA();
    swSetLED();
}
