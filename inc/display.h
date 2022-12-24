/*
 * disp_example.h
 *
 *  Created on: Dec 11, 2022
 *      Author: Stuart
 */

#ifndef INC_DISP_EXAMPLE_H_
#define INC_DISP_EXAMPLE_H_

#include <string.h>
#include <SI_EFM8BB3_Register_Enums.h>

// Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF

void lcdInit(void);
void Rcmd1();
void Rcmd2red();
void Rcmd2green();
void Rcmd3();
void fillScreen(unsigned int colour);
void fillRectangle(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour);
void setAddrWindow(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1);
void drawPixel(unsigned char x, unsigned char y, unsigned int colour);
void drawChar(unsigned char x, unsigned char y, unsigned char c, unsigned int colour, unsigned int bg,  unsigned char size);
void drawtextq(unsigned char x, unsigned char y, const char *_text, unsigned int color, unsigned int bg, unsigned char size);
void drawtext(unsigned char x, unsigned char y, const char *_text, unsigned int color, unsigned int bg, unsigned char size);
void setTextWrap(char w);
void fillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour) ;
void drawFastVLine(unsigned char x, unsigned char y, unsigned char h, unsigned int colour);
void drawFastHLine(unsigned char x, unsigned char y, unsigned char w, unsigned int color);
void drawLine(signed int x0, signed int y0, signed int x1, signed int y1, unsigned int colour);
void drawRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour);
void drawCircle(signed int x0, signed int y0, signed int r, unsigned int colour);
void drawCircleHelper(signed int x0, signed int y0, signed int r, unsigned char cornername, unsigned int colour);
void fillCircle(signed int x0, signed int y0, signed int r, unsigned int colour);
void fillCircleHelper(signed int x0, signed int y0, signed int r, unsigned char cornername, signed int delta, unsigned int colour);
void drawRoundRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned char r, unsigned int colour);
void fillRoundRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned char r, unsigned int colour);
void drawTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int colour);
void fillTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int colour);
void invertDisplay(unsigned char/*bit*/ i);
void setScrollDefinition(unsigned char top_fix_height, unsigned char bottom_fix_height, unsigned char/*bit*/ _scroll_direction);
void VerticalScroll(unsigned char _vsp);
void NormalDisplay();
int Color565(int r, int g, int b);
int bmpDraw(char x, char y, char *bmpname);

void spi_write(unsigned char dataa);
void lcd_write_data(unsigned char dataa);
void lcd_write_command(unsigned char dataa);


#endif /* INC_DISP_EXAMPLE_H_ */
