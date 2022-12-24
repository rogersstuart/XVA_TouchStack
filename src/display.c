//#include <pic16f877a.h>
//#include <htc.h>
#include  <stdlib.h>
#include "display.h"

//#include <xc.h>
//#include "ST7735.h"
#define _XTAL_FREQ 20000000
unsigned char testaa = 0;

unsigned char wrap = 1;
#define TRUE 1
#define FALSE 0
unsigned char colstart = 1, rowstart = 26, _tft_type;
#define _swap(a, b) { signed int t; t = a; a = b; b = t;}
#define _width         160
#define _height        80

//Command definitions

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09
#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13
#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E
#define ST7735_PTLAR   0x30
#define ST7735_VSCRDEF 0x33
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36
#define ST7735_VSCRSADD 0x37
#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6
#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5
#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD
#define ST7735_PWCTR6  0xFC
#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1




const unsigned char code font[]= {
0x00, 0x00, 0x00, 0x00, 0x00, // (space)
0x00, 0x00, 0x5F, 0x00, 0x00, // !
0x00, 0x07, 0x00, 0x07, 0x00, // "
0x14, 0x7F, 0x14, 0x7F, 0x14, // #
0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
0x23, 0x13, 0x08, 0x64, 0x62, // %
0x36, 0x49, 0x56, 0x20, 0x50, // &
0x00, 0x08, 0x07, 0x03, 0x00, // '
0x00, 0x1C, 0x22, 0x41, 0x00, // (
0x00, 0x41, 0x22, 0x1C, 0x00, // )
0x2A, 0x1C, 0x7F, 0x1C, 0x2A, // *
0x08, 0x08, 0x3E, 0x08, 0x08, // +
0x00, 0x80, 0x70, 0x30, 0x00, // ,
0x08, 0x08, 0x08, 0x08, 0x08, // -
0x00, 0x00, 0x60, 0x60, 0x00, // .
0x20, 0x10, 0x08, 0x04, 0x02, // /
0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
0x00, 0x42, 0x7F, 0x40, 0x00, // 1
0x72, 0x49, 0x49, 0x49, 0x46, // 2
0x21, 0x41, 0x49, 0x4D, 0x33, // 3
0x18, 0x14, 0x12, 0x7F, 0x10, // 4
0x27, 0x45, 0x45, 0x45, 0x39, // 5
0x3C, 0x4A, 0x49, 0x49, 0x31, // 6
0x41, 0x21, 0x11, 0x09, 0x07, // 7
0x36, 0x49, 0x49, 0x49, 0x36, // 8
0x46, 0x49, 0x49, 0x29, 0x1E, // 9
0x00, 0x00, 0x14, 0x00, 0x00, // :
0x00, 0x40, 0x34, 0x00, 0x00, // ;
0x00, 0x08, 0x14, 0x22, 0x41, // <
0x14, 0x14, 0x14, 0x14, 0x14, // =
0x00, 0x41, 0x22, 0x14, 0x08, // >
0x02, 0x01, 0x59, 0x09, 0x06, // ?
0x3E, 0x41, 0x5D, 0x59, 0x4E, // @
0x7C, 0x12, 0x11, 0x12, 0x7C, // A
0x7F, 0x49, 0x49, 0x49, 0x36, // B
0x3E, 0x41, 0x41, 0x41, 0x22, // C
0x7F, 0x41, 0x41, 0x41, 0x3E, // D
0x7F, 0x49, 0x49, 0x49, 0x41, // E
0x7F, 0x09, 0x09, 0x09, 0x01, // F
0x3E, 0x41, 0x41, 0x51, 0x73, // G
0x7F, 0x08, 0x08, 0x08, 0x7F, // H
0x00, 0x41, 0x7F, 0x41, 0x00, // I
0x20, 0x40, 0x41, 0x3F, 0x01, // J
0x7F, 0x08, 0x14, 0x22, 0x41, // K
0x7F, 0x40, 0x40, 0x40, 0x40, // L
0x7F, 0x02, 0x1C, 0x02, 0x7F, // M
0x7F, 0x04, 0x08, 0x10, 0x7F, // N
0x3E, 0x41, 0x41, 0x41, 0x3E, // O
0x7F, 0x09, 0x09, 0x09, 0x06, // P
0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
0x7F, 0x09, 0x19, 0x29, 0x46  // R
};

