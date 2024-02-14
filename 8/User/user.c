/*
 * user.c
 *
 *  Created on: 1 февр. 2024 г.
 *      Author: Yuriy
 */
#include "user.h"
#include "echo.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_hal_uart.h"

#include "usart.h"
#include "usart1.h"
#include  "LED.h"




//#include "fonts.h"

//#include "font24.c"
//#include "font20.c"
//#include "font16.c"
//#include "font12.c"
//#include "font8.c"



//-------------------------------------------------------------------
typedef struct
{
	uint16_t TextColor;
	uint16_t BackColor;
	sFONT *pFont;
}LCD_DrawPropTypeDef;

LCD_DrawPropTypeDef lcdprop;

//------------------------------------------------

uint16_t TFT9341_WIDTH = 240;
uint16_t TFT9341_HEIGHT = 320;

void TFT9341_FontsIni(void)
{
  Font8.Height = 8;
  Font8.Width = 5;
  Font12.Height = 12;
  Font12.Width = 7;
  Font16.Height = 16;
  Font16.Width = 11;
  Font20.Height = 20;
  Font20.Width = 14;
  Font24.Height = 24;
  Font24.Width = 17;
  lcdprop.BackColor=TFT9341_BLACK;
  lcdprop.TextColor=TFT9341_GREEN;
  lcdprop.pFont=&Font16;
}

void TFT9341_SetTextColor(uint16_t color)
{
  lcdprop.TextColor=color;
}

void TFT9341_SetBackColor(uint16_t color)
{
  lcdprop.BackColor=color;
}

void TFT9341_SetFont(sFONT *pFonts)
{
  lcdprop.pFont=pFonts;
}
void TFT9341_DrawChar(uint16_t x, uint16_t y, uint8_t c)
{
  uint32_t i = 0, j = 0;
  uint16_t height, width;
  uint8_t offset;
  uint8_t *c_t;
  uint8_t *pchar;
  uint32_t line=0;
  height = lcdprop.pFont->Height;
  width  = lcdprop.pFont->Width;
  offset = 8 *((width + 7)/8) -  width ;
  c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' ') * lcdprop.pFont->Height * ((lcdprop.pFont->Width + 7) / 8)]);
  for(i = 0; i < height; i++)
  {
    pchar = ((uint8_t *)c_t + (width + 7)/8 * i);
    switch(((width + 7)/8))
    {
      case 1:
          line =  pchar[0];
          break;
      case 2:
          line =  (pchar[0]<< 8) | pchar[1];
          break;
      case 3:
      default:
        line =  (pchar[0]<< 16) | (pchar[1]<< 8) | pchar[2];
        break;
    }
    for (j = 0; j < width; j++)
    {
      if(line & (1 << (width- j + offset- 1)))
      {
        TFT9341_DrawPixel((x + j), y, lcdprop.TextColor);
      }
      else
      {
        TFT9341_DrawPixel((x + j), y, lcdprop.BackColor);
      }
    }
    y++;
  }
}
//-----------
void TFT9341_String(uint16_t x,uint16_t y, char *str)
{
  while(*str)
  {
    TFT9341_DrawChar(x,y,str[0]);
    x+=lcdprop.pFont->Width;
    (void)*str++;
  }
}
//--
void TFT9341_SetRotation(uint8_t r)
{
  TFT9341_SendCommand(0x36);
  switch(r)
  {
    case 0:
      TFT9341_SendData(0x48);
      TFT9341_WIDTH = 240;
      TFT9341_HEIGHT = 320;
      break;
    case 1:
      TFT9341_SendData(0x28);
      TFT9341_WIDTH = 320;
      TFT9341_HEIGHT = 240;
      break;
    case 2:
      TFT9341_SendData(0x88);
      TFT9341_WIDTH = 240;
      TFT9341_HEIGHT = 320;
      break;
    case 3:
      TFT9341_SendData(0xE8);
      TFT9341_WIDTH = 320;
      TFT9341_HEIGHT = 240;
      break;
  }
}

//------------------------------------------------



void Delay_ms (uint32_t delay ){
	uint32_t out = 0 ;

	while (delay--){
		out++ ;
	}
	return ;
}

void TFT9341_SendCommand(uint8_t cmd)
{
  DC_COMMAND();
  HAL_SPI_Transmit (&hspi5, &cmd, 1, 5000);
}

