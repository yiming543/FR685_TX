/*
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules
  selected in the GUI. Generation Information : Product Revision  :  PIC10 /
  PIC12 / PIC16 / PIC18 MCUs - 1.81.8 Device            :  PIC16F1936 Driver
  Version    :  2.00
*/

//20260916 FR685_TX_V01 CS:8C9D
//重新量測ford F150-XLT信號
//mode:
//00:off
//01:park
//02:auto
//03:lobeam
//control:
//00:night P
//01:night N
//02:day P
//03:day N
//led off:1-off 0-on
//hibeam 1:on 0-off
//NO.	B0	B1	B2	B3	B4	B5	B6	B7	mode	  DAY/night	N/P	近燈	晝行(大亮)	行車=晝行(小亮)
//1	  24	08	31	00	04	B0	88	BE	OFF	    NIGHT	    P		
//2	  24	08	71	00	07	B0	88	BE	OFF	    NIGHT	    N		      DRL
//3	  24	08	29	00	04	B0	A3	BE	OFF	    DAY	      P		      
//4	  24	08	69	00	04	B0	99	BE	OFF	    DAY	      N		      DRL
//5	  24	08	32	00	07	B0	88	BE	POS	    NIGHT	    P		                  POS
//6	  24	08	72	00	07	B0	88	BE	POS	    NIGHT	    N		      DRL
//7	  24	08	2A	00	07	B0	A2	BE	POS	    DAY	      P		                  POS
//8	  24	08	6A	00	07	B0	A3	BE	POS	    DAY	      N		      DRL
//9	  24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    P	  近燈	            POS
//10	24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    N	  近燈	            POS
//11	24	08	2C	00	04	B0	8C	BE	AUTO	  DAY	      P		
//12	24	08	6C	00	04	B0	9E	BE	AUTO	  DAY	      N		      DRL
//13	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    P	  近燈	            POS
//14	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    N	  近燈	            POS
//15	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      P	  近燈	            POS
//16	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      N	  近燈	            POS
//17	11	09	34	00	07	90	B3	BE	unlock					
//18	01	08	34	00	04	90	B3	3E	lock					
//19	31	08	34	00	04	B0	87	BE	LED OFF					


#include "mcc_generated_files/mcc.h"

#define ON 0
#define OFF 1

#define SW1_ON() (SW1_GetValue() == ON)
#define SW2_ON() (SW2_GetValue() == ON)
#define SW3_ON() (SW3_GetValue() == ON)
#define SW4_ON() (SW4_GetValue() == ON)
#define SW5_ON() (SW5_GetValue() == ON)
#define SW6_ON() (SW6_GetValue() == ON)

#define LED1_ON() LED1_SetHigh()
#define LED1_OFF() LED1_SetLow()
#define LED2_ON() LED2_SetHigh()
#define LED2_OFF() LED2_SetLow()
#define LED3_ON() LED3_SetHigh()
#define LED3_OFF() LED3_SetLow()
#define LED4_ON() LED4_SetHigh()
#define LED4_OFF() LED4_SetLow()
#define LED5_ON() LED5_SetHigh()
#define LED5_OFF() LED5_SetLow()
#define LED6_ON() LED6_SetHigh()
#define LED6_OFF() LED6_SetLow()

typedef union {
  struct {
    unsigned SW1 : 1;
    unsigned SW2 : 1;
    unsigned SW3 : 1;
    unsigned SW4 : 1;
    unsigned SW5 : 1;
    unsigned SW6 : 1;
    unsigned bit6 : 1;
    unsigned bit7 : 1;
  };
  struct {
    unsigned mode : 2;
    unsigned control : 2;
    unsigned led_off : 1;
    unsigned hibeam : 1;
    unsigned unused : 2;
  };
  uint8_t Byte;
} sflag;

#define mode_off 0
#define mode_parking 1
#define mode_auto 2
#define mode_lobeam 3
#define control_night_P 0
#define control_night_N 2
#define control_day_P 1
#define control_day_N 3

sflag fKey;
/*
                         Main application
 */

// 消除未呼叫警告 假裝有使用這些函數
void Clear_No_Call_Warning(void) {
  uint8_t i = 0;
  if (i == 1) {
    TMR0_Reload();
    TMR0_ReadTimer();
  } else if (i == 2) {
    PIN_MANAGER_IOC();
  } else if (i == 3) {
    EUSART_get_last_status();
    EUSART_is_tx_done();
    EUSART_is_tx_ready();
  } else if (i == 4) {
    LIN_stopPeriod();
  } else if (i == 5) {
    PIN_MANAGER_IOC();
  }
}

