#ifndef _ST7789_H
#define _ST7789_H


/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

/* 必须包括“main.h”,为了避免单独连接与MK和标准库相关的文件 */
#include "stm32f1xx.h"
#include "st77xx_spi.h"
#include "st77xx_fonts.h"
#include "stdlib.h"
#include "string.h"

extern uint16_t ST7789_Width, ST7789_Height;

//====选择通过HAL或CMSIS发送的内容（更快）===================
//为CMSIS指定SPI端口（快速）-----
//由于不同的MC有不同的寄存器，所以在函数中，我们根据自己的MC进行了调整
//目前，F1 F4 H7系列有一个实现，用于选择功能中的系列
//void st7789 sendcmd（uint8 t cmd）；
//void st7789 senddata（uint8 t data）；
//void st7789 senddatamass（uint8 t*buff，size t buff size）；	
//#define st7789 spi cmsis spi2
/* ------------------------------------------------ */
			
/* 指定HAL的SPI端口（慢速） */
#define ST7789_SPI_HAL 		hspi2
/* ------------------------------------------------ */

/* 选择显示方向： */
#define	ST7789_IS_135X240		// 1.14" 135 x 240 ST7789 
//#define	ST7789_IS_240X240	// 1.3" 240 x 240 ST7789 		
//#define	ST7789_IS_240X320	// 2" 240 x 320 ST7789
/* ------------------------------------------------ */

#ifdef ST7789_SPI_HAL
	extern SPI_HandleTypeDef ST7789_SPI_HAL;
#endif

extern uint16_t ST7789_X_Start;
extern uint16_t ST7789_Y_Start;

#define RGB565(r, g, b)         (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))
/* ------------------------------------------------ */

 /* 成品颜色 */ 
#define   	ST7789_BLACK   	0x0000
#define   	ST7789_BLUE    	0x001F
#define   	ST7789_RED     	0xF800
#define   	ST7789_GREEN   	0x07E0
#define 	ST7789_CYAN    	0x07FF
#define 	ST7789_MAGENTA 	0xF81F
#define 	ST7789_YELLOW  	0xFFE0
#define 	ST7789_WHITE   	0xFFFF
/* ------------------------------------------------ */

/* 位颜色设置掩码ST7789 */ 
#define ST7789_ColorMode_65K    0x50
#define ST7789_ColorMode_262K   0x60
#define ST7789_ColorMode_12bit  0x03
#define ST7789_ColorMode_16bit  0x05
#define ST7789_ColorMode_18bit  0x06
#define ST7789_ColorMode_16M    0x07
/* ------------------------------------------------ */

#define ST7789_MADCTL_MY  		0x80
#define ST7789_MADCTL_MX  		0x40
#define ST7789_MADCTL_MV  		0x20
#define ST7789_MADCTL_ML  		0x10
#define ST7789_MADCTL_RGB 		0x00
#define ST7789_MADCTL_BGR 		0x08
#define ST7789_MADCTL_MH  		0x04
/* ------------------------------------------------ */

#define ST7789_SWRESET 0x01
#define ST7789_SLPIN   0x10
#define ST7789_SLPOUT  0x11
#define ST7789_NORON   0x13
#define ST7789_INVOFF  0x20
#define ST7789_INVON   0x21
#define ST7789_DISPOFF 0x28
#define ST7789_DISPON  0x29
#define ST7789_CASET   0x2A
#define ST7789_RASET   0x2B
#define ST7789_RAMWR   0x2C
#define ST7789_COLMOD  0x3A
#define ST7789_MADCTL  0x36
/* ------------------------------------------------ */

#define DELAY 0x80
/* ------------------------------------------------ */

/* 1.3" 240 x 240 ST7789  display, default orientation */
#ifdef ST7789_IS_240X240
	
	#define ST7789_WIDTH  			240
	#define ST7789_HEIGHT 			240
	#define ST7789_XSTART 			0
	#define ST7789_YSTART 			0
	#define ST7789_ROTATION 		(ST7789_MADCTL_MV|ST7789_MADCTL_ML|ST7789_MADCTL_MH)
	
#endif

/* 1.14英寸135 x 240 ST7789显示器，默认方向 */
#ifdef ST7789_IS_135X240
	
	#define ST7789_WIDTH  			135
	#define ST7789_HEIGHT 			240
	#define ST7789_XSTART 			0
	#define ST7789_YSTART 			0
	#define ST7789_ROTATION 		(ST7789_MADCTL_MV|ST7789_MADCTL_ML|ST7789_MADCTL_MH)
	
#endif
	