const unsigned char code font2[] = {
0x26, 0x49, 0x49, 0x49, 0x32, // S
0x03, 0x01, 0x7F, 0x01, 0x03,
0x3F, 0x40, 0x40, 0x40, 0x3F,
0x1F, 0x20, 0x40, 0x20, 0x1F,
0x3F, 0x40, 0x38, 0x40, 0x3F,
0x63, 0x14, 0x08, 0x14, 0x63,
0x03, 0x04, 0x78, 0x04, 0x03,
0x61, 0x59, 0x49, 0x4D, 0x43,
0x00, 0x7F, 0x41, 0x41, 0x41,
0x02, 0x04, 0x08, 0x10, 0x20,
0x00, 0x41, 0x41, 0x41, 0x7F,
0x04, 0x02, 0x01, 0x02, 0x04,
0x40, 0x40, 0x40, 0x40, 0x40,
0x00, 0x03, 0x07, 0x08, 0x00,
0x20, 0x54, 0x54, 0x78, 0x40,
0x7F, 0x28, 0x44, 0x44, 0x38,
0x38, 0x44, 0x44, 0x44, 0x28,
0x38, 0x44, 0x44, 0x28, 0x7F,
0x38, 0x54, 0x54, 0x54, 0x18,
0x00, 0x08, 0x7E, 0x09, 0x02,
0x18, 0xA4, 0xA4, 0x9C, 0x78,
0x7F, 0x08, 0x04, 0x04, 0x78,
0x00, 0x44, 0x7D, 0x40, 0x00,
0x20, 0x40, 0x40, 0x3D, 0x00,
0x7F, 0x10, 0x28, 0x44, 0x00,
0x00, 0x41, 0x7F, 0x40, 0x00,
0x7C, 0x04, 0x78, 0x04, 0x78,
0x7C, 0x08, 0x04, 0x04, 0x78,
0x38, 0x44, 0x44, 0x44, 0x38,
0xFC, 0x18, 0x24, 0x24, 0x18,
0x18, 0x24, 0x24, 0x18, 0xFC,
0x7C, 0x08, 0x04, 0x04, 0x08,
0x48, 0x54, 0x54, 0x54, 0x24,
0x04, 0x04, 0x3F, 0x44, 0x24,
0x3C, 0x40, 0x40, 0x20, 0x7C,
0x1C, 0x20, 0x40, 0x20, 0x1C,
0x3C, 0x40, 0x30, 0x40, 0x3C,
0x44, 0x28, 0x10, 0x28, 0x44,
0x4C, 0x90, 0x90, 0x90, 0x7C,
0x44, 0x64, 0x54, 0x4C, 0x44,
0x00, 0x08, 0x36, 0x41, 0x00,
0x00, 0x00, 0x77, 0x00, 0x00,
0x00, 0x41, 0x36, 0x08, 0x00,
0x02, 0x01, 0x02, 0x04, 0x02
};



//Pin definitions (For PIC18F26K40) - change as required
//NOTE: on older micros this will just be RC0, RC1, etc.
//On newer chips we have to use the latch registers.
#define CSX     P1_B1 //Chip select
#define RESX    P3_B4 //Reset pin
#define CMD     P0_B0 //Command select
//Software SPI pins if required
//#define SDO     LATC3
//#define SCK     LATC4

//Use hardware SPI, will just big bang it through if false
    #define USE_HW_SPI  1

//SPI Bus status register and transmission buffer
//Set these to suit your particular microcontroller
//    #define SPIBUF  SPI1TXB
//    #define SPIIDLE SPI1STATUS & 0x20


/*
 * Writes a byte to SPI without changing chip select (CSX) state.
 * Called by the write_command() and write_data() functions which
 * control these pins as required.
 *
 * This will use either a software implementation or the hardware
 * implementation depending on if USE_HW_SPI flag is set in the
 * header file. (Software SPI is reeeeeally slow. Measured at
 * 40 kHz clock compared to 2 MHz clock with hardware SPI).
 */