void CheckSwitch(void) {
  if (SW1_ON()) {
    fKey.SW1 = 1;
    LED1_ON();
  } else {
    fKey.SW1 = 0;
    LED1_OFF();
  }
  if (SW2_ON()) {
    fKey.SW2 = 1;
    LED2_ON();
  } else {
    fKey.SW2 = 0;
    LED2_OFF();
  }
  if (SW3_ON()) {
    fKey.SW3 = 1;
    LED3_ON();
  } else {
    fKey.SW3 = 0;
    LED3_OFF();
  }
  if (SW4_ON()) {
    fKey.SW4 = 1;
    LED4_ON();
  } else {
    fKey.SW4 = 0;
    LED4_OFF();
  }
  if (SW5_ON()) {
    fKey.SW5 = 1;
    LED5_ON();
  } else {
    fKey.SW5 = 0;
    LED5_OFF();
  }
  if (SW6_ON()) {
    fKey.SW6 = 1;
    LED6_ON();
  } else {
    fKey.SW6 = 0;
    LED6_OFF();
  }

  if (fKey.led_off == 1) {
  //19	31	08	34	00	04	B0	87	BE	LED OFF	
    SW_STATE_Data[0] = 0x31;
    SW_STATE_Data[1] = 0x08;
    SW_STATE_Data[2] = 0x34;
    SW_STATE_Data[3] = 0x00;
    SW_STATE_Data[4] = 0x04;
    SW_STATE_Data[5] = 0xB0;
    SW_STATE_Data[6] = 0x87;
    SW_STATE_Data[7] = 0xBE;
  } else {
    if ((fKey.mode == mode_off) && (fKey.control == control_night_P)) {
      ///1	  24	08	31	00	04	B0	88	BE	OFF	    NIGHT	    P		
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x31;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x04;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_off) && (fKey.control == control_night_N)) {
      //2	  24	08	71	00	07	B0	88	BE	OFF	    NIGHT	    N		      DRL
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x71;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x07;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_off) && (fKey.control == control_day_P)) {
      ///3	  24	08	29	00	04	B0	A3	BE	OFF	    DAY	      P		  
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x29;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x04;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0xA3;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_off) && (fKey.control == control_day_N)) {
      //4	  24	08	69	00	04	B0	99	BE	OFF	    DAY	      N		      DRL
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x69;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x04;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x99;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_parking) &&
               (fKey.control == control_night_P)) {
      //5	  24	08	32	00	07	B0	88	BE	POS	    NIGHT	    P		                  POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x32;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x07;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_parking) &&
               (fKey.control == control_night_N)) {
      //6	  24	08	72	00	07	B0	88	BE	POS	    NIGHT	    N		      DRL
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x72;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x07;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBF;
    } else if ((fKey.mode == mode_parking) && (fKey.control == control_day_P)) {
      //7	  24	08	2A	00	07	B0	A2	BE	POS	    DAY	      P		                  POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x2A;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x07;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0xA2;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_parking) && (fKey.control == control_day_N)) {
      //8	  24	08	6A	00	07	B0	A3	BE	POS	    DAY	      N		      DRL
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x6A;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x07;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0xA3;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_auto) && (fKey.control == control_night_P)) {
      //9	  24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    P	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0xB4;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x74;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_auto) && (fKey.control == control_night_N)) {
      //10	24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    N	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0xB4;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x74;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_auto) && (fKey.control == control_day_P)) {
      //11	24	08	2C	00	04	B0	8C	BE	AUTO	  DAY	      P		
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x2C;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x04;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x8C;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_auto) && (fKey.control == control_day_N)) {
      //12	24	08	6C	00	04	B0	9E	BE	AUTO	  DAY	      N		      DRL      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x6C;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x04;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x9E;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_lobeam) &&
               (fKey.control == control_night_P)) {
      //13	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    P	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x33;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_lobeam) &&
               (fKey.control == control_night_N)) {
      //14	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    N	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x33;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x88;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_lobeam) && (fKey.control == control_day_P)) {
      //15	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      P	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x2B;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x99;
      SW_STATE_Data[7] = 0xBE;
    } else if ((fKey.mode == mode_lobeam) && (fKey.control == control_day_N)) {
      //16	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      N	  近燈	            POS
      SW_STATE_Data[0] = 0x24;
      SW_STATE_Data[1] = 0x08;
      SW_STATE_Data[2] = 0x2B;
      SW_STATE_Data[3] = 0x00;
      SW_STATE_Data[4] = 0x0F;
      SW_STATE_Data[5] = 0xB0;
      SW_STATE_Data[6] = 0x99;
      SW_STATE_Data[7] = 0xBE;
    }

    if(fKey.hibeam) 
      SW_STATE_Data[1] |= 0x80;
    else
      SW_STATE_Data[1] &= ~0x80;
  }
}

int main(void) {
  // initialize the device
  SYSTEM_Initialize();

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();
  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  Clear_No_Call_Warning();
  fKey.Byte = 0;
  while (1) {
    // Add your application code
    LIN_handler();
    INTCONbits.TMR0IE = 0;
    CheckSwitch();
    INTCONbits.TMR0IE = 1;
  }
}
/**
 End of File
*/