/* 2英寸240 x 320 ST7789显示器，默认方向 */
#ifdef ST7789_IS_240X320
	
	#define ST7789_WIDTH  			240
	#define ST7789_HEIGHT 			320
	#define ST7789_XSTART 			0
	#define ST7789_YSTART 			0
	#define ST7789_ROTATION 		(ST7789_MADCTL_MV|ST7789_MADCTL_ML|ST7789_MADCTL_MH)
	
#endif

/* 显示初始化过程 */
void ST7789_Init(void);

/* SPI控制程序 */
void ST7789_Select(void);
void ST7789_Unselect(void);

/* 发送数据以初始化显示的过程 */
static void ST7789_ExecuteCommandList(const uint8_t *addr);

/* 彩色图像显示程序 */
void ST7789_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);	

/* 显示硬件重置过程（RESET脚） */
void ST7789_HardReset(void);

/* 向显示屏发送命令的过程 */
void ST7789_SendCmd(uint8_t Cmd);

/* 将数据（参数）发送到1 Byte显示屏的过程 */
void ST7789_SendData(uint8_t Data );

/* 向Mass显示屏发送数据（参数）的过程 */
void ST7789_SendDataMASS(uint8_t* buff, size_t buff_size);

/* 睡眠模式启动程序 */
void ST7789_SleepModeEnter( void );

/* 睡眠模式关闭程序 */
void ST7789_SleepModeExit( void );

/* 设置颜色格式的过程 */
void ST7789_ColorModeSet(uint8_t ColorMode);

/* 显示配置过程 */
void ST7789_MemAccessModeSet(uint8_t Rotation, uint8_t VertMirror, uint8_t HorizMirror, uint8_t IsBGR);

/* 启用/禁用部分屏幕填充模式的过程 */
void ST7789_InversionMode(uint8_t Mode);

/* 程序将屏幕着色为彩色 */
void ST7789_FillScreen(uint16_t color);

/* 屏幕清理程序-将屏幕涂成黑色 */
void ST7789_Clear(void);

/* 用颜色填充矩形的过程 */
void ST7789_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

/* 设置屏幕边框以填充的过程 */
void ST7789_SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

/* 将数据写入显示器的过程 */
void ST7789_RamWrite(uint16_t *pBuff, uint32_t Len);

/* 设置列的起始和结束地址的过程 */
static void ST7789_ColumnSet(uint16_t ColumnStart, uint16_t ColumnEnd);

/* 设置行起始和目标地址的过程 */
static void ST7789_RowSet(uint16_t RowStart, uint16_t RowEnd);

/* 背光控制程序（PWM） */
void ST7789_SetBL(uint8_t Value);

/* 打开/关闭显示器电源的过程 */
void ST7789_DisplayPower(uint8_t On);

/* 绘制矩形的过程（空心） */
void ST7789_DrawRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);

/* 辅助程序——绘制矩形的过程（已填充） */
static void SwapInt16Values(int16_t *pValue1, int16_t *pValue2);

/* 绘制矩形的过程（填充） */
void ST7789_DrawRectangleFilled(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t fillcolor);

/* 辅助程序——绘制线条的程序 */
static void ST7789_DrawLine_Slow(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);

/* 绘制线条的过程 */
void ST7789_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);

/* 绘制三角形的过程（空心） */
void ST7789_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);

/* 绘制三角形的过程（填充） */
void ST7789_DrawFilledTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);

/* 程序着色1像素显示 */
void ST7789_DrawPixel(int16_t x, int16_t y, uint16_t color);

/* 绘制圆的过程（已完成） */
void ST7789_DrawCircleFilled(int16_t x0, int16_t y0, int16_t radius, uint16_t fillcolor);

/* 绘制圆的过程（空心） */
void ST7789_DrawCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color);

/* 绘制符号的过程（1个字母或符号） */
void ST7789_DrawChar(uint16_t x, uint16_t y, uint16_t TextColor, uint16_t BgColor, uint8_t TransparentBg, FontDef_t* Font, uint8_t multiplier, unsigned char ch);

/* 绘制字符串的过程 */
void ST7789_print(uint16_t x, uint16_t y, uint16_t TextColor, uint16_t BgColor, uint8_t TransparentBg, FontDef_t* Font, uint8_t multiplier, char *str);

/* 旋转程序（模式）播放 
   PA默认模式1（共1、2、3、4）*/
void ST7789_rotation( uint8_t rotation );

/* 单色图标绘制程序 */
void ST7789_DrawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, int16_t w, int16_t h, uint16_t color);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif	/*	_ST7789_H */

/************************ (C) COPYRIGHT GKP *****END OF FILE****/
