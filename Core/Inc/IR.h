/*
 * IR.h
 *
 *  Created on: 14-May-2020
 *      Author: admiral
 */

#ifndef INC_IR_H_
#define INC_IR_H_

#endif /* INC_IR_H_ */

// C Standard Libraries

#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Private defines -----------------------------------------------------------*/
/* DEFAULT SLAVE ADDRESS */
#define sEn_DEFAULT_SA 0x5A
/* OPCODE DEFINES */
#define sEn_OP_RAM		0x00
#define sEn_OP_EEPROM	0x20
#define sEn_OP_SLEEP	0xFF

/* RAM offsets with 16-bit data, MSB first */
#define sEn_RAW1		(sEn_OP_RAM | 0x04) /* raw data IR channel 1 */
#define sEn_RAW2		(sEn_OP_RAM | 0x05) /* raw data IR channel 2 */
#define sEn_TAMB 		(sEn_OP_RAM | 0x06) /* ambient temperature */
#define sEn_TOBJ1 		(sEn_OP_RAM | 0x07) /* object 1 temperature */
#define sEn_TOBJ2 		(sEn_OP_RAM | 0x08) /* object 2 temperature */
/* EEPROM offsets with 16-bit data, MSB first */
#define sEn_TOMIN 		(sEn_OP_EEPROM | 0x00) /* object temperature min register */
#define sEn_TOMAX 		(sEn_OP_EEPROM | 0x01) /* object temperature max register */
#define sEn_PWMCTRL 	(sEn_OP_EEPROM | 0x02) /* pwm configuration register */
#define sEn_TARANGE 	(sEn_OP_EEPROM | 0x03) /* ambient temperature register */
#define sEn_EMISSIVITY (sEn_OP_EEPROM | 0x04) /* emissivity correction register */
#define sEn_CFG1 		(sEn_OP_EEPROM | 0x05) /* configuration register */
#define sEn_SA 		(sEn_OP_EEPROM | 0x0E) /* slave address register */
#define sEn_ID1 		(sEn_OP_EEPROM | 0x1C) /*[read-only] 1 ID register */
#define sEn_ID2 		(sEn_OP_EEPROM | 0x1D) /*[read-only] 2 ID register */
#define sEn_ID3 		(sEn_OP_EEPROM | 0x1E) /*[read-only] 3 ID register */
#define sEn_ID4 		(sEn_OP_EEPROM | 0x1F) /*[read-only] 4 ID register */

#define sEn_DBG_OFF 0
#define sEn_DBG_ON 1
#define sEn_DBG_MSG_W 0
#define sEn_DBG_MSG_R 1


/* Exported functions prototypes ---------------------------------------------*/

uint8_t CRC8_Calc(uint8_t*, const uint8_t);
void sEn_WriteReg(uint8_t, uint8_t, uint16_t);
uint16_t sEn_ReadReg(uint8_t, uint8_t, uint8_t);
float sEn_ReadTemp(uint8_t, uint8_t);
void sEn_ScanDevices (void);
void sEn_SendDebugMsg(uint8_t, uint8_t, uint8_t, uint16_t, uint8_t, uint8_t);
void LED(bool enable);
void UART_TX (void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart);
void buzzer_Notification();
