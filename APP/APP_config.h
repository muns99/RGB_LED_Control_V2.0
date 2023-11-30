#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_ 
void APP_redLedRoutine();
void APP_greenLedRoutine();
void APP_blueLedRoutine();
void APP_sequence(void);
#define LED_ON_INTERVAL     1000
#define TASK_1_ID           0
#define TASK_2_ID           1
#define TASK_3_ID           2
#define TASK_4_ID           3
#define APP_SEQUENCE_COUNT  5
st_button_t st_g_sw1 = {
    .buttonPort = BUTTON_PORTF,
    .buttonPin  = BUTTON_PIN4,
    .buttonMode = BUTTON_INTERRUPT_FALLING_EDGE_MODE,
    .buttonHandler = APP_sequence
};
st_led_t st_g_redLed = {
    .ledPort = LED_PORTF,
    .ledPin  = LED_PIN1,
    .ledState= LED_OFF,
    .ptr_func_ledCallBack = APP_redLedRoutine
};
st_led_t st_g_blueLed = {
    .ledPort = LED_PORTF,
    .ledPin  = LED_PIN2,
    .ledState= LED_OFF,
    .ptr_func_ledCallBack = APP_blueLedRoutine
};
st_led_t st_g_greenLed = {
    .ledPort = LED_PORTF,
    .ledPin  = LED_PIN3,
    .ledState= LED_OFF,
    .ptr_func_ledCallBack = APP_greenLedRoutine
};

str_sysTickTask_t str_gl_redLedTask = {
    .taskId = TASK_1_ID,
    .taskInterval = LED_ON_INTERVAL,
    .taskPeriodicity = TASK_ONE_SHOT,
    .ptr_func_taskHandler = APP_redLedRoutine
};
str_sysTickTask_t str_gl_greenLedTask = {
    .taskId = TASK_2_ID,
    .taskInterval = LED_ON_INTERVAL,
    .taskPeriodicity = TASK_ONE_SHOT,
    .ptr_func_taskHandler = APP_greenLedRoutine
};
str_sysTickTask_t str_gl_blueLedTask = {
    .taskId = TASK_3_ID,
    .taskInterval = LED_ON_INTERVAL,
    .taskPeriodicity = TASK_ONE_SHOT,
    .ptr_func_taskHandler = APP_blueLedRoutine
};
str_sysTickTask_t str_gl_allLedsTask = {
    .taskId = TASK_4_ID,
    .taskInterval = LED_ON_INTERVAL,
    .taskPeriodicity = TASK_ONE_SHOT,
    .ptr_func_taskHandler = APP_allLedsRoutine
};
#endif