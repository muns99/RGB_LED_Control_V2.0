#include "../LIB/std_types.h"
#include "../HAL/button/button_interface.h"
#include "../HAL/led/led_interface.h"
#include "app_interface.h"
#include "app_config.h"
uint8_t uint8_gl_appSequenceCounter = 0;
void debounce()
{
    for (uint16_t i = 0 ; i < 10000 ; i++)
        for(uint16_t j = 0 ; j < 100 ; j++)
            for (uint16_t k = 0 ; k < 2 ; k++);
}
void APP_firstPress(void)
{
    LED_intervalStart(&st_g_redLed,1000);
}
void APP_secondPress(void)
{
    LED_off(&st_g_redLed);
    LED_intervalStart(&st_g_greenLed,1000);
}
void APP_thirdPress(void)
{
    LED_off(&st_g_greenLed);
    LED_intervalStart(&st_g_blueLed,1000);
}
void APP_fourthPress(void)
{
    LED_intervalStart(&st_g_blueLed,1000);
    LED_intervalStart(&st_g_greenLed,1000);
    LED_intervalStart(&st_g_redLed,1000);
}
void APP_fifthPress(void)
{
    LED_intervalStop(&st_g_redLed);
    LED_intervalStop(&st_g_greenLed);
    LED_intervalStop(&st_g_blueLed);
    LED_off(&st_g_redLed);
    LED_off(&st_g_greenLed);
    LED_off(&st_g_blueLed);
}
void APP_redLedRoutine()
{
    LED_intervalStop(&st_g_redLed);
}
void APP_greenLedRoutine()
{
    LED_intervalStop(&st_g_greenLed);
}
void APP_blueLedRoutine()
{
    LED_intervalStop(&st_g_blueLed);
}
void (*ptr_func_appSequenceFunctions[])(void) = {APP_firstPress,APP_secondPress,APP_thirdPress,APP_fourthPress,APP_fifthPress};
void APP_sequence(void)
{
    if (uint8_gl_appSequenceCounter < 5)
    {
        ptr_func_appSequenceFunctions[uint8_gl_appSequenceCounter++]();
    }
    else
    {
        uint8_gl_appSequenceCounter = 0;
    }
    debounce();
}
enu_appErrorState_t APP_init()
{
    enu_appErrorState_t enu_a_functionRet = APP_SUCCESS;
    if (LED_init(&st_g_redLed) == LED_SUCCESS)
    {
        if (LED_init(&st_g_blueLed) == LED_SUCCESS)
        {
            if (LED_init(&st_g_greenLed) == LED_SUCCESS)
            {
                if (BUTTON_init(&st_g_sw1) == BUTTON_SUCCESS)
                {
                    /* do nothing */
                }
                else
                {
                    enu_a_functionRet = APP_NOT_SUCCESS;
                }
                
            }
            else
            {
                enu_a_functionRet = APP_NOT_SUCCESS;
            }
        }
        else
        {
            enu_a_functionRet = APP_NOT_SUCCESS;
        }
        
    }
    else
    {
        enu_a_functionRet = APP_NOT_SUCCESS;
    }
    return enu_a_functionRet;
}
enu_appErrorState_t APP_start()
{
    enu_appErrorState_t enu_a_functionRet = APP_SUCCESS;
    if (BUTTON_enable(&st_g_sw1) == BUTTON_SUCCESS)
    {
        /* do nothing */
    }
    else
    {
        enu_a_functionRet = APP_NOT_SUCCESS;
    }
    return enu_a_functionRet;
}
enu_appErrorState_t APP_stop()
{
    enu_appErrorState_t enu_a_functionRet = APP_SUCCESS;
    uint8_t state ;
    if (BUTTON_disable(&st_g_sw1) == BUTTON_SUCCESS)
    {
        /*do nothing*/
    }
    else
    {
        enu_a_functionRet = APP_NOT_SUCCESS;
    }
    return enu_a_functionRet;
}


