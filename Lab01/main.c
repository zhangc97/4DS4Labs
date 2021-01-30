/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	/* Testing pins */
	// HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	// HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    /* USER CODE END WHILE */

	char initials[5] = "AB AB";
	uint16_t pins[2] = {GPIO_PIN_4, GPIO_PIN_5};
	for (int i = 0; i < 5; i++) {
		if (initials[i] == ' ') {
			HAL_Delay(2500);
		} else {
			Flash_Morse_Character(initials[i], GPIOB, pins[i%3]);
			HAL_Delay(1500);
		}
	}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}


/*
 * This function will take in a char variable and flash the morse code related to the char on the inputted pin
 * @param  Char_Value specifies the character to flash
 * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L4 family
 * @param  GPIO_Pin specifies the port bit to be written.
 *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 */

void Flash_Morse_Character(char Char_Value, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	// Dot 500ms
	// Dash 1500ms
	switch (Char_Value)
	{
	case 'A':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		break;
	case 'B':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
    break;
    // commmmmment
	case 'N':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'O':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'P':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'Q':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'R':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'S':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'T':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'U':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'V':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'W':
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'X':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'Y':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	case 'Z':
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dash(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		Dot(GPIOx, GPIO_Pin);
		HAL_Delay(500);
		break;
	}
}

/*
 * This function creates a morse code dot
 * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L4 family
 * @param  GPIO_Pin specifies the port bit to be written.
 *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 */
void Dot(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

/*
 * This function creates a morse code dash
 * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L4 family
 * @param  GPIO_Pin specifies the port bit to be written.
 *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 */
void Dash(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	HAL_Delay(1500);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD3_Pin|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LD3_Pin PB4 PB5 */
  GPIO_InitStruct.Pin = LD3_Pin|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
