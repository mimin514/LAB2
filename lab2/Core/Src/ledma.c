/*
 * ledma.c
 *
 *  Created on: Sep 20, 2024
 *      Author: User
 */

#include "ledma.h"
#include "stm32f1xx_hal.h"

int count = 0;

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

