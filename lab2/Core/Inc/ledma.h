/*
 * ledma.h
 *
 *  Created on: Sep 20, 2024
 *      Author: User
 */

#ifndef INC_LEDMA_H_
#define INC_LEDMA_H_
#include "main.h"

void ledma_init();
void updateLEDMatrix(uint8_t *pattern) ;
void shiftleftLEDMatrix(uint8_t* data) ;
void runex9();
void runex10();

#endif /* INC_LEDMA_H_ */
