# 1 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers\\lin_app.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers\\lin_app.c" 2
# 41 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers\\lin_app.c"
# 1 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_app.h" 1
# 41 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_app.h"
# 1 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_master.h" 1
# 42 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_master.h"
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
# 43 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_master.h" 2
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdbool.h" 1 3
# 44 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_master.h" 2


typedef enum {
    LIN_IDLE,
    LIN_TX_IP,
    LIN_RX_IP,
    LIN_RX_RDY
}lin_state_t;

typedef enum {
    TRANSMIT,
    RECEIVE
}lin_packet_type_t;

typedef struct {
    uint8_t cmd;
    lin_packet_type_t type;
    uint8_t length;
    uint8_t timeout;
    uint8_t period;
    uint8_t* data;
}lin_cmd_packet_t;

typedef union {
    struct {
        uint8_t PID;
        uint8_t data[8];
        uint8_t checksum;
        uint8_t length;
    };
    uint8_t rawPacket[11];
}lin_packet_t;

typedef union {
    struct {
        uint8_t cmd;
        uint8_t rxLength;
        uint8_t data[8];
        uint8_t checksum;
        uint8_t timeout;
    };
    uint8_t rawPacket[12];
}lin_rxpacket_t;

typedef union {
    struct {
        unsigned ID0: 1;
        unsigned ID1: 1;
        unsigned ID2: 1;
        unsigned ID3: 1;
        unsigned ID4: 1;
        unsigned ID5: 1;
        unsigned P0: 1;
        unsigned P1: 1;
    };
    uint8_t rawPID;
}lin_pid_t;



void LIN_init(uint8_t tableLength, const lin_cmd_packet_t* const table, void (*processData)(void));

void LIN_queuePacket(uint8_t cmd, uint8_t* data);

_Bool LIN_receivePacket(void);

void LIN_sendPacket(void);

uint8_t LIN_getPacket(uint8_t* data);

lin_state_t LIN_handler(void);

uint8_t LIN_getChecksum(uint8_t length, uint8_t pid, uint8_t* data);
uint8_t LIN_getChecksum_receive(uint8_t length, uint8_t pid, uint8_t* data);

uint8_t LIN_calcParity(uint8_t CMD);


void LIN_startTimer(uint8_t timeout);

void LIN_timerHandler(void);

void LIN_setTimerHandler(void);

void LIN_stopTimer(void);

void LIN_startPeriod(void);

void LIN_stopPeriod(void);

void LIN_enableRx(void);

void LIN_disableRx(void);

void LIN_sendBreak(void);

void LIN_sendPeriodicTx(void);
# 42 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers/lin_app.h" 2




typedef enum {
  ID_00 = 0x00,
  ID_10 = 0x10,
  ID_01 = 0x01,
  ID_18 = 0x18
} lin_cmd_t;

uint8_t ID_00_Data[8]={0x01, 0x08, 0x25, 0x80, 0x00, 0x9C, 0xFF, 0xFF};
uint8_t ID_10_Data[8];
uint8_t ID_01_Data[8];
uint8_t ID_18_Data[8];

lin_cmd_packet_t scheduleTable[] = {

    {ID_00, TRANSMIT, 8, 10, 20, ID_00_Data},
    {ID_10, RECEIVE, 8, 15, 20, ID_10_Data},
    {ID_01, TRANSMIT, 8, 10, 20, ID_01_Data},
    {ID_18, RECEIVE, 8, 15, 20, ID_18_Data}};


void LIN_Master_Initialize(void);

void processLIN(void);
# 42 "D:\\yiming\\00work\\FR685_TX_V02.X\\mcc_generated_files\\LINDrivers\\lin_app.c" 2

extern uint16_t Rcount;
extern uint16_t Lcount;

void LIN_Master_Initialize(void) {

  LIN_init((sizeof(scheduleTable) / sizeof(lin_cmd_packet_t)), scheduleTable, processLIN);
}

void processLIN(void) {
  uint8_t tempRxData[8];
  uint8_t cmd;

  cmd = LIN_getPacket(tempRxData);
  switch (cmd) {
  case ID_00:
    break;
  case ID_10:
    Lcount = 4000U;
    break;
  case ID_01:
    break;
  case ID_18:
    Rcount = 4000U;
    break;
  default:
    break;
  }
}