void TFT9341_SendData(uint8_t dt)
{
	DC_DATA();
	HAL_SPI_Transmit (&hspi5, &dt, 1, 5000);
}

void TFT9341_reset(void)
{
	RESET_ACTIVE();
	HAL_Delay(50);
	RESET_IDLE();
}
static void TFT9341_WriteData(uint8_t* buff, size_t buff_size) {
	DC_DATA();
	while(buff_size > 0) {
		uint16_t chunk_size = buff_size > 32768 ? 32768 : buff_size;
		HAL_SPI_Transmit(&hspi5, buff, chunk_size, HAL_MAX_DELAY);
		buff += chunk_size;
		buff_size -= chunk_size;
	}
}


void TFT9341_ini(uint16_t w_size, uint16_t h_size)
{
  uint8_t data[15];

  CS_ACTIVE();
  TFT9341_reset();
  TFT9341_SendCommand(0x01);
  //HAL_Delay(1000);
  HAL_Delay(1000);
  //Power Control A
  data[0] = 0x39;
  data[1] = 0x2C;
  data[2] = 0x00;
  data[3] = 0x34;
  data[4] = 0x02;
  TFT9341_SendCommand(0xCB);
  TFT9341_WriteData(data, 5);
  //Power Control B
  data[0] = 0x00;
  data[1] = 0xC1;
  data[2] = 0x30;
  TFT9341_SendCommand(0xCF);
  TFT9341_WriteData(data, 3);
  //Driver timing control A
  data[0] = 0x85;
  data[1] = 0x00;
  data[2] = 0x78;
  TFT9341_SendCommand(0xE8);
  TFT9341_WriteData(data, 3);
  //Driver timing control B
  data[0] = 0x00;
  data[1] = 0x00;
  TFT9341_SendCommand(0xEA);
  TFT9341_WriteData(data, 2);
  //Power on Sequence control
  data[0] = 0x64;
  data[1] = 0x03;
  data[2] = 0x12;
  data[3] = 0x81;
  TFT9341_SendCommand(0xED);
  TFT9341_WriteData(data, 4);
  //Pump ratio control
  data[0] = 0x20;
  TFT9341_SendCommand(0xF7);
  TFT9341_WriteData(data, 1);
  //Power Control,VRH[5:0]
  data[0] = 0x10;
  TFT9341_SendCommand(0xC0);
  TFT9341_WriteData(data, 1);
  //Power Control,SAP[2:0];BT[3:0]
  data[0] = 0x10;
  TFT9341_SendCommand(0xC1);
  TFT9341_WriteData(data, 1);
  //VCOM Control 1
  data[0] = 0x3E;
  data[1] = 0x28;
  TFT9341_SendCommand(0xC5);
  TFT9341_WriteData(data, 2);
  //VCOM Control 2
  data[0] = 0x86;
  TFT9341_SendCommand(0xC7);
  TFT9341_WriteData(data, 1);
  //Memory Acsess Control
  data[0] = 0x48;
  TFT9341_SendCommand(0x36);
  TFT9341_WriteData(data, 1);
  //Pixel Format Set
  data[0] = 0x55;//16bit
  TFT9341_SendCommand(0x3A);
  TFT9341_WriteData(data, 1);
  //Frame Rratio Control, Standard RGB Color
  data[0] = 0x00;
  data[1] = 0x18;
  TFT9341_SendCommand(0xB1);
  TFT9341_WriteData(data, 2);
  //Display Function Control
  data[0] = 0x08;
  data[1] = 0x82;
  data[2] = 0x27;//320 строк
  TFT9341_SendCommand(0xB6);
  TFT9341_WriteData(data, 3);
  //Enable 3G (пока не знаю что это за режим)
  data[0] = 0x00;//не включаем
  TFT9341_SendCommand(0xF2);
  TFT9341_WriteData(data, 1);
  //Gamma set
  data[0] = 0x01;//Gamma Curve (G2.2) (Кривая цветовой гаммы)
  TFT9341_SendCommand(0x26);
  TFT9341_WriteData(data, 1);
  //Positive Gamma  Correction
  data[0] = 0x0F;
  data[1] = 0x31;
  data[2] = 0x2B;
  data[3] = 0x0C;
  data[4] = 0x0E;
  data[5] = 0x08;
  data[6] = 0x4E;
  data[7] = 0xF1;
  data[8] = 0x37;
  data[9] = 0x07;
  data[10] = 0x10;
  data[11] = 0x03;
  data[12] = 0x0E;
  data[13] = 0x09;
  data[14] = 0x00;
  TFT9341_SendCommand(0xE0);
  TFT9341_WriteData(data, 15);
  //Negative Gamma  Correction
  data[0] = 0x00;
  data[1] = 0x0E;
  data[2] = 0x14;
  data[3] = 0x03;
  data[4] = 0x11;
  data[5] = 0x07;
  data[6] = 0x31;
  data[7] = 0xC1;
  data[8] = 0x48;
  data[9] = 0x08;
  data[10] = 0x0F;
  data[11] = 0x0C;
  data[12] = 0x31;
  data[13] = 0x36;
  data[14] = 0x0F;
  TFT9341_SendCommand(0xE1);
  TFT9341_WriteData(data, 15);
  TFT9341_SendCommand(0x11);//Выйдем из спящего режима
  HAL_Delay(120);
	  //Display ON
	  data[0] = TFT9341_ROTATION;
	  TFT9341_SendCommand(0x29);
	  TFT9341_WriteData(data, 1);

}

