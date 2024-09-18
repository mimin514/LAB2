/*
 * timer.c
 *
 *  Created on: Sep 18, 2024
 *      Author: User
 */

#include "timer.h"
#include "led7.h"

#define NUM_TIMERS 10  // Number of timers you want to handle
#define TICK 10
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


int digit_index = 0;
const uint8_t digits[] = {1, 2, 3, 0};  // Digits to display in order
const uint16_t digit_pins[] = {GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9};  // PA6, PA7, PA8, PA9

void display_digit(uint8_t digit)
{
    display1(digit);
}
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2){
	        timerRun();

	        if (timer_flag[0] == 1){
	            HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	            setTimer(0, 1000);
	        }

	        if (timer_flag[1] == 1){
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, 1);

	            display_digit(digits[digit_index]);

	            HAL_GPIO_WritePin(GPIOA, digit_pins[digit_index], 0);

	            digit_index++;
	            if (digit_index >= 4) digit_index = 0;
	            setTimer(1,500);
	        }
	    }
	}
