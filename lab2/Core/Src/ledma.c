/*
 * ledma.c
 *
 *  Created on: Sep 20, 2024
 *      Author: User
 */


#include "ledma.c"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
void updateLEDMatrix(int index){
	switch (index){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
	}
}

#include "stm32f1xx_hal.h"

// Function to set a specific row
void setRow(int index) {
    // Reset all rows first
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

    // Set the specific row
    switch (index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
            break;
        default:
            break;
    }
}

// Function to set the columns for a specific row
void setColumns(uint8_t data) {
    // Reset all columns
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

    // Set columns based on data
    if (data & 0x01) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
    if (data & 0x02) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
    if (data & 0x04) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
    if (data & 0x08) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    if (data & 0x10) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
    if (data & 0x20) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    if (data & 0x40) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    if (data & 0x80) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
}

// Function to display the letter "A"
void displayLetterA(void) {
    // Define the pattern for the letter "A"
    uint8_t letterA[8] = {
        0x7E,  // Row 0
        0x81,  // Row 1
        0x81,  // Row 2
        0xFF,  // Row 3
        0x81,  // Row 4
        0x81,  // Row 5
        0x81,  // Row 6
        0x81   // Row 7
    };

    // Manually set each row and its corresponding column data
    setRow(0); // Set row 0
    setColumns(letterA[0]); // Set columns for row 0
    HAL_Delay(1); // Short delay for persistence

    setRow(1); // Set row 1
    setColumns(letterA[1]); // Set columns for row 1
    HAL_Delay(1);

    setRow(2); // Set row 2
    setColumns(letterA[2]); // Set columns for row 2
    HAL_Delay(1);

    setRow(3); // Set row 3
    setColumns(letterA[3]); // Set columns for row 3
    HAL_Delay(1);

    setRow(4); // Set row 4
    setColumns(letterA[4]); // Set columns for row 4
    HAL_Delay(1);

    setRow(5); // Set row 5
    setColumns(letterA[5]); // Set columns for row 5
    HAL_Delay(1);

    setRow(6); // Set row 6
    setColumns(letterA[6]); // Set columns for row 6
    HAL_Delay(1);

    setRow(7); // Set row 7
    setColumns(letterA[7]); // Set columns for row 7
    HAL_Delay(1);
}

