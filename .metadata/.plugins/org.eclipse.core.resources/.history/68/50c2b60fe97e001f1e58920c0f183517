///*
// * ledma.c
// *
// *  Created on: Sep 20, 2024
// *      Author: User
// */
//
//
//#include "ledma.h"
//
//const int MAX_LED_MATRIX = 8;
//int index_led_matrix = 0;
//uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
//int count=0;
//// Function to update the LED matrix based on the index
//void ledma_init(){
//	HAL_GPIO_WritePin(GPIOA,
//			ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin,
//			GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB,
//				ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin,
//				GPIO_PIN_RESET);
//}
//void row(int num){
//	HAL_GPIO_WritePin(GPIOB,
//					ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin,
//					GPIO_PIN_SET);
//}
//
//void updateLEDMatrix(uint8_t *pattern) {
//    	if(count>=8) count=0;
//
//        // Set the current row (only one row active at a time)
//        row(count);
//        pattern[count];
//        count++;
//
//}
//
//int countrow=0,countcol=0;
//// Display a pattern on the LED matrix
//void DisplayPattern(uint8_t* pattern) {
//        row(countrow);
//        if (countrow>=8) countrow=0;// Select the row
//        uint8_t col_data = pattern[countrow]; // Get the column data for the current row
//
//            if (col_data & (1 << countcol)) {
//                col(countcol); // Activate the column if the bit is set
//                countcol++;
//                if(countcol>=8)countcol=0;
//        }
//        countrow++;
//        HAL_Delay(1); // Adjust the delay for your refresh rate
//}








#include "ledma.h"
#include "stm32f1xx_hal.h"  // Include HAL library header

uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t heart[8] = {0x00, 0x66, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00}; // Heart

int count = 0;

// Function to initialize the LED matrix
void ledma_init() {
    HAL_GPIO_WritePin(GPIOA,
                      ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin,
                      GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,
                      ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin,
                      GPIO_PIN_RESET);
}

// Function to activate a specific row
void row(int num) {
    HAL_GPIO_WritePin(GPIOB,
                      ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin,
                      GPIO_PIN_RESET); // Reset all rows

    switch (num) {
        case 0: HAL_GPIO_WritePin(GPIOB, ROW0_Pin, GPIO_PIN_SET); break;
        case 1: HAL_GPIO_WritePin(GPIOB, ROW1_Pin, GPIO_PIN_SET); break;
        case 2: HAL_GPIO_WritePin(GPIOB, ROW2_Pin, GPIO_PIN_SET); break;
        case 3: HAL_GPIO_WritePin(GPIOB, ROW3_Pin, GPIO_PIN_SET); break;
        case 4: HAL_GPIO_WritePin(GPIOB, ROW4_Pin, GPIO_PIN_SET); break;
        case 5: HAL_GPIO_WritePin(GPIOB, ROW5_Pin, GPIO_PIN_SET); break;
        case 6: HAL_GPIO_WritePin(GPIOB, ROW6_Pin, GPIO_PIN_SET); break;
        case 7: HAL_GPIO_WritePin(GPIOB, ROW7_Pin, GPIO_PIN_SET); break;
        default: break;
    }

}

// Function to update the LED matrix with a specific pattern
void updateLEDMatrix(uint8_t *pattern) {
    if (count >= 8) count = 0; // Reset count if it exceeds 8

    // Set the current row (only one row active at a time)
    row(count);

    // Output the pattern for the current row
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (pattern[count] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (pattern[count] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (pattern[count] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (pattern[count] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (pattern[count] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (pattern[count] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (pattern[count] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (pattern[count] & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    count++; // Move to the next row
}

