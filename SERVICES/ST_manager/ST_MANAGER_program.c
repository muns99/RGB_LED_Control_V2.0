#include "../../LIB/std_types.h"
#include "../../MCAL/systick/SYSTICK_interface.h"
#include "ST_MANAGER_interface.h"
str_sysTickTask_t str_gl_tasks[TASKS_COUNT]= {0};
void ST_MANAGER_manageTasks()
{
    for (uint8_t uint8_a_tasksIterator = 0; uint8_a_tasksIterator < TASKS_COUNT; uint8_a_tasksIterator++)
        {
            if(str_gl_tasks[uint8_a_tasksIterator].taskInterval != 0)
            {
                if (str_gl_tasks[uint8_a_tasksIterator].taskState == TASK_WAITING)
                {
                    str_gl_tasks[uint8_a_tasksIterator].taskRemaining--;
                    if (str_gl_tasks[uint8_a_tasksIterator].taskRemaining == 0)
                    {
                        str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_READY;
                    }
                }
            }
        }
}
void ST_MANAGER_dispatcher()
{
     for (uint8_t uint8_a_tasksIterator = 0; uint8_a_tasksIterator < TASKS_COUNT; uint8_a_tasksIterator++)
        {
            if(str_gl_tasks[uint8_a_tasksIterator].taskInterval != 0)
            {
                if (str_gl_tasks[uint8_a_tasksIterator].taskState == TASK_READY)
                {
                    str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_RUNNING;
                    if( str_gl_tasks[uint8_a_tasksIterator].ptr_func_taskHandler != NULL)
                    {
                        str_gl_tasks[uint8_a_tasksIterator].ptr_func_taskHandler();
                    }
                    str_gl_tasks[uint8_a_tasksIterator].taskRemaining = str_gl_tasks[uint8_a_tasksIterator].taskInterval;
                    if (str_gl_tasks[uint8_a_tasksIterator].taskPeriodicity == TASK_PERIODIC)
                    {
                        str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_WAITING;
                    }
                    else
                    {
                        str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_STOPED;
                    }
                    
                }
            }
        }

}
enu_systickManagerErrorState_t ST_MANAGER_init()
{
    enu_systickManagerErrorState_t enu_a_functionRet = ST_MANAGER_SUCCESS;
   
        if ( SYSTICK_init() == SYSTICK_SSUCCESS)
        {
            if (SYSTICK_setTimerCallBack(ST_MANAGER_manageTasks) == SYSTICK_SSUCCESS)
            {
                if (SYSTICK_enableInterrupt() == SYSTICK_SSUCCESS)
                {
                    
                }
                else
                {
                    enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
                }
            }
             else
            {
                enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
            }
            
        }
        else
        {
            enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
        }
         

    return enu_a_functionRet;
}
enu_systickManagerErrorState_t ST_MANAGER_start()
{
    enu_systickManagerErrorState_t enu_a_functionRet = ST_MANAGER_SUCCESS;
    if (SYSTICK_start(SYSTICK_INTERVAL) == SYSTICK_SSUCCESS)
    {
        /*do nothing*/
    }
    else
    {
        enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
    }
    return enu_a_functionRet;

}
enu_systickManagerErrorState_t ST_MANAGER_stop()
{
    enu_systickManagerErrorState_t enu_a_functionRet = ST_MANAGER_SUCCESS;
    if (SYSTICK_stop() == SYSTICK_SSUCCESS)
    {
        /*do nothing*/
    }
    else
    {
        enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
    }
    return enu_a_functionRet;
}
enu_systickManagerErrorState_t ST_MANAGER_createTask(str_sysTickTask_t *str_a_task)
{
    enu_systickManagerErrorState_t enu_a_functionRet = ST_MANAGER_SUCCESS;
    if (str_a_task != NULL)
    {
        for (uint8_t uint8_a_tasksIterator = 0; uint8_a_tasksIterator < TASKS_COUNT; uint8_a_tasksIterator++)
        {
            if(str_gl_tasks[uint8_a_tasksIterator].taskInterval == 0)
            {
                str_gl_tasks[uint8_a_tasksIterator] = *str_a_task;
                str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_STOPED;
                str_gl_tasks[uint8_a_tasksIterator].taskRemaining = str_gl_tasks[uint8_a_tasksIterator].taskInterval;
                enu_a_functionRet = ST_MANAGER_SUCCESS;
                break;
            }
            else
            {
                enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
            }
        }
        
    }
    else
    {
        enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
    }
    return enu_a_functionRet;
    

}
enu_systickManagerErrorState_t ST_MANAGER_reStartTask(uint8_t uint8_a_taskID)
{
    enu_systickManagerErrorState_t enu_a_functionRet = ST_MANAGER_SUCCESS;
    for (uint8_t uint8_a_tasksIterator = 0; uint8_a_tasksIterator < TASKS_COUNT; uint8_a_tasksIterator++)
    {
        if(str_gl_tasks[uint8_a_tasksIterator].taskId == uint8_a_taskID)
        {
            str_gl_tasks[uint8_a_tasksIterator].taskState = TASK_WAITING;
            enu_a_functionRet = ST_MANAGER_SUCCESS;
            break;
        }
        else
        {
            enu_a_functionRet = ST_MANAGER_NOT_SUCCESS;
        }
    }
        return enu_a_functionRet;
}
enu_systickManagerErrorState_t ST_MANAGER_deleteTask(uint8_t uint8_a_taskID)
{

}

enu_systickManagerErrorState_t ST_MANAGER_modifyTask(uint8_t uint8_a_taskID,str_sysTickTask_t *str_a_task)
{

}