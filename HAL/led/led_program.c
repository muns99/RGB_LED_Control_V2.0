#include "../../LIB/std_types.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/systick/SYSTICK_interface.h"
#include "led_interface.h"


enu_ledErrorState_t LED_init(st_led_t *st_a_led)
{
    enu_ledErrorState_t enu_a_functionRet = LED_SUCCESS;
    if (st_a_led != NULL)
    {  st_gpioPinConfig_t st_a_ledPin = 
         {
            .port =  st_a_led->ledPort,
            .pinNum = st_a_led->ledPin,
            .pinMode = DIGITAL_OUTPUT_2MA
         };        
        if (GPIO_initPin(&st_a_ledPin) != GPIO_SUCCESS)
        {
           enu_a_functionRet = LED_NOT_SUCCES;
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        enu_a_functionRet = LED_INVALID_STATE;
    }
    return enu_a_functionRet;
}
enu_ledErrorState_t LED_on(st_led_t *st_a_led)
{
    enu_ledErrorState_t enu_a_functionRet = LED_SUCCESS;
    if (st_a_led != NULL)
    {
        if (GPIO_setPinValue(st_a_led->ledPort,st_a_led->ledPin,GPIO_HIGH) != GPIO_SUCCESS)
        {
           enu_a_functionRet = LED_NOT_SUCCES;
        }
        else
        {
            /*do nothing*/
        }
        
        
    }
    else
    {
        enu_a_functionRet = LED_INVALID_STATE;
    }
    return enu_a_functionRet;
}

enu_ledErrorState_t LED_intervalOn(st_led_t *st_a_led,uint16_t uint16_a_interval)
{
    enu_ledErrorState_t enu_a_functionRet = LED_SUCCESS;
    if (st_a_led != NULL)
    {
        if ( SYSTICK_init() == SYSTICK_SSUCCESS)
        {
            if (SYSTICK_setTimer(uint16_a_interval,st_a_led->ptr_func_ledCallBack) == SYSTICK_SSUCCESS)
            {
                if (SYSTICK_enableInterrupt() == SYSTICK_SSUCCESS)
                {
                    if (SYSTICK_start() == SYSTICK_SSUCCESS)
                    {
                        LED_on(st_a_led);
                    }
                    else
                    {
                        enu_a_functionRet = LED_NOT_SUCCES;
                    }
                }
                else
                {
                    enu_a_functionRet = LED_NOT_SUCCES;
                }
            }
             else
            {
                enu_a_functionRet = LED_NOT_SUCCES;
            }
            
        }
        else
        {
            enu_a_functionRet = LED_NOT_SUCCES;
        }
         
    }
    else
    {
        enu_a_functionRet = LED_INVALID_STATE;
    }
    return enu_a_functionRet;
}


enu_ledErrorState_t LED_off(st_led_t *st_a_led)
{
     enu_ledErrorState_t enu_a_functionRet = LED_SUCCESS;
    if (st_a_led != NULL)
    {

        if (GPIO_setPinValue(st_a_led->ledPort,st_a_led->ledPin,GPIO_LOW) != GPIO_SUCCESS)
        {
           enu_a_functionRet = LED_NOT_SUCCES;
        }
        else
        {
            /*do nothing*/
        }
        
        
    }
    else
    {
        enu_a_functionRet = LED_INVALID_STATE;
    }
    return enu_a_functionRet;
}
enu_ledErrorState_t LED_toggle(st_led_t *st_a_led)
{
     enu_ledErrorState_t enu_a_functionRet = LED_SUCCESS;
    if (st_a_led != NULL)
    {
        if (GPIO_togglePin(&st_a_led->ledPort,st_a_led->ledPin) != GPIO_SUCCESS)
        {
           enu_a_functionRet = LED_NOT_SUCCES;
        }
        else
        {
            /*do nothing*/
        }
        
        
    }
    else
    {
        enu_a_functionRet = LED_INVALID_STATE;
    }
    return enu_a_functionRet;
}