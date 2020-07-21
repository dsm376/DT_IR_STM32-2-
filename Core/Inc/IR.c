/*
 * IR.c
 *
 *  Created on: 14-May-2020
 *      Author: admiral
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdlib.h"
#include <stdio.h>
#include <stdint.h>
#include "stm32g0xx_hal.h"
#include "IR.h"
#include <string.h>
#include "stm32g0xx_it.h"

/*define---------------------*/
#define UART_BUFFER_MAX_DATA_LEN 256

/* Private variables ---------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3 ;

char RxData_array[UART_BUFFER_MAX_DATA_LEN];
char TxData_array[UART_BUFFER_MAX_DATA_LEN];
int  UART_index = 0;\


uint8_t p_rx_buffer;
uint8_t value = 0;
char txdata[5] = "ok\r\n";

void UART_TX (void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart);

/*UART Transmit function*/
void UART_TX (void)
{
	HAL_UART_Transmit(&huart1,(uint8_t*)TxData_array,strlen(TxData_array),10);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart)
{
	/*prevent unused argument(s) complication warning*/
	UNUSED(uart);

	RxData_array[UART_index] = p_rx_buffer;
	if(UART_index>2){
		if((RxData_array[UART_index]=='\n')||(UART_index >=UART_BUFFER_MAX_DATA_LEN))
		{
			UART_index =0;
			memset(RxData_array,0,UART_BUFFER_MAX_DATA_LEN);
		  return;

		}
	}
	UART_index++;
}

void LED(bool enable)
{
	if(enable)
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		}
	else
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		}
}

void buzzer_Notification()
{
	if(value<255)
	{
		htim3.Instance->CCR1 = value;
		value += 20;
		HAL_Delay (500);
	}
	value=0;
}
/*void check_charge_status(void)
 *brief function used to check charger is connected or not
 *Param [in] 	:void
 *Param [out]	:void
 *Param [ret]	:void


*/
void check_charge_status(void)
{
	uint8_t status ;

	status = HAL_GPIO_ReadPin(CHARGE_DETECT_GPIO_Port, CHARGE_DETECT_Pin);

	if(status == 1)
	{
		// Display charging icon
	}
	else if(status == 0)
	{
		// Do not display charging icon
	}
	//return	gpio_pin_status;
}


