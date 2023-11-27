#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#ifdef PIOSC
#define MAX_TIME_INTERVAL   4194.30375 //in millies
#endif // PIOSC

#ifdef SYSTEM_CLOCK
#define MAX_TIME_INTERVAL   335.30375 //in millies
#endif // SYSTEM_CLOCK

#define MAX_REGISTER_COUNT  16777215   //in ticks
#define (_MILLIES_)    (((_MILLIES_) * (MAX_REGISTER_COUNT)) / (MAX_TIME_INTERVAL) )
#define STCTRL          (*(volatile uint32_t *)(0xE000E010))
#define STRELOAD        (*(volatile uint32_t *)(0xE000E014))
#define STCURRENT       (*(volatile uint32_t *)(0xE000E018))
/**********STCTRL BITS ********/
#define STCTRL_COUNT        16
#define STCTRL_CLK_SRC      2
#define STCTRL_INTEN        1
#define STCTRL_ENABLE       0
/*****************************/
#define ZERO_MASK 0x0
#define BIT_LOW     0
#endif // !SYSTICK_PRIVATE_H_