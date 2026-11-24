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

// 20260916 FR685_TX_V01 CS:8C9D
// 重新量測ford F150-XLT信號
// mode:
// 00:off
// 01:park
// 02:auto
// 03:lobeam
// control:
// 00:night P
// 01:night N
// 02:day P
// 03:day N
// led off:1-off 0-on
// hibeam 1:on 0-off
// NO.	B0	B1	B2	B3	B4	B5	B6	B7	mode	  DAY/night	N/P	近燈	晝行(大亮)	行車=晝行(小亮)
// 1	  24	08	31	00	04	B0	88	BE	OFF	    NIGHT	    P
// 2	  24	08	71	00	07	B0	88	BE	OFF	    NIGHT	    N		      DRL
// 3	  24	08	29	00	04	B0	A3	BE	OFF	    DAY	      P
// 4	  24	08	69	00	04	B0	99	BE	OFF	    DAY	      N		      DRL
// 5	  24	08	32	00	07	B0	88	BE	POS	    NIGHT	    P		                  POS
// 6	  24	08	72	00	07	B0	88	BE	POS	    NIGHT	    N		      DRL
// 7	  24	08	2A	00	07	B0	A2	BE	POS	    DAY	      P		                  POS
// 8	  24	08	6A	00	07	B0	A3	BE	POS	    DAY	      N		      DRL
// 9	  24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    P	  近燈	            POS
// 10	24	08	B4	00	0F	B0	74	BE	AUTO	  NIGHT	    N	  近燈	            POS
// 11	24	08	2C	00	04	B0	8C	BE	AUTO	  DAY	      P
// 12	24	08	6C	00	04	B0	9E	BE	AUTO	  DAY	      N		      DRL
// 13	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    P	  近燈	            POS
// 14	24	08	33	00	0F	B0	88	BE	LOBEAM	NIGHT	    N	  近燈	            POS
// 15	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      P	  近燈	            POS
// 16	24	08	2B	00	0F	B0	99	BE	LOBEAM	DAY	      N	  近燈	            POS
// 17	11	09	34	00	07	90	B3	BE	unlock
// 18	01	08	34	00	04	90	B3	3E	lock
// 19	31	08	34	00	04	B0	87	BE	LED OFF

// 20261118 FR685_TX_V02 CS:047F
// 使用MCC LIN TX，收到裝置回饋信號亮LED燈。
// MISRA 2012:MCC 有64個警告

// 20261124 FR685_TX_V03 CS:8366
// ID=00[1] & ID=01[1]需相同，否則hiBeam會閃爍.
// OFF模式，SW3,4 模擬門信號
// MISRA 2012:MCC 有64個警告

#include "BOARD.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

int main(void) {
  // initialize the device
  SYSTEM_Initialize();
  board_init();

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();
  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  lin_state_t tmp_state;
  while (1) {
    // Add your application code
    CLRWDT();
    tmp_state = LIN_handler();
    board_update();
  }
}
/**
 End of File
*/