void __delay_ms(uint16_t ms)
{
  int i = 0;
  for(i = 0; i < ms*1000; i++);
}

uint8_t b1 = 0;
void spi_write(unsigned char dataa) {
  int i = 0;
  b1 = 0;

        //Write data to SSPBUFF
        SPI0DAT = dataa;
        //Wait for transmission to finish
        while(!(SPI0CN0_SPIF));
        b1 = SPI0DAT;
        SPI0CN0_SPIF = 0;


}

/*
 * Writes a data byte to the display. Pulls CS low as required.
 */
/*
void spi_write(unsigned char dataa)
{
  SPI0DAT = dataa; // Transfer The Data To The Buffer Register
   while(!SPI0CN0_TXNF); // Un-comment it if you're Not Using Interrupts!
  // The Above While Loop Protects Against Writing To The Buffer Before
  // The Previous Transmission Ends
}
*/

void lcd_write_data(unsigned char dataa) {
    //CS LOW
    CSX = 0;
    //Send data to the SPI register
    spi_write(dataa);
    //CS HIGH
    CSX = 1;
}

/*
 * Writes a command byte to the display
 */
void lcd_write_command(unsigned char dataa) {
    //Pull the command AND chip select lines LOW
    CMD = 0;
    CSX = 0;
    spi_write(dataa);
    //Return the control lines to HIGH
    CMD = 1;
    CSX = 1;
}

void lcdInit(void)
{
  uint8_t bk1 = 0;
  uint8_t bk2 = 0;
  uint8_t bk3 = 0;
  uint32_t total = 0;

  //SET control pins for the LCD HIGH (they are active LOW)
  CSX = 1; //CS
  CMD = 1; //Data / command select, the datasheet isn't clear on that.
  RESX = 1; //RESET pin HIGH

  //Cycle reset pin
  RESX = 0;
  __delay_ms(500);
  RESX = 1;
  __delay_ms(500);

  __delay_ms(500);

  Rcmd1();
  Rcmd2green();
  Rcmd3();
  lcd_write_command(ST7735_MADCTL);
  lcd_write_data(0xA0);
  lcd_write_command(0);
  _tft_type = 1;

  fillScreen (ST7735_BLACK);
}

void Rcmd1()
{
  lcd_write_command(ST7735_SWRESET);
  __delay_ms(150);
  lcd_write_command(ST7735_SLPOUT);
  __delay_ms(500);
  lcd_write_command(ST7735_FRMCTR1);
  lcd_write_data(0x01);
  lcd_write_data(0x2C);
  lcd_write_data(0x2D);
  lcd_write_command(ST7735_FRMCTR2);
  lcd_write_data(0x01);
  lcd_write_data(0x2C);
  lcd_write_data(0x2D);
  lcd_write_command(ST7735_FRMCTR3);
  lcd_write_data(0x01); lcd_write_data(0x2C); lcd_write_data(0x2D);
  lcd_write_data(0x01); lcd_write_data(0x2C); lcd_write_data(0x2D);
  lcd_write_command(ST7735_INVCTR);
  lcd_write_data(0x07);
  lcd_write_command(ST7735_PWCTR1);
  lcd_write_data(0xA2);
  lcd_write_data(0x02);
  lcd_write_data(0x84);
  lcd_write_command(ST7735_PWCTR2);
  lcd_write_data(0xC5);
  lcd_write_command(ST7735_PWCTR3);
  lcd_write_data(0x0A);
  lcd_write_data(0x00);
  lcd_write_command(ST7735_PWCTR4);
  lcd_write_data(0x8A);
  lcd_write_data(0x2A);
  lcd_write_command(ST7735_PWCTR5);
  lcd_write_data(0x8A);
  lcd_write_data(0xEE);
  lcd_write_command(ST7735_VMCTR1);
  lcd_write_data(0x0E);
  lcd_write_command(ST7735_INVON);
  lcd_write_command(ST7735_MADCTL);
  lcd_write_data(0xC8);
  lcd_write_command(ST7735_COLMOD);
  lcd_write_data(0x05);
}

