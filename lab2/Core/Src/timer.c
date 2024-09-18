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

int digit_index = 0;
const uint8_t digits[] = {1, 2, 3, 0};  // Digits to display in order
const uint16_t digit_pins[] = {GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9};  // PA6, PA7, PA8, PA9

#define MAX_LED 4
int led_buffer[MAX_LED] = {9, 8, 7, 6};  // Example buffer with 4 digits to display
int index_led=0;

int hour = 15, minute = 8, second = 50;
int led_state=0;

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
            }
        }
    }
}

void display_digit(uint8_t digit)
{
    display1(digit);
}
void update7SEG(int index) {
    switch (index) {
        case 0:
            display1(led_buffer[0]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
            break;
        case 1:
            display1(led_buffer[1]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
            break;
        case 2:
            display1(led_buffer[2]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
            break;
        case 3:
            display1(led_buffer[3]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
            break;
        default:
            break;
    }
}
void updateClockBuffer(void)
{
    uint8_t hour_tens = hour / 10; // Tens place of hour
    uint8_t hour_units = hour % 10; // Units place of hour
    uint8_t minute_tens = minute / 10; // Tens place of minute
    uint8_t minute_units = minute % 10; // Units place of minute

    // For displaying hour and minute
    led_buffer[0] = hour_tens; // Display hours tens digit
    led_buffer[1] = hour_units; // Display hours units digit
    led_buffer[2] = minute_tens; // Display minutes tens digit
    led_buffer[3] = minute_units; // Display minutes units digit
}
void runex5(void){
	  second++;
	  	  if (second >= 60) {
	  		  second = 0;
	  		  minute++;
	  	  }
	  	  if( minute >= 60) {
	  		  minute = 0;
	  		  hour++;
	  	  }
	  	  if( hour >=24){
	  		  hour = 0;
	  	  }
	  	  updateClockBuffer();
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

				display_digit(led_buffer[digit_index]);

				HAL_GPIO_WritePin(GPIOA, digit_pins[digit_index], 0);

				digit_index++;
				if (digit_index >= 4) digit_index = 0;
				setTimer(1,250);
			}

	    }
	}
