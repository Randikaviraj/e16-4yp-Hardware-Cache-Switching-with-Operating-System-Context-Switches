#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include <unistd.h>

#define PC 0x00081030
#define INST 0x00081020
#define REG0 0x000810a0
#define REG1 0x00081090
#define REG2 0x00081080
#define REG3 0x00081070
#define REG4 0x00081060
#define REG5 0x00081050
#define REG6 0x00081040
#define OFFSET 0x00000000


static uint32_t pc;
static uint32_t ins;
static uint32_t reg0;
static uint32_t reg1;
static uint32_t reg2;
static uint32_t reg3;
static uint32_t reg4;
static uint32_t reg5;
static uint32_t reg6;


int main(void)
{


    /* 0x00-0xFF counting loop. */
    while( 1 )
    {
        usleep(100000); // Wait for about 0.1 seconds

        pc = IORD_32DIRECT(PC,OFFSET);
        ins = IORD_32DIRECT(INST,OFFSET);
        reg0 = IORD_32DIRECT(REG0,OFFSET);
        reg1 = IORD_32DIRECT(REG1,OFFSET);
        reg2 = IORD_32DIRECT(REG2,OFFSET);
        reg3 = IORD_32DIRECT(REG3,OFFSET);
        reg4 = IORD_32DIRECT(REG4,OFFSET);
        reg5 = IORD_32DIRECT(REG5,OFFSET);
        reg6 = IORD_32DIRECT(REG6,OFFSET);
        printf("PC [%d] INS [%d] reg0 [%d] reg1 [%d] reg2 [%d] reg3 [%d] reg4 [%d] reg5 [%d] reg6 [%d]\n",pc,ins,reg0,reg1,reg2,reg3,reg4,reg5,reg6);
        usleep(1000000); // If done counting, wait about 1 second...

    }

    return 0;
}