void Rcmd2green()
{
  lcd_write_command(ST7735_CASET);
  lcd_write_data(0x00); lcd_write_data(0x02);
  lcd_write_data(0x00); lcd_write_data(0x7F + 0x02);
  lcd_write_command(ST7735_RASET);
  lcd_write_data(0x00); lcd_write_data(0x01);
  lcd_write_data(0x00); lcd_write_data(0x9F + 0x01);
}

void Rcmd3()
{
  lcd_write_command(ST7735_GMCTRP1);
  lcd_write_data(0x02); lcd_write_data(0x1C); lcd_write_data(0x07); lcd_write_data(0x12);
  lcd_write_data(0x37); lcd_write_data(0x32); lcd_write_data(0x29); lcd_write_data(0x2D);
  lcd_write_data(0x29); lcd_write_data(0x25); lcd_write_data(0x2B); lcd_write_data(0x39);
  lcd_write_data(0x00); lcd_write_data(0x01); lcd_write_data(0x03); lcd_write_data(0x10);
  lcd_write_command(ST7735_GMCTRN1);
  lcd_write_data(0x03); lcd_write_data(0x1D); lcd_write_data(0x07); lcd_write_data(0x06);
  lcd_write_data(0x2E); lcd_write_data(0x2C); lcd_write_data(0x29); lcd_write_data(0x2D);
  lcd_write_data(0x2E); lcd_write_data(0x2E); lcd_write_data(0x37); lcd_write_data(0x3F);
  lcd_write_data(0x00); lcd_write_data(0x00); lcd_write_data(0x02); lcd_write_data(0x10);
  lcd_write_command(ST7735_NORON);
  __delay_ms(10);
  lcd_write_command(ST7735_DISPON);
  __delay_ms(100);
}

void drawPixel(unsigned char x, unsigned char y, unsigned int colour)
{
  if((x >= _width) || (y >= _height))
  {
    return;
  }
  setAddrWindow(x,y,x+1,y+1);
  lcd_write_data(colour >> 8);
  lcd_write_data(colour & 0xFF);

  //lcd_write_command(ST7735_RASET);
}

void fillRectangle(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour)
{
  unsigned char hi, lo;

  if((x >= _width) || (y >= _height))
  {
    return;
  }
  if((x + w - 1) >= _width)
  {
    w = _width - x;
  }
  if((y + h - 1) >= _height)
  {
    h = _height - y;
  }
    //set_draw_window(x, y, x, y);
  setAddrWindow(x, y, x+w-1, y+h-1);
  hi = colour >> 8; lo = colour;
  //output_high(tft_dc);
//  CMD = 1; //Data / command select, the datasheet isn't clear on that.

  //output_low(tft_cs);
    CSX = 0;
  //Write colour to each pixel
  for(y=h; y>0; y--)
  {
    for(x = w; x > 0; x--)
    {
      spi_write(hi);
      spi_write(lo);

    }
  }
  CSX = 1;
  //lcd_write_command(ST7735_RASET);
}

void drawFastVLine(unsigned char x, unsigned char y, unsigned char h, unsigned int colour)
{
  unsigned char hi, lo;
  if((x >= _width) || (y >= _height))
    return;
  if((y + h - 1) >= _height)
    h = _height - y;
  hi = colour >> 8; lo = colour;
  setAddrWindow(x, y, x, y + h - 1);
  //output_high(tft_dc);
  //output_low(tft_cs);
//  CMD = 1; //Data / command select, the datasheet isn't clear on that.
  CSX = 0;
  while (h--)
  {
    spi_write(hi);
    spi_write(lo);
  }
  CSX = 1;
  //lcd_write_command(ST7735_RASET);
}

void drawFastHLine(unsigned char x, unsigned char y, unsigned char w, unsigned int color)
{
  unsigned char hi, lo;
  if((x >= _width) || (y >= _height))
  {
    return;
  }
  if((x + w - 1) >= _width)
  {
    w = _width - x;
  }
  hi = color >> 8; lo = color;
  setAddrWindow(x, y, x + w - 1, y);
  //output_high(tft_dc);
//  TFT_DC = 1;
  //output_low(tft_cs);
//  TFT_CS = 0;
  CSX = 0;
  while (w--)
  {
    spi_write(hi);
    spi_write(lo);
  }
  //output_high(tft_cs);
  //TFT_CS = 1;
  CSX = 1;
  //lcd_write_command(ST7735_RASET);
}



