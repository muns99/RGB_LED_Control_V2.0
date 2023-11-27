#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
enu_systickErrorState_t SYSTICK_init()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    #ifdef SYSTEM_CLOCK
    SET_BIT(STCTRL,STCTRL_CLK_SRC);
    #endif // SYSTEM_CLOCK
    #ifdef PIOSC
    CLR_BIT(STCTRL,STCTRL_CLK_SRC);
    #endif // PIOSC
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_setTimer(uint16_t uint16_a_millies)
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (uint16_a_millies <= MAX_TIME_INTERVAL)
    {
        STRELOAD &= ZERO_MASK;
        STRELOAD |= CALC_RELOAD(uint16_a_millies);
    }
    else
    {
        enu_a_functionRet = SYSTICK_INVALID_ARGS;
    }
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_enableInterrupt()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (GET_BIT(STCTRL,STCTRL_INTEN) == ZERO_MASK)
    {
        SET_BIT(STCTRL,STCTRL_INTEN);
    }
    else
    {
        enu_a_functionRet = SYSTICK_NOT_SSUCCESS;
    }
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_disableInterrupt()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (GET_BIT(STCTRL,STCTRL_INTEN) != ZERO_MASK)
    {
        CLR_BIT(STCTRL,STCTRL_INTEN);
    }
    else
    {
        enu_a_functionRet = SYSTICK_NOT_SSUCCESS;
    }
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_start()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (GET_BIT(STCTRL,STCTRL_ENABLE) == ZERO_MASK)
    {
        SET_BIT(STCTRL,STCTRL_ENABLE);
    }
    else
    {
        enu_a_functionRet = SYSTICK_NOT_SSUCCESS;
    }
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_stop()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (GET_BIT(STCTRL,STCTRL_ENABLE) != ZERO_MASK)
    {
        CLR_BIT(STCTRL,STCTRL_ENABLE);
    }
    else
    {
        enu_a_functionRet = SYSTICK_NOT_SSUCCESS;
    }
    return enu_a_functionRet;
}