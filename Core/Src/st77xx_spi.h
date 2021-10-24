#ifndef _ST77XX_SPI_H
#define _ST77XX_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define DC_GPIO_Port	GPIOA
#define DC_Pin			GPIO_PIN_3

#define RST_GPIO_Port   GPIOA
#define RST_Pin			GPIO_PIN_2

#define CS_GPIO_Port    GPIOA
#define CS_Pin			GPIO_PIN_4

#define BLK_GPIO_Port   GPIOA
#define BLK_Pin			GPIO_PIN_0

extern SPI_HandleTypeDef hspi2;

void ST77XX_SPI_Init(void);
void ST77XX_GPIO_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