void fillScreen(unsigned int colour)
{
  fillRectangle(0, 0, _width, _height, colour);
}

void setAddrWindow(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1)
{
  lcd_write_command(ST7735_CASET);
  lcd_write_data(0x00);
  lcd_write_data(x0 + colstart);
  lcd_write_data(0x00);
  lcd_write_data(x1 + colstart);

  lcd_write_command(ST7735_RASET);
  lcd_write_data(0x00);
  lcd_write_data(y0 + rowstart);
  lcd_write_data(0x00);
  lcd_write_data(y1 + rowstart);
  lcd_write_command(ST7735_RAMWR); // Write to RAM


}


/*
 * Draws a single char to the screen.
 * Called by the various string writing functions like print().
 */


void drawChar(unsigned char x, unsigned char y, unsigned char c, unsigned int colour, unsigned int bg,  unsigned char size)
{
  unsigned char i, j;
  unsigned char line;
  unsigned char testcc = 0;
  if((x >= _width) || (y >= _height))
  {
    return;
  }
  if(size < 1)
  {
    size = 1;
  }
  if((c < ' ') || (c > '~'))
  {
    c = '?';
  }
  for(i=0; i<5; i++ )
  {
    if(c < 'S')
    {
      testcc = (c - 32)*(unsigned int)5 + i;
      line = font[testcc];
      //line = font[(c - 32)*(unsigned int)5 + i];
//      testaa = line;
    }
    else
    {
      testaa = (c - 'S')*(unsigned int)5 + i;
      line = font2[testaa];
      //line = font2[];
    }
    for(j=0; j<7; j++, line >>= 1)
    {
      if(line & 0x01)
      {
        if(size == 1)
        {
          drawPixel(x+i, y+j, colour);
        }
        else
        {
          fillRect(x+(i*size), y+(j*size), size, size, colour);
        }
      }
      else if(bg != colour)
      {
        if(size == 1)
        {
          drawPixel(x+i, y+j, bg);
        }
        else
        {
          fillRect(x+i*size, y+j*size, size, size, bg);
        }
      }
    }
  }
}


void fillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour)
{
  signed int i;
  // Update in subclasses if desired!
  for (i = x; i < x + w; i++)
  {
    drawFastVLine(i, y, h, colour);
  }
}


void setTextWrap(char w)
{
  wrap = w;
}

void drawtextq(unsigned char x, unsigned char y, const char *_text, unsigned int colour, unsigned int bg, unsigned char size)
{
  unsigned char cursor_x, cursor_y;
  unsigned int textsize, i;
  cursor_x = x, cursor_y = y;
  textsize = strlen(_text);
  for(i = 0; i < textsize; i++)
  {
    if(wrap && ((cursor_x + size * 5) > _width))
    {
      cursor_x = 0;
      cursor_y = cursor_y + size * 7 + 3 ;
      if(cursor_y > _height)
      {
        cursor_y = _height;
      }
      if(_text[i] == 0x20)
      {
        goto _skip;
      }
    }
    drawChar(cursor_x, cursor_y, _text[i], colour, bg, size);
    cursor_x = cursor_x + size * 6;
    if(cursor_x > _width)
    {
      cursor_x = _width;
    }
    _skip:;
  }

  //lcd_write_command(ST7735_RASET);
}


void drawtext(unsigned char x, unsigned char y, const char *_text, unsigned int colour, unsigned int bg, unsigned char size)
{
  unsigned char cursor_x, cursor_y;
  unsigned int textsize, i;
  cursor_x = x, cursor_y = y;
  textsize = strlen(_text);
  for(i = 0; i < textsize; i++)
  {
    if(wrap && ((cursor_x + size * 5) > _width))
    {
      cursor_x = 0;
      cursor_y = cursor_y + size * 7 + 3 ;
      if(cursor_y > _height)
      {
        cursor_y = _height;
      }
      if(_text[i] == 0x20)
      {
        goto _skip;
      }
    }
    drawChar(cursor_x, cursor_y * size *8, _text[i], colour, bg, size);
    cursor_x = cursor_x + size * 6;
    if(cursor_x > _width)
    {
      cursor_x = _width;
    }
    _skip:;
  }

  //lcd_write_command(ST7735_RASET);
}


