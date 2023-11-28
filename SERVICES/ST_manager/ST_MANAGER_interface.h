#ifndef ST_MANAGER_INTERFACE_H_
#define ST_MANAGER_INTERFACE_H_
#define SYSTICK_INTERVAL    1
#define TASKS_COUNT 10
typedef enum __systickManagerErrorState
{
    ST_MANAGER_SUCCESS  =   0 ,
    ST_MANAGER_NOT_SUCCESS    ,
    ST_INVALID_STATE     
}enu_systickManagerErrorState_t;
typedef enum __taskState
{
    TASK_READY      = 0 ,
    TASK_STOPED         ,
    TASK_RUNNING        
}enu_taskState_t;
typedef enum __taskPeriodicity
{
    TASK_ONE_SHOT   = 0,
    TASK_PERIODIC
}enu_taskPeriodicity_t;
typedef struct __sysTickTask
{
    uint16_t taskInterval;
    uint16_t taskRemening;
    uint8_t  taskId;
    enu_taskState_t taskState;
    enu_taskPeriodicity_t taskPeriodicity;
}str_sysTickTask_t;

enu_systickManagerErrorState_t ST_MANAGER_init();
enu_systickManagerErrorState_t ST_MANAGER_strat();
enu_systickManagerErrorState_t ST_MANAGER_stop();
enu_systickManagerErrorState_t ST_MANAGER_createTask(str_sysTickTAsk *str_a_task);
enu_systickManagerErrorState_t ST_MANAGER_deleteTask(uint8_t uint8_a_taskID);
enu_systickManagerErrorState_t ST_MANAGER_modifyTask(uint8_t uint8_a_taskID,str_sysTickTAsk *str_a_task);


#endif // !ST_MANAGER_INTERFACE_H_