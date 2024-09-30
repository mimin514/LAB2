/*
 * ledma.c
 *
 *  Created on: Sep 20, 2024
 *      Author: User
 */

#include "ledma.h"
#include "timer.h"
#include "stm32f1xx_hal.h"
#include <string.h>
int count = 0;
uint8_t heart[8] =
    //{0x00, 0x66, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00}; // Trái tim
     {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66}; // Chữ A
    // {0x63, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0x63}, // Chữ K
    // {0x00, 0xC3, 0xE7, 0xFF, 0xDB, 0xC3, 0xC3, 0xC3}, // Chữ M
    // {0x00, 0xC3, 0xE3, 0xF3, 0xDB, 0xCF, 0xC7, 0xC3}, // Chữ N
    // {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C}, // Mặt cư�?i
    // {0x0B, 0x7E, 0xD8, 0x18, 0x18, 0x24, 0x42, 0xC3}  // H�? hước
//};

void ledma_init() {
    HAL_GPIO_WritePin(GPIOA,
                      ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin,
                      GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,
                      ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin,
                      GPIO_PIN_RESET);
}

void row(int num) {
    HAL_GPIO_WritePin(GPIOB,
                      ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin,
                      GPIO_PIN_RESET);

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

void updateLEDMatrix(uint8_t *pattern) {
    if (count >= 8) count = 0;

    row(count);

    HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (pattern[count] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (pattern[count] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (pattern[count] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (pattern[count] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (pattern[count] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (pattern[count] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (pattern[count] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (pattern[count] & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    count++;
}

void shift(uint8_t *pattern){
    for (int i = 0; i < 8; i++) {
        uint8_t temp = (pattern[i] << 1) | ((pattern[i] & 0x80) >> 7);  // Shift left and wrap the leftmost bit to the right
        pattern[i] = temp;
    }
}

void shiftleftLEDMatrix(uint8_t* data) {
	 uint8_t buffer[8];
    memcpy(buffer, data, 8);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            updateLEDMatrix(buffer);
            HAL_Delay(2);
        }
        shift(buffer);

        HAL_Delay(20);
    }
}
void runex9(){
	updateLEDMatrix(heart);
}
void runex10(){
	shiftleftLEDMatrix(heart);
}