void drawLine(signed int x0, signed int y0, signed int x1, signed int y1, unsigned int colour)
{
  signed int steep, dx, dy, err, ystep;
  //int steep;
  signed int yy, xx;
  steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep)
  {
    _swap(x0,y0);
    _swap(x1,y1);
  }
  if (x0 > x1)
  {
    _swap(x0,x1);
    _swap(y0,y1);
  }
  dx = x1 - x0;
  dy = abs((y1-y0));

  err = dx / 2;
  if (y0 < y1)
  {
    ystep = 1;
  } else
  {
    ystep = -1;
  }

  for (; x0<=x1; x0++)
  {
    if (steep)
    {
      drawPixel(y0, x0, colour);
    }
    else
    {
      drawPixel(x0, y0, colour);
    }
    err -= dy;
    if (err < 0)
    {
      y0 += ystep;
      err += dx;
    }
  }
}

void drawRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned int colour)
{
  drawFastHLine(x, y, w, colour);
  drawFastHLine(x, y + h - 1, w, colour);
  drawFastVLine(x, y, h, colour);
  drawFastVLine(x + w - 1, y, h, colour);
}

void drawCircle(signed int x0, signed int y0, signed int r, unsigned int colour)
{
  signed int f, ddF_x, ddF_y, x, y;
  f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
  drawPixel(x0  , y0 + r, colour);
  drawPixel(x0  , y0 - r, colour);
  drawPixel(x0+r, y0    , colour);
  drawPixel(x0-r, y0    , colour);
  while (x < y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    drawPixel(x0 + x, y0 + y, colour);
    drawPixel(x0 - x, y0 + y, colour);
    drawPixel(x0 + x, y0 - y, colour);
    drawPixel(x0 - x, y0 - y, colour);
    drawPixel(x0 + y, y0 + x, colour);
    drawPixel(x0 - y, y0 + x, colour);
    drawPixel(x0 + y, y0 - x, colour);
    drawPixel(x0 - y, y0 - x, colour);
  }
}

void drawCircleHelper(signed int x0, signed int y0, signed int r, unsigned char cornername, unsigned int colour)
{
  signed int f, ddF_x, ddF_y, x, y;
  f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
  while (x<y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    if (cornername & 0x4)
    {
      drawPixel(x0 + x, y0 + y, colour);
      drawPixel(x0 + y, y0 + x, colour);
    }
    if (cornername & 0x2)
    {
      drawPixel(x0 + x, y0 - y, colour);
      drawPixel(x0 + y, y0 - x, colour);
    }
    if (cornername & 0x8)
    {
      drawPixel(x0 - y, y0 + x, colour);
      drawPixel(x0 - x, y0 + y, colour);
    }
    if (cornername & 0x1)
    {
      drawPixel(x0 - y, y0 - x, colour);
      drawPixel(x0 - x, y0 - y, colour);
    }
  }
}

void fillCircle(signed int x0, signed int y0, signed int r, unsigned int colour)
{
  drawFastVLine(x0, y0 - r, 2 * r + 1, colour);
  fillCircleHelper(x0, y0, r, 3, 0, colour);
}

void fillCircleHelper(signed int x0, signed int y0, signed int r, unsigned char cornername, signed int delta, unsigned int colour)
{
  signed int f, ddF_x, ddF_y, x, y;
  f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
  while (x<y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;

    if (cornername & 0x1)
    {
      drawFastVLine(x0+x, y0-y, 2*y+1+delta, colour);
      drawFastVLine(x0+y, y0-x, 2*x+1+delta, colour);
    }
    if (cornername & 0x2)
    {
      drawFastVLine(x0-x, y0-y, 2*y+1+delta, colour);
      drawFastVLine(x0-y, y0-x, 2*x+1+delta, colour);
    }
  }
}

void drawRoundRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned char r, unsigned int colour)
{
  drawFastHLine(x+r  , y    , w-2*r, colour);
  drawFastHLine(x+r  , y+h-1, w-2*r, colour);
  drawFastVLine(x    , y+r  , h-2*r, colour);
  drawFastVLine(x+w-1, y+r  , h-2*r, colour);
  drawCircleHelper(x+r    , y+r    , r, 1, colour);
  drawCircleHelper(x+w-r-1, y+r    , r, 2, colour);
  drawCircleHelper(x+w-r-1, y+h-r-1, r, 4, colour);
  drawCircleHelper(x+r    , y+h-r-1, r, 8, colour);
}

void fillRoundRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned char r, unsigned int colour)
{
  fillRect(x+r, y, w-2*r, h, colour);
  fillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, colour);
  fillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, colour);
}

void drawTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int colour)
{
  drawLine(x0, y0, x1, y1, colour);
  drawLine(x1, y1, x2, y2, colour);
  drawLine(x2, y2, x0, y0, colour);
}

void fillTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int colour)
{
  signed int a, b, y, last, dx01, dy01, dx02, dy02, dx12, dy12, sa, sb;
  // Sort coordinates by Y order (y2 >= y1 >= y0)
  if (y0 > y1)
  {
    _swap(y0, y1);
    _swap(x0, x1);
  }
  if (y1 > y2)
  {
    _swap(y2, y1);
    _swap(x2, x1);
  }
  if (y0 > y1)
  {
    _swap(y0, y1); _swap(x0, x1);
  }
  if(y0 == y2)
  { // Handle awkward all-on-same-line case as its own thing
    a = b = x0;
    if(x1 < a)
    {
      a = x1;
    }
    else if(x1 > b)
    {
      b = x1;
    }
    if(x2 < a)
    {
      a = x2;
    }
    else if(x2 > b)
    {
      b = x2;
    }
    drawFastHLine(a, y0, b-a+1, colour);
    return;
  }
  dx01 = x1 - x0;
  dy01 = y1 - y0;
  dx02 = x2 - x0;
  dy02 = y2 - y0;
  dx12 = x2 - x1;
  dy12 = y2 - y1;
  sa   = 0;
  sb   = 0;
  if(y1 == y2)
  {
    last = y1;   // Include y1 scanline
  }
  else
  {
    last = y1-1; // Skip it
  }
  for(y=y0; y<=last; y++)
  {
    a   = x0 + sa / dy01;
    b   = x0 + sb / dy02;
    sa += dx01;
    sb += dx02;
    /* longhand:
    a = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
    b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
    */
    if(a > b)
    {
      _swap(a,b);
    }
    drawFastHLine(a, y, b - a + 1, colour);
  }
  // For lower part of triangle, find scanline crossings for segments
  // 0-2 and 1-2.  This loop is skipped if y1=y2.
  sa = dx12 * (y - y1);
  sb = dx02 * (y - y0);
  for(; y<=y2; y++)
  {
    a   = x1 + sa / dy12;
    b   = x0 + sb / dy02;
    sa += dx12;
    sb += dx02;
    /* longhand:
    a = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
    b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
    */
    if(a > b)
    {
      _swap(a,b);
    }
    drawFastHLine(a, y, b-a+1, colour);
  }
}

void invertDisplay(unsigned char/*bit*/ i)
{
  if(i)
  {
    lcd_write_command(ST7735_INVON);
  }
  else
  {
    lcd_write_command(ST7735_INVOFF);
  }
}

void setScrollDefinition(unsigned char top_fix_height, unsigned char bottom_fix_height, unsigned char/*bit*/ _scroll_direction)
{
  unsigned char scroll_height;
  scroll_height = _height - top_fix_height - bottom_fix_height;
  lcd_write_command(ST7735_VSCRDEF);
  lcd_write_data(0x00);
  lcd_write_data(top_fix_height);
  lcd_write_data(0x00);
  lcd_write_data(scroll_height);
  lcd_write_data(0x00);
  lcd_write_data(bottom_fix_height);
  lcd_write_command(ST7735_MADCTL);
  if(_scroll_direction)
  {
    if(_tft_type == 0)
    {
      lcd_write_data(0xD8);
    }
    if(_tft_type == 1)
    {
      lcd_write_data(0xD0);
    }
    if(_tft_type == 2)
    {
      lcd_write_data(0x18);
    }
  }
  else
  {
    if(_tft_type == 0)
    {
      lcd_write_data(0xC8);
    }
    if(_tft_type == 1)
    {
      lcd_write_data(0xC0);
    }
    if(_tft_type == 2)
    {
      lcd_write_data(0x08);
    }
  }
}

