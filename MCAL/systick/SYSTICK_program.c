#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "TM4C123.h"
#include "core_cm4.h" 
void(*prt_func_gl_sysTickHandler)(void) = NULL;
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
enu_systickErrorState_t SYSTICK_setTimerCallBack(void(*ptr_func_a_sysTickHandler)(void))
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
   
			if (ptr_func_a_sysTickHandler != NULL)
			{
					
					prt_func_gl_sysTickHandler = ptr_func_a_sysTickHandler;
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
        NVIC_EnableIRQ(SysTick_IRQn);
        __enable_irq();
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
enu_systickErrorState_t SYSTICK_start(uint16_t uint16_a_millies)
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    SET_BIT(STCTRL,STCTRL_ENABLE);
	STRELOAD &= ZERO_MASK;
    STRELOAD = CALC_RELOAD(uint16_a_millies);//CALC_RELOAD(uint16_a_millies);
   
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_stop()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    if (GET_BIT(STCTRL,STCTRL_ENABLE) != ZERO_MASK)
    {
        CLR_BIT(STCTRL,STCTRL_ENABLE);
        STRELOAD = ZERO_MASK;
    }
    else
    {
        enu_a_functionRet = SYSTICK_NOT_SSUCCESS;
    }
    return enu_a_functionRet;
}
enu_systickErrorState_t SYSTICK_deInit()
{
    enu_systickErrorState_t enu_a_functionRet = SYSTICK_SSUCCESS;
    SET_BIT(STCTRL,STCTRL_CLK_SRC);
    CLR_BIT(STCTRL,STCTRL_ENABLE);
    CLR_BIT(STCTRL,STCTRL_COUNT);
    CLR_BIT(STCTRL,STCTRL_INTEN);
    prt_func_gl_sysTickHandler = NULL;
    return enu_a_functionRet;
}
void SysTick_Handler()
{
    if (prt_func_gl_sysTickHandler != NULL)
    {
        prt_func_gl_sysTickHandler();
    }
    else
    {
        /*do nothing*/
    }
    
}