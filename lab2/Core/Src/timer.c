/*
 * timer.c
 *
 *  Created on: Sep 18, 2024
 *      Author: User
 */

#define NUM_TIMERS 10  // Number of timers you want to handle
#define TICK 10

#include "timer.h"
#include "led7.h"

int timer_flag[NUM_TIMERS];  // Timer flags for each timer
int timer_counter[NUM_TIMERS];  // Timer counters for each timer

void setTimer(int timer_id, int duration)
{
	if (timer_id >= 0 && timer_id < NUM_TIMERS)
	    {
	        timer_counter[timer_id] = duration / TICK;
	        timer_flag[timer_id] = 0;
	    }
}
void timerRun(void)
{
    for (int i = 0; i < NUM_TIMERS; i++)
    {
        if (timer_counter[i] >= 0)
        {
            timer_counter[i]--;  // Decrease the counter

            if (timer_counter[i] <= 0)
            {
                timer_flag[i] = 1;  // Timer expired
                // Optional: Trigger a specific action for timer expiration
            }
        }
    }
}
int led_state = 0;

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2){
		timerRun();
		if(timer_flag[0]==1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer(0,1000);
		}
		if(timer_flag[1]==1){
			if (led_state == 0) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
				display1(1);
				led_state = 1;
			} else {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
				display1(2);
				led_state = 0;
			}
			setTimer(1,500);
		}

	}
	}
