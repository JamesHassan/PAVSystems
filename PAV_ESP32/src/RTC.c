/*
   @brief to utalise the inbuilt Real Time Clock (RTC) for control and operation, recording the time of events
   @author James Hassan 11991559
   @date 2019-03-29
*/
#include "RTC.h"


//Init
bool RTC_Init()
{
    //_DI();
    int RTCCntlReg = REG_READ (RTC_CNTL_CLK_CONF_REG);

    printf("Initial Reg: %d\n ",RTCCntlReg); //693633040
    // 0x29580010
    // 0b101001010110000000000000010000

    int temp = REG_GET_BIT (RTC_CNTL_CLK_CONF_REG,RTC_CNTL_SOC_CLK_SEL_M);

    printf("Value of the bit: %d\n ",temp); 
    // 134217728
    // 0x08000000
    // 0b1000000000000000000000000000
    
    int bitShifted = ((2 & 0x3) << 27);
    printf("Maunal Bit Shift: %d\n ",bitShifted);
    // 268435456
    // 0b10000000000000000000000000000
    bitShifted = ((RTC_CNTL_SOC_CLK_SEL_8M & RTC_CNTL_SOC_CLK_SEL_V) << RTC_CNTL_SOC_CLK_SEL_S);
    // bitShifted = RTC_CNTL_SOC_CLK_SEL_M & RTC_CNTL_SOC_CLK_SEL_8M;
    printf("Masked: %d\n ",bitShifted);

    RTCCntlReg &= ~RTC_CNTL_SOC_CLK_SEL_M;
    printf("Unmasked: %d\n ",RTCCntlReg);
    //559415312
    // 100001010110000000000000010000

    RTCCntlReg |= bitShifted;
    printf("Bits Set: %d\n ",RTCCntlReg);
    // 827850768
    // 110001010110000000000000010000

// Initial Reg: 693633040
    // 0b101001010110000000000000010000

//  Value of the bit: 134217728
    // 0b1000000000000000000000000000

//  Maunal Bit Shift: 268435456
    // 0b10000000000000000000000000000

//  Masked: 268435456
    // 0b10000000000000000000000000000
//  Unmasked: 559415312
    // 100001010110000000000000010000

//  Bits Set: 827850768
    // 110001010110000000000000010000

    
    // *(volatile uint32_t*)(RTC_CNTL_CLK_CONF_REG) &= ~RTC_CNTL_SOC_CLK_SEL_M;
    // *(volatile uint32_t*)(RTC_CNTL_CLK_CONF_REG) |= bitShifted;

    //REG_SET_BITS(RTC_CNTL_CLK_CONF_REG,RTC_CNTL_SOC_CLK_SEL_8M,RTC_CNTL_SOC_CLK_SEL_M);
    // // RTCCntlReg = REG_READ (RTC_CNTL_CLK_CONF_REG);
     
    // printf("%d\n ",RTCCntlReg);

    // 
    // /* RTC_CNTL_CK8M_DIV : R/W ;bitpos:[5:4] ;default: 2'b01 --> which is div 256, so leave it alone*/
    // RTC_CNTL_CK8M_DIV_M;
    // // Clk select
    // REG_SET_BITS(RTC_CNTL_CLK_CONF_REG,RTC_CNTL_SOC_CLK_SEL_8M,RTC_CNTL_SOC_CLK_SEL_M);
    
    // int val = RTC_CNTL_SOC_CLK_SEL_M | RTC_CNTL_SOC_CLK_SEL_8M;
    // *RTC_CNTL_CLK_CONF_REG |= val;
    // // Clear interupt
    // RTC_CNTL_MAIN_TIMER_INT_CLR;
    // // Enable interupt
    // RTC_CNTL_MAIN_TIMER_INT_ENA;
    // // Interupt state
    // RTC_CNTL_MAIN_TIMER_INT_ST;
    // // Time update
    // RTC_CNTL_TIME_UPDATE;
    // // Set to clear the interupt
    // RTC_CNTL_MAIN_TIMER_INT_CLR;
    return true;

}

//Set
void RTC_Set(const uint8_t hours, const uint8_t minutes, const uint8_t seconds)
{
    // RTC value reg
    //((hours*3600)+(minutes*60)+seconds);

}

//Get
void RTC_Get(uint8_t* const hours, uint8_t* const  minutes, uint8_t* const  seconds)
{
    uint64_t temptime = 0;      // RTC value reg
    //obtain hours component of the time
    *hours = (temptime/3600)%24;
    //temptime%3600 represents the minutes and seconds
    temptime = temptime%3600;
    //obtain minutes component of the time
    *minutes = temptime/60;
    //temptime%60 represents the seconds of the time
    temptime = temptime%60;
    //obtain seconds component of the time
    *seconds = temptime;

}

//ISR