void VerticalScroll(unsigned char _vsp)
{
  lcd_write_command(ST7735_VSCRSADD);
  lcd_write_data(0x00);
  lcd_write_data(_vsp);
}

void NormalDisplay()
{
  lcd_write_command(ST7735_NORON);
}

int Color565(int r, int g, int b)
{           // Convert 24-bit color to 16-bit color
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

#if defined (DRAW_BMP_FROM_MMCSD_CARD)                       // Additional code for drawing BMP image files from MMC/SD card
#ifndef pixel_buffer
#define pixel_buffer  10
#endif
int bmpDraw(char x, char y, char *bmpname)
{
  int1 ec = 0, padding = 0;
  char bmpdata[pixel_buffer*3], planes, depth, r, g, b, col, row;
  int i, buffer=pixel_buffer*3, format, width, height, color;
  int32 offset, compression, bmp_size, row_size, padding_factor;
  if((x >= _width) || (y >= _height))
  {
    return 1;
  }
  if(fat16_open_file(bmpname) != 0)
  {
    return 1;
  }
  ec |= sdcard_read_byte(address_pointer + 1, &format);
  format <<= 8;
  ec |= sdcard_read_byte(address_pointer, &format);
  if(format != 0x4D42)
  {                                             // BMP file format signature
    return 1;
  }                                                      // Return error
  ec |= sdcard_read_byte(address_pointer + 0x0D, &offset);
  offset <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x0C, &offset);
  offset <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x0B, &offset);
  offset <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x0A, &offset);
  ec |= sdcard_read_byte(address_pointer + 0x13, &width);
  width <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x12, &width);
  ec |= sdcard_read_byte(address_pointer + 0x17, &height);
  height <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x16, &height);
  ec |= sdcard_read_byte(address_pointer + 0x1A, &planes);
  ec |= sdcard_read_byte(address_pointer + 0x1C, &depth);
  ec |= sdcard_read_byte(address_pointer + 0x21, &compression);
  compression <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x20, &compression);
  compression <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x1f, &compression);
  compression <<= 8;
  ec |= sdcard_read_byte(address_pointer + 0x1e, &compression);
  if(ec != 0 || compression != 0 || depth != 24 || planes != 1)
  {
    return 1;
  }
  bmp_size = file_size - offset;                                // bmp_size: BMP image raw size
  row_size = bmp_size/height;                                   // row_size: number of bytes per row
  if((x + width  - 1) >=  _width)
  {                              // _width is the TFT screen width
    width = _width  - x;
    padding = 1;                                                //Padding = 1 ==> only upper left part will be displayed
    padding_factor = width / pixel_buffer;
    if(width % pixel_buffer)
    {
      padding_factor++;
    }
    padding_factor *= buffer;
  }
  if((y + height - 1) >= _height)
  {                              // _height is the TFT screen height
    offset += row_size * (height - _height + y);                // Only upper part will be displayed
    height = _height - y;
  }
  file_pointer     = offset;
  address_pointer += offset;
  i = buffer;
  for(row = height; row > 0; row--)
  {
    for(col = 0; col < width; col++)
    {
      if(i >= buffer)
      {
        i = 0;
        if(fat16_read_data(buffer, bmpdata) != 0)
        {
          return 1;
        }
      }
      b = bmpdata[i++];
      g = bmpdata[i++];
      r = bmpdata[i++];
      color = Color565(r, g, b);
      drawPixel(x + col, y + row, color);
    }
    if(padding == 1)
    {
      i = buffer;
      file_pointer    += row_size - padding_factor;
      address_pointer += row_size - padding_factor;
    }
  }
  return 0;
}
#endif
