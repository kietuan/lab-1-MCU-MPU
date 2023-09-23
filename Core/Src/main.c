/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearNumberOnClock (int);
void setNumberOnClock (int);
void displayClock (int, int, int);
void increaseClock(int*, int*, int*);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  int hour = 23;
  int minute = 5;
  int second = 29;
  uint32_t counter = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (counter >= 10)
	  {
		  counter = 0;
		  increaseClock(&hour, &minute, &second);
		  displayClock(hour, minute, second);
	  }
	  counter++;
	  HAL_Delay(10);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD_0_Pin|LD_1_Pin|LD_2_Pin|LD_3_Pin
                          |LD_4_Pin|LD_5_Pin|LD_6_Pin|LD_7_Pin
                          |LD_8_Pin|LD_9_Pin|LD_10_Pin|LD_11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD_0_Pin LD_1_Pin LD_2_Pin LD_3_Pin
                           LD_4_Pin LD_5_Pin LD_6_Pin LD_7_Pin
                           LD_8_Pin LD_9_Pin LD_10_Pin LD_11_Pin */
  GPIO_InitStruct.Pin = LD_0_Pin|LD_1_Pin|LD_2_Pin|LD_3_Pin
                          |LD_4_Pin|LD_5_Pin|LD_6_Pin|LD_7_Pin
                          |LD_8_Pin|LD_9_Pin|LD_10_Pin|LD_11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void setNumberOnClock (int num)
{
	if (0 == num)
	{
		HAL_GPIO_WritePin(LD_0_GPIO_Port, LD_0_Pin, 1);
	}

	if (1 == num)
	{
		HAL_GPIO_WritePin(LD_1_GPIO_Port, LD_1_Pin, 1);
	}

	if (2 == num)
	{
		HAL_GPIO_WritePin(LD_2_GPIO_Port, LD_2_Pin, 1);
	}

	if (3 == num)
		HAL_GPIO_WritePin(LD_3_GPIO_Port, LD_3_Pin, 1);

	if (4 == num)
		HAL_GPIO_WritePin(LD_4_GPIO_Port, LD_4_Pin, 1);

	if (5 == num)
		HAL_GPIO_WritePin(LD_5_GPIO_Port, LD_5_Pin, 1);

	if (6 == num)
		HAL_GPIO_WritePin(LD_6_GPIO_Port, LD_6_Pin, 1);

	if (7 == num)
		HAL_GPIO_WritePin(LD_7_GPIO_Port, LD_7_Pin, 1);

	if (8 == num)
		HAL_GPIO_WritePin(LD_8_GPIO_Port, LD_8_Pin, 1);

	if (9 == num)
		HAL_GPIO_WritePin(LD_9_GPIO_Port, LD_9_Pin, 1);

	if (10 == num)
		HAL_GPIO_WritePin(LD_10_GPIO_Port, LD_10_Pin, 1);

	if (11 == num)
		HAL_GPIO_WritePin(LD_11_GPIO_Port, LD_11_Pin, 1);
}

void clearNumberOnClock (int num)
{
	if (0 == num)
	{
		HAL_GPIO_WritePin(LD_0_GPIO_Port, LD_0_Pin, 0);
	}

	if (1 == num)
	{
		HAL_GPIO_WritePin(LD_1_GPIO_Port, LD_1_Pin, 0);
	}

	if (2 == num)
	{
		HAL_GPIO_WritePin(LD_2_GPIO_Port, LD_2_Pin, 0);
	}

	if (3 == num)
		HAL_GPIO_WritePin(LD_3_GPIO_Port, LD_3_Pin, 0);

	if (4 == num)
		HAL_GPIO_WritePin(LD_4_GPIO_Port, LD_4_Pin, 0);

	if (5 == num)
		HAL_GPIO_WritePin(LD_5_GPIO_Port, LD_5_Pin, 0);

	if (6 == num)
		HAL_GPIO_WritePin(LD_6_GPIO_Port, LD_6_Pin, 0);

	if (7 == num)
		HAL_GPIO_WritePin(LD_7_GPIO_Port, LD_7_Pin, 0);

	if (8 == num)
		HAL_GPIO_WritePin(LD_8_GPIO_Port, LD_8_Pin, 0);

	if (9 == num)
		HAL_GPIO_WritePin(LD_9_GPIO_Port, LD_9_Pin, 0);

	if (10 == num)
		HAL_GPIO_WritePin(LD_10_GPIO_Port, LD_10_Pin, 0);

	if (11 == num)
		HAL_GPIO_WritePin(LD_11_GPIO_Port, LD_11_Pin, 0);
}

void displayClock ( int hour,  int minute,  int second)
{
//	hour %= 12;
//	minute %= 60;
//	second %= 60;

	for (int i = 0; i <= 11; ++i)
	{
		if (hour == i || second/5 == i || minute/5 == i)
			setNumberOnClock (i);
		else
			clearNumberOnClock(i);
	}
}

void increaseClock (int* hour, int* minute, int* second)
{
//	(*hour) %= 12;
//	(*minute) %= 60;
//	(*second) %= 60;

	(*second)++;
	if (*second >= 60)
	{
		*second = 0;
		(*minute)++;
		if (*minute >= 60)
		{
			*minute = 0;
			(*hour)++;
			if (*hour >= 12)
				*hour = 0;
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
