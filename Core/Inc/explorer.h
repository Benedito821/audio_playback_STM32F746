/*
 * explorer.h
 *
 *  Created on: Feb 20, 2024
 *      Author: bened
 */

#ifndef INC_EXPLORER_H_
#define INC_EXPLORER_H_
#include "stdint.h"
#include "ff.h"

uint8_t AUDIO_ShowWavFiles(void);
uint8_t AUDIO_StorageInit(void);
FRESULT AUDIO_StorageParse(void);
uint16_t AUDIO_GetWavObjectNumber(void);
#endif /* INC_EXPLORER_H_ */
