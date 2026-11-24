# 1 "D:\\yiming\\00work\\FR685_TX_V03.X\\timer.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "D:\\yiming\\00work\\FR685_TX_V03.X\\timer.c" 2






# 1 "D:\\yiming\\00work\\FR685_TX_V03.X/timer.h" 1
# 12 "D:\\yiming\\00work\\FR685_TX_V03.X/timer.h"
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 1 3



# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/musl_xc8.h" 1 3
# 5 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 26 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 1 3
# 133 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef short intptr_t;
# 164 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 13 "D:\\yiming\\00work\\FR685_TX_V03.X/timer.h" 2


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
# 8 "D:\\yiming\\00work\\FR685_TX_V03.X\\timer.c" 2
# 1 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h" 1
# 55 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdbool.h" 1 3
# 56 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h" 2
# 103 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_Initialize(void);
# 132 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_StartTimer(void);
# 164 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_StopTimer(void);
# 199 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
uint8_t TMR2_ReadTimer(void);
# 238 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_WriteTimer(uint8_t timerVal);
# 290 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_LoadPeriodRegister(uint8_t periodVal);
# 308 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_ISR(void);
# 326 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
 void TMR2_SetInterruptHandler(void (* InterruptHandler)(void));
# 344 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
extern void (*TMR2_InterruptHandler)(void);
# 362 "D:\\yiming\\00work\\FR685_TX_V03.X/mcc_generated_files/tmr2.h"
void TMR2_DefaultInterruptHandler(void);
# 9 "D:\\yiming\\00work\\FR685_TX_V03.X\\timer.c" 2


static volatile uint8_t R_Cnt = 0U;
static volatile uint8_t L_Cnt = 0U;


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
