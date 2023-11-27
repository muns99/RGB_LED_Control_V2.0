#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
typedef enum __systickErrorState
{
    SYSTICK_SSUCCESS    = 0 ,
    SYSTICK_NOT_SSUCCESS    ,
    SYSTICK_INVALID_ARGS    
}enu_systickErrorState_t;
enu_systickErrorState_t SYSTICK_init();
enu_systickErrorState_t SYSTICK_setTimer(uint16_t   uint16_a_millies);
enu_systickErrorState_t SYSTICK_enableInterrupt();
enu_systickErrorState_t SYSTICK_disableInterrupt();
enu_systickErrorState_t SYSTICK_start();
enu_systickErrorState_t SYSTICK_stop();
#endif // !SYSTICK_INTERFACE_H_