//-------------------------------------------------------------------
static void TFT9341_SetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  // column address set
  TFT9341_SendCommand(0x2A); // CASET
  {
    uint8_t data[] = { (x0 >> 8) & 0xFF, x0 & 0xFF, (x1 >> 8) & 0xFF, x1 & 0xFF };
    TFT9341_WriteData(data, sizeof(data));
  }

  // row address set
  TFT9341_SendCommand(0x2B); // RASET
  {
    uint8_t data[] = { (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF };
    TFT9341_WriteData(data, sizeof(data));
  }

  // write to RAM
  TFT9341_SendCommand(0x2C); // RAMWR
}//-------------------------------------------------------------------
void TFT9341_FillRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
  if((x1 >= TFT9341_WIDTH) || (y1 >= TFT9341_HEIGHT) || (x2 >= TFT9341_WIDTH) || (y2 >= TFT9341_HEIGHT)) return;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
  TFT9341_SetAddrWindow(x1, y1, x2, y2);
  uint8_t data[] = { color >> 8, color & 0xFF };
  DC_DATA();
  for(uint32_t i = 0; i < (x2-x1+1)*(y2-y1+1); i++)
  {
      HAL_SPI_Transmit(&hspi5, data, 2, HAL_MAX_DELAY);
  }
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void TFT9341_FillScreen(uint16_t color)
{
  TFT9341_FillRect(0, 0, TFT9341_WIDTH-1, TFT9341_HEIGHT-1, color);
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void TFT9341_DrawPixel(int x, int y, uint16_t color)
{
	if((x<0)||(y<0)||(x>=TFT9341_WIDTH)||(y>=TFT9341_HEIGHT)) return;
	TFT9341_SetAddrWindow(x,y,x,y);
	TFT9341_SendCommand(0x2C);
	TFT9341_SendData(color>>8);
	TFT9341_SendData(color & 0xFF);
}

void Print_text(void){
 //char str[32] = "string line" ;
 uint8_t X = 0, step = 0;
 	 step =  (TFT9341_WIDTH - X) - (2 - 5*17)/2;

	    TFT9341_SetTextColor(TFT9341_BLACK);
	    TFT9341_SetBackColor(TFT9341_WHITE);
	    TFT9341_SetFont(&Font24);
	    TFT9341_DrawChar( 1*17 + step,10,'S');
	    TFT9341_DrawChar( 2*17 + step,10,('t'));
	    TFT9341_DrawChar( 3*17 + step,10,('m'));
	    TFT9341_DrawChar( 4*17 + step,10,('3'));
	    TFT9341_DrawChar( 5*17 + step,10,('2'));
	    /*
	    TFT9341_SetTextColor(TFT9341_WHITE);
	    TFT9341_SetBackColor(TFT9341_BLUE);
	    TFT9341_SetFont(&Font20);
	    TFT9341_DrawChar(10,34,('S'));
	    TFT9341_DrawChar(24,34,('t'));
	    TFT9341_DrawChar(38,34,('m'));
	    TFT9341_DrawChar(52,34,('3'));
	    TFT9341_DrawChar(66,34,('2'));
	    TFT9341_SetTextColor(TFT9341_WHITE);
	    TFT9341_SetBackColor(TFT9341_RED);
	    TFT9341_SetFont(&Font16);
	    TFT9341_DrawChar(10,54,('S'));
	    TFT9341_DrawChar(21,54,('t'));
	    TFT9341_DrawChar(32,54,('m'));
	    TFT9341_DrawChar(43,54,('3'));
	    TFT9341_DrawChar(54,54,('2'));
	    TFT9341_SetTextColor(TFT9341_CYAN);
	    TFT9341_SetBackColor(TFT9341_BLACK);
	    TFT9341_SetFont(&Font12);
	    TFT9341_DrawChar(10,70,('S'));
	    TFT9341_DrawChar(17,70,('t'));
	    TFT9341_DrawChar(24,70,('m'));
	    TFT9341_DrawChar(31,70,('3'));
	    TFT9341_DrawChar(38,70,('2'));
	    TFT9341_SetTextColor(TFT9341_RED);
	    TFT9341_SetBackColor(TFT9341_GREEN);
	    TFT9341_SetFont(&Font8);
	    TFT9341_DrawChar(10,82,('S'));
	    TFT9341_DrawChar(15,82,('t'));
	    TFT9341_DrawChar(20,82,('m'));
	    TFT9341_DrawChar(25,82,('3'));
	    TFT9341_DrawChar(30,82,('2'));
	    TFT9341_SetTextColor(TFT9341_YELLOW);
	    TFT9341_SetBackColor(TFT9341_BLUE);
	    */
	    //HAL_Delay(2000);
	    //TFT9341_FillScreen(TFT9341_BLACK);


	    //TFT9341_String( 10, 134, "   string line number3");

}

void get_num( uint32_t *num ){

	*num = 10 ;

}



void print_num(uint32_t num ){
	//uint32_t num = 0 ;
	char buffer[11];
	//char buffer2[32];

	sprintf(buffer, "%10d", (int)num);
	TFT9341_String( 130, 114, buffer );


};





void zeroing_string(char *pData){

	while (*pData){

		pData[0] = (uint32_t )" ";
		pData++ ;
	}
}



void Display_welcomeScreen(void ){

TFT9341_ini(240, 320);
TFT9341_FontsIni();
TFT9341_FillScreen(TFT9341_BLACK);
TFT9341_SetRotation( 1 );

Print_text();

}

void print_text_distance(void){

	TFT9341_SetTextColor(TFT9341_WHITE);
    TFT9341_SetBackColor(TFT9341_BLACK);
    TFT9341_SetFont(&Font16);

    char str2[] = "   distance";

    TFT9341_String( 10, 114, str2);
}

void Get_Usonic_distance(){

	uint32_t distance =0 ;


		print_text_distance();

		start_USonic( &distance );
		distance = distance*((distance>0) & (distance <90)) ;

		print_num(distance);

}

void start(void)
{



	Leds_flash_on_start_led1_led2();

	Display_welcomeScreen();

	Get_Usonic_distance();



	  //while (1){


		  //transmitUSART_Transmit();
	  //}
	while (1){

		// receive only one message

		// wait in circle
		Get_time ();
		//Uart_Receive_IRQ_DMA();

	// Uart_Send_Recive();

	}



}

void Dispaly_init(void){

	  TFT9341_ini(240, 320);
	  TFT9341_FontsIni();
	  TFT9341_FillScreen(TFT9341_BLACK);
	  TFT9341_SetRotation( 1 );

}


/*
 * функция из примера пока не работает
 * чтение номера прерывания из прерыапния
 */

void SendString(void)
{
   // Проверка: откуда запущен код: из ISR или нет:
   if (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk)
   {
      /* Мы находимся в прерывании */
 //     TM_USART_Puts(USART2, "Вызвано из прерывания\n");
   }
   else
   {
      /* Обычный вызов, не из контекста прерывания */
  //    TM_USART_Puts(USART2, "Обычный контекст, вызов из тела main\n");
   }
}


void Start_2(){

	// init display
	//-----> Display_init();

	// print menu
	//----> Print_Menu();
	// choose menu
	// make job  - send
	//			- receive

	// разрешение . запрет прерываний (cpsiD)
	//int i = 1;
	 __asm
	volatile
	(
	"cpsie i"
	);

}

