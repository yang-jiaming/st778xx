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
#include "st7789.h"
#include "st7735.h"
#include "bitmap.h"
#include "st77xx_fonts.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
// ST7789_GPIO_Init();
// ST7789_SPI_Init();
 
 
 ST7789_Init();
 //ST7735_Init();

	// §Ù§Ñ§Ü§â§Ñ§ê§Ú§Ó§Ñ§Ö§Þ §Ó§Ö§ã§î §ï§Ü§â§Ñ§ß §å§Ü§Ñ§Ù§Ñ§ß§í§Þ §è§Ó§Ö§ä§à§Þ 
				ST7789_FillScreen( RGB565(255, 0, 0) );
				HAL_Delay (2000);
				// §Ù§Ñ§Ü§â§Ñ§ê§Ú§Ó§Ñ§Ö§Þ §Ó§Ö§ã§î §ï§Ü§â§Ñ§ß §å§Ü§Ñ§Ù§Ñ§ß§í§Þ §è§Ó§Ö§ä§à§Þ 
				ST7789_FillScreen( RGB565(0, 255, 0) );
				HAL_Delay (2000);
				// §Ù§Ñ§Ü§â§Ñ§ê§Ú§Ó§Ñ§Ö§Þ §Ó§Ö§ã§î §ï§Ü§â§Ñ§ß §å§Ü§Ñ§Ù§Ñ§ß§í§Þ §è§Ó§Ö§ä§à§Þ 
				ST7789_FillScreen( RGB565(0, 0, 255) );
				HAL_Delay (2000);
				
				// §á§â§ñ§Þ§à§å§Ô§à§Ý§î§ß§Ú§Ü §Ù§Ñ§Ü§â§Ñ§ê§Ö§ß§í§Û ( §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§Ñ X §Ú Y ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ) §ê§Ú§â§Ú§ß§Ñ §Ú §Ó§í§ã§à§ä§Ñ §Ó §á§Ú§Ü§ã§Ö§Ý§ñ§ç )
				ST7789_DrawRectangleFilled(0, 0, 240, 240, RGB565(255, 255, 255)) ;
				HAL_Delay (1000);
				
				for( uint8_t i = 0; i< 240; i+=3){
					// §á§â§ñ§Þ§à§å§Ô§à§Ý§î§ß§Ú§Ü §Ù§Ñ§Ü§â§Ñ§ê§Ö§ß§í§Û ( §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§Ñ X §Ú Y ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ) §ê§Ú§â§Ú§ß§Ñ §Ú §Ó§í§ã§à§ä§Ñ §Ó §á§Ú§Ü§ã§Ö§Ý§ñ§ç )
					ST7789_DrawRectangleFilled(i, i, 240-i, 240-i, RGB565(i/2, 255-i, 0+i)) ;
				}
				
				for( uint8_t i = 0; i< 120; i+=3){
					// §á§â§ñ§Þ§à§å§Ô§à§Ý§î§ß§Ú§Ü §á§å§ã§ä§à§ä§Ö§Ý§í§Û ( §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§Ñ X §Ú Y ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ) §ê§Ú§â§Ú§ß§Ñ §Ú §Ó§í§ã§à§ä§Ñ §Ó §á§Ú§Ü§ã§Ö§Ý§ñ§ç )
					ST7789_DrawRectangle(i, i, 240-i, 240-i, RGB565(255, 0, 0)) ;
				}
				HAL_Delay (2000);
				
				
				// §â§Ú§ã§å§Ö§Þ §è§Ó§Ö§ä§ß§å§ð §Ú§Ü§à§ß§Ü§å. §á§Ñ§â§Ñ§Þ§Ö§ä§â§í §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§í §ç §Ú §å ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ), §â§Ñ§Ù§Þ§Ö§â §Ú§Ü§à§ß§Ü§Ú §ê§Ú§â §Ú §Ó§í§ã, §Ú§Þ§ñ §Ú§Ü§à§ß§Ü§Ú ( §Þ§Ñ§ã§ã§Ú§Ó )
				ST7789_DrawImage( 0, 0, 240, 240, img1 );
				HAL_Delay (2000);
				
				// §â§Ú§ã§å§Ö§Þ §è§Ó§Ö§ä§ß§å§ð §Ú§Ü§à§ß§Ü§å. §á§Ñ§â§Ñ§Þ§Ö§ä§â§í §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§í §ç §Ú §å ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ), §â§Ñ§Ù§Þ§Ö§â §Ú§Ü§à§ß§Ü§Ú §ê§Ú§â §Ú §Ó§í§ã, §Ú§Þ§ñ §Ú§Ü§à§ß§Ü§Ú ( §Þ§Ñ§ã§ã§Ú§Ó )
				ST7789_DrawImage( 0, 0, 240, 240, img2 );
				HAL_Delay (2000);
				
				// §â§Ú§ã§å§Ö§Þ §è§Ó§Ö§ä§ß§å§ð §Ú§Ü§à§ß§Ü§å. §á§Ñ§â§Ñ§Þ§Ö§ä§â§í §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§í §ç §Ú §å ( §ß§Ñ§é§Ú§ß§Ñ§ñ §ã 0 ), §â§Ñ§Ù§Þ§Ö§â §Ú§Ü§à§ß§Ü§Ú §ê§Ú§â §Ú §Ó§í§ã, §Ú§Þ§ñ §Ú§Ü§à§ß§Ü§Ú ( §Þ§Ñ§ã§ã§Ú§Ó )
				ST7789_DrawImage( 0, 0, 240, 240, img3 );
				HAL_Delay (2000);
				
	
	// §Ù§Ñ§Ü§â§Ñ§ê§Ú§Ó§Ñ§Ö§Þ §Ó§Ö§ã§î §ï§Ü§â§Ñ§ß §å§Ü§Ñ§Ù§Ñ§ß§í§Þ §è§Ó§Ö§ä§à§Þ 
	ST7789_FillScreen( RGB565(0, 10, 100) );
	

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//ST7789_Test();
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
