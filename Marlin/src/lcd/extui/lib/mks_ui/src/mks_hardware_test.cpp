#include "../../../../../MarlinCore.h"
#if ENABLED(TFT_LITTLE_VGL_UI)
#include "../inc/tft_lvgl_configuration.h"
#include "lvgl.h"
#include "../../../../../feature/touch/xpt2046.h"
#include "../inc/draw_ready_print.h"
#include "../inc/W25Qxx.h"
#include "../inc/pic_manager.h"
//#include "../../MarlinCore.h"
#include "../inc/mks_hardware_test.h"
#include "../../../../../module/temperature.h"



#if ENABLED(MKS_TEST)

extern uint8_t curent_disp_ui;

uint8_t pw_det_sta,pw_off_sta,mt_det_sta,mt_det2_sta,mt_det3_sta;
uint8_t endstopx1_sta,endstopx2_sta,endstopy1_sta,endstopy2_sta,endstopz1_sta,endstopz2_sta;
void test_gpio_readlevel_L()
{
	volatile uint32_t itest;

  digitalWrite(WIFI_IO2_PIN, HIGH);
	itest = 10000;
	while(itest--);
	if(digitalRead(POWER_LOSS_PIN)==0)
	{
		pw_det_sta = 1;
	}
	else
	{
		pw_det_sta = 0;
	}
  if(digitalRead(PS_ON_PIN)==0)
	{
		pw_off_sta = 1;
	}
	else
	{
		pw_off_sta = 0;
	}
	if(digitalRead(FIL_RUNOUT_PIN)==0)
	{
		mt_det_sta = 1;
	}
	else
	{
		mt_det_sta = 0;
	}
	if(digitalRead(FIL_RUNOUT_2_PIN)==0)
	{
		mt_det2_sta = 1;
	}
	else
	{
		mt_det2_sta = 0;
	}	
  if(digitalRead(FIL_RUNOUT_3_PIN)==0)
	{
		mt_det3_sta = 1;
	}
	else
	{
		mt_det3_sta = 0;
	}	
	if(digitalRead(X_MIN_PIN)==0)
	{
		endstopx1_sta = 1;
	}
	else
	{
		endstopx1_sta = 0;
	}
  if(digitalRead(X_MAX_PIN)==0)
	{
		endstopx2_sta = 1;
	}
	else
	{
		endstopx2_sta = 0;
	}
	if(digitalRead(Y_MIN_PIN)==0)
	{
		endstopy1_sta = 1;
	}
	else
	{
		endstopy1_sta = 0;
	}
	if(digitalRead(Y_MAX_PIN)==0)
	{
		endstopy2_sta = 1;
	}
	else
	{
		endstopy2_sta = 0;
	}
	if(digitalRead(Z_MIN_PIN)==0)
	{
		endstopz1_sta = 1;
	}
	else
	{
		endstopz1_sta = 0;
	}
	if(digitalRead(Z_MAX_PIN)==0)
	{
		endstopz2_sta = 1;
	}
	else
	{
		endstopz2_sta = 0;
	}
}
void test_gpio_readlevel_H()
{
	volatile uint32_t itest;

  digitalWrite(WIFI_IO2_PIN, LOW);
	itest = 10000;
	while(itest--);
	if(digitalRead(POWER_LOSS_PIN)==1)
	{
		pw_det_sta = 1;
	}
	else
	{
		pw_det_sta = 0;
	}
  if(digitalRead(PS_ON_PIN)==1)
	{
		pw_off_sta = 1;
	}
	else
	{
		pw_off_sta = 0;
	}
	if(digitalRead(FIL_RUNOUT_PIN)==1)
	{
		mt_det_sta = 1;
	}
	else
	{
		mt_det_sta = 0;
	}
	if(digitalRead(FIL_RUNOUT_2_PIN)==1)
	{
		mt_det2_sta = 1;
	}
	else
	{
		mt_det2_sta = 0;
	}	
  if(digitalRead(FIL_RUNOUT_3_PIN)==1)
	{
		mt_det3_sta = 1;
	}
	else
	{
		mt_det3_sta = 0;
	}	
	if(digitalRead(X_MIN_PIN)==1)
	{
		endstopx1_sta = 1;
	}
	else
	{
		endstopx1_sta = 0;
	}
  if(digitalRead(X_MAX_PIN)==1)
	{
		endstopx2_sta = 1;
	}
	else
	{
		endstopx2_sta = 0;
	}
	if(digitalRead(Y_MIN_PIN)==1)
	{
		endstopy1_sta = 1;
	}
	else
	{
		endstopy1_sta = 0;
	}
	if(digitalRead(Y_MAX_PIN)==1)
	{
		endstopy2_sta = 1;
	}
	else
	{
		endstopy2_sta = 0;
	}
	if(digitalRead(Z_MIN_PIN)==1)
	{
		endstopz1_sta = 1;
	}
	else
	{
		endstopz1_sta = 0;
	}
	if(digitalRead(Z_MAX_PIN)==1)
	{
		endstopz2_sta = 1;
	}
	else
	{
		endstopz2_sta = 0;
	}
}
void init_Tst_GPIO()
{
  pinMode(X_MIN_PIN, INPUT_PULLUP);
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MIN_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MIN_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);
  
  pinMode(WIFI_IO2_PIN, OUTPUT);

  pinMode(FIL_RUNOUT_PIN, INPUT_PULLUP);
  pinMode(FIL_RUNOUT_2_PIN, INPUT_PULLUP);
  pinMode(FIL_RUNOUT_3_PIN, INPUT_PULLUP);

  pinMode(POWER_LOSS_PIN, INPUT_PULLUP);
  pinMode(PS_ON_PIN, INPUT_PULLUP);

  pinMode(SERVO0_PIN, INPUT_PULLUP);

  pinMode(E0_ENABLE_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);

  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(E0_ENABLE_PIN, LOW);
  digitalWrite(E1_ENABLE_PIN, LOW);
  digitalWrite(E2_ENABLE_PIN, LOW);
}

void mks_test_beeper(){
	digitalWrite(BEEPER_PIN, HIGH);
	delay(100);
	digitalWrite(BEEPER_PIN, LOW);
	delay(100);
}

void Test_GPIO()
{
  init_Tst_GPIO();

  test_gpio_readlevel_L();
	test_gpio_readlevel_H();
	test_gpio_readlevel_L();  
  if((pw_det_sta == 1)&&(mt_det_sta == 1)&&(mt_det2_sta == 1)&&(mt_det3_sta == 1))
	{
    		if(curent_disp_ui == 1)
		    disp_det_ok();
	}
	else
	{
		if(curent_disp_ui == 1)
    		disp_det_error();
	}
	if((endstopx1_sta== 1)
    &&(endstopx2_sta== 1)
		&&(endstopy1_sta== 1)
    &&(endstopy2_sta== 1)
		&&(endstopz1_sta== 1)
		&&(endstopz2_sta== 1))
	{
		if(curent_disp_ui == 1)
    {
      disp_Limit_ok();
    }
	}
	else
	{
		if(curent_disp_ui == 1)
    {
      disp_Limit_error();
      //mks_test_beeper();
    }	
	}
}

void mks_test(){
	if(millis() % 2000 <1000){
		digitalWrite(X_DIR_PIN, LOW);
		digitalWrite(Y_DIR_PIN, LOW);
		digitalWrite(Z_DIR_PIN, LOW);
		digitalWrite(E0_DIR_PIN, LOW);
		digitalWrite(E1_DIR_PIN, LOW);
    digitalWrite(E2_DIR_PIN, LOW);
    thermalManager.fan_speed[0] = 255;
    digitalWrite(HEATER_2_PIN, HIGH);//HE2
		digitalWrite(HEATER_1_PIN, HIGH);//HE1
    digitalWrite(HEATER_0_PIN, HIGH);//HE0
    digitalWrite(HEATER_BED_PIN, HIGH);//HOT-BED
	}
	else{
		digitalWrite(X_DIR_PIN, HIGH);
		digitalWrite(Y_DIR_PIN, HIGH);
		digitalWrite(Z_DIR_PIN, HIGH);
		digitalWrite(E0_DIR_PIN, HIGH);
		digitalWrite(E1_DIR_PIN, HIGH);
    digitalWrite(E2_DIR_PIN, HIGH);
    thermalManager.fan_speed[0] = 0;
    digitalWrite(HEATER_2_PIN, LOW);//HE2
		digitalWrite(HEATER_1_PIN, LOW);//HE1
    digitalWrite(HEATER_0_PIN, LOW);//HE0
    digitalWrite(HEATER_BED_PIN, LOW);//HOT-BED
	}
		if((endstopx1_sta== 1)
    &&(endstopx2_sta== 1)
		&&(endstopy1_sta== 1)
    &&(endstopy2_sta== 1)
		&&(endstopz1_sta== 1)
		&&(endstopz2_sta== 1))
		{
			
		}
		else
		{
			mks_test_beeper();
		}
		
		if(curent_disp_ui == 1)
		{
			disp_test();
		}
    
	}

#endif
const uint16_t ASCII_Table_16x24[] =
{
/** 
  * @brief        Space ' '  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '!'  
  */ 
         0x0000, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0000, 0x0000,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '"'  
  */ 
         0x0000, 0x0000, 0x00CC, 0x00CC, 0x00CC, 0x00CC, 0x00CC, 0x00CC,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '#'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C60, 0x0C60,
         0x0C60, 0x0630, 0x0630, 0x1FFE, 0x1FFE, 0x0630, 0x0738, 0x0318,
         0x1FFE, 0x1FFE, 0x0318, 0x0318, 0x018C, 0x018C, 0x018C, 0x0000,
/** 
  * @brief        '$'  
  */ 
         0x0000, 0x0080, 0x03E0, 0x0FF8, 0x0E9C, 0x1C8C, 0x188C, 0x008C,
         0x0098, 0x01F8, 0x07E0, 0x0E80, 0x1C80, 0x188C, 0x188C, 0x189C,
         0x0CB8, 0x0FF0, 0x03E0, 0x0080, 0x0080, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '%'  
  */ 
         0x0000, 0x0000, 0x0000, 0x180E, 0x0C1B, 0x0C11, 0x0611, 0x0611,
         0x0311, 0x0311, 0x019B, 0x018E, 0x38C0, 0x6CC0, 0x4460, 0x4460,
         0x4430, 0x4430, 0x4418, 0x6C18, 0x380C, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '&'  
  */ 
         0x0000, 0x01E0, 0x03F0, 0x0738, 0x0618, 0x0618, 0x0330, 0x01F0,
         0x00F0, 0x00F8, 0x319C, 0x330E, 0x1E06, 0x1C06, 0x1C06, 0x3F06,
         0x73FC, 0x21F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '''  
  */ 
         0x0000, 0x0000, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '('  
  */ 
         0x0000, 0x0200, 0x0300, 0x0180, 0x00C0, 0x00C0, 0x0060, 0x0060,
         0x0030, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030,
         0x0060, 0x0060, 0x00C0, 0x00C0, 0x0180, 0x0300, 0x0200, 0x0000,
/** 
  * @brief        ')'  
  */ 
         0x0000, 0x0020, 0x0060, 0x00C0, 0x0180, 0x0180, 0x0300, 0x0300,
         0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600,
         0x0300, 0x0300, 0x0180, 0x0180, 0x00C0, 0x0060, 0x0020, 0x0000,
/** 
  * @brief        '*'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00C0, 0x00C0,
         0x06D8, 0x07F8, 0x01E0, 0x0330, 0x0738, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '+'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x3FFC, 0x3FFC, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        ','  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0180, 0x0180, 0x0100, 0x0100, 0x0080, 0x0000, 0x0000,
/** 
  * @brief        '-'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '.'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '/'  
  */ 
         0x0000, 0x0C00, 0x0C00, 0x0600, 0x0600, 0x0600, 0x0300, 0x0300,
         0x0300, 0x0380, 0x0180, 0x0180, 0x0180, 0x00C0, 0x00C0, 0x00C0,
         0x0060, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '0'  
  */ 
         0x0000, 0x03E0, 0x07F0, 0x0E38, 0x0C18, 0x180C, 0x180C, 0x180C,
         0x180C, 0x180C, 0x180C, 0x180C, 0x180C, 0x180C, 0x0C18, 0x0E38,
         0x07F0, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '1'  
  */ 
         0x0000, 0x0100, 0x0180, 0x01C0, 0x01F0, 0x0198, 0x0188, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '2'  
  */ 
         0x0000, 0x03E0, 0x0FF8, 0x0C18, 0x180C, 0x180C, 0x1800, 0x1800,
         0x0C00, 0x0600, 0x0300, 0x0180, 0x00C0, 0x0060, 0x0030, 0x0018,
         0x1FFC, 0x1FFC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '3'  
  */ 
         0x0000, 0x01E0, 0x07F8, 0x0E18, 0x0C0C, 0x0C0C, 0x0C00, 0x0600,
         0x03C0, 0x07C0, 0x0C00, 0x1800, 0x1800, 0x180C, 0x180C, 0x0C18,
         0x07F8, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '4'  
  */ 
         0x0000, 0x0C00, 0x0E00, 0x0F00, 0x0F00, 0x0D80, 0x0CC0, 0x0C60,
         0x0C60, 0x0C30, 0x0C18, 0x0C0C, 0x3FFC, 0x3FFC, 0x0C00, 0x0C00,
         0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '5'  
  */ 
         0x0000, 0x0FF8, 0x0FF8, 0x0018, 0x0018, 0x000C, 0x03EC, 0x07FC,
         0x0E1C, 0x1C00, 0x1800, 0x1800, 0x1800, 0x180C, 0x0C1C, 0x0E18,
         0x07F8, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '6'  
  */ 
         0x0000, 0x07C0, 0x0FF0, 0x1C38, 0x1818, 0x0018, 0x000C, 0x03CC,
         0x0FEC, 0x0E3C, 0x1C1C, 0x180C, 0x180C, 0x180C, 0x1C18, 0x0E38,
         0x07F0, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '7'  
  */ 
         0x0000, 0x1FFC, 0x1FFC, 0x0C00, 0x0600, 0x0600, 0x0300, 0x0380,
         0x0180, 0x01C0, 0x00C0, 0x00E0, 0x0060, 0x0060, 0x0070, 0x0030,
         0x0030, 0x0030, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '8'  
  */ 
         0x0000, 0x03E0, 0x07F0, 0x0E38, 0x0C18, 0x0C18, 0x0C18, 0x0638,
         0x07F0, 0x07F0, 0x0C18, 0x180C, 0x180C, 0x180C, 0x180C, 0x0C38,
         0x0FF8, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '9'  
  */ 
         0x0000, 0x03E0, 0x07F0, 0x0E38, 0x0C1C, 0x180C, 0x180C, 0x180C,
         0x1C1C, 0x1E38, 0x1BF8, 0x19E0, 0x1800, 0x0C00, 0x0C00, 0x0E1C,
         0x07F8, 0x01F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        ':'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0180, 0x0180,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        ';'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0180, 0x0180,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0180, 0x0180, 0x0100, 0x0100, 0x0080, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '<'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x1000, 0x1C00, 0x0F80, 0x03E0, 0x00F8, 0x0018, 0x00F8, 0x03E0,
         0x0F80, 0x1C00, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '='  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x1FF8, 0x0000, 0x0000, 0x0000, 0x1FF8, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '>'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0008, 0x0038, 0x01F0, 0x07C0, 0x1F00, 0x1800, 0x1F00, 0x07C0,
         0x01F0, 0x0038, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '?'  
  */ 
         0x0000, 0x03E0, 0x0FF8, 0x0C18, 0x180C, 0x180C, 0x1800, 0x0C00,
         0x0600, 0x0300, 0x0180, 0x00C0, 0x00C0, 0x00C0, 0x0000, 0x0000,
         0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '@'  
  */ 
         0x0000, 0x0000, 0x07E0, 0x1818, 0x2004, 0x29C2, 0x4A22, 0x4411,
         0x4409, 0x4409, 0x4409, 0x2209, 0x1311, 0x0CE2, 0x4002, 0x2004,
         0x1818, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'A'  
  */ 
         0x0000, 0x0380, 0x0380, 0x06C0, 0x06C0, 0x06C0, 0x0C60, 0x0C60,
         0x1830, 0x1830, 0x1830, 0x3FF8, 0x3FF8, 0x701C, 0x600C, 0x600C,
         0xC006, 0xC006, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'B'  
  */ 
         0x0000, 0x03FC, 0x0FFC, 0x0C0C, 0x180C, 0x180C, 0x180C, 0x0C0C,
         0x07FC, 0x0FFC, 0x180C, 0x300C, 0x300C, 0x300C, 0x300C, 0x180C,
         0x1FFC, 0x07FC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'C'  
  */ 
         0x0000, 0x07C0, 0x1FF0, 0x3838, 0x301C, 0x700C, 0x6006, 0x0006,
         0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x6006, 0x700C, 0x301C,
         0x1FF0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'D'  
  */ 
         0x0000, 0x03FE, 0x0FFE, 0x0E06, 0x1806, 0x1806, 0x3006, 0x3006,
         0x3006, 0x3006, 0x3006, 0x3006, 0x3006, 0x1806, 0x1806, 0x0E06,
         0x0FFE, 0x03FE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'E'  
  */ 
         0x0000, 0x3FFC, 0x3FFC, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C,
         0x1FFC, 0x1FFC, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C,
         0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'F'  
  */ 
         0x0000, 0x3FF8, 0x3FF8, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018,
         0x1FF8, 0x1FF8, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018,
         0x0018, 0x0018, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'G'  
  */ 
         0x0000, 0x0FE0, 0x3FF8, 0x783C, 0x600E, 0xE006, 0xC007, 0x0003,
         0x0003, 0xFE03, 0xFE03, 0xC003, 0xC007, 0xC006, 0xC00E, 0xF03C,
         0x3FF8, 0x0FE0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'H'  
  */ 
         0x0000, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C,
         0x3FFC, 0x3FFC, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C,
         0x300C, 0x300C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'I'  
  */ 
         0x0000, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'J'  
  */ 
         0x0000, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600,
         0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0618, 0x0618, 0x0738,
         0x03F0, 0x01E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'K'  
  */ 
         0x0000, 0x3006, 0x1806, 0x0C06, 0x0606, 0x0306, 0x0186, 0x00C6,
         0x0066, 0x0076, 0x00DE, 0x018E, 0x0306, 0x0606, 0x0C06, 0x1806,
         0x3006, 0x6006, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'L'  
  */ 
         0x0000, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018,
         0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018,
         0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'M'  
  */ 
         0x0000, 0xE00E, 0xF01E, 0xF01E, 0xF01E, 0xD836, 0xD836, 0xD836,
         0xD836, 0xCC66, 0xCC66, 0xCC66, 0xC6C6, 0xC6C6, 0xC6C6, 0xC6C6,
         0xC386, 0xC386, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'N'  
  */ 
         0x0000, 0x300C, 0x301C, 0x303C, 0x303C, 0x306C, 0x306C, 0x30CC,
         0x30CC, 0x318C, 0x330C, 0x330C, 0x360C, 0x360C, 0x3C0C, 0x3C0C,
         0x380C, 0x300C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'O'  
  */ 
         0x0000, 0x07E0, 0x1FF8, 0x381C, 0x700E, 0x6006, 0xC003, 0xC003,
         0xC003, 0xC003, 0xC003, 0xC003, 0xC003, 0x6006, 0x700E, 0x381C,
         0x1FF8, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'P'  
  */ 
         0x0000, 0x0FFC, 0x1FFC, 0x380C, 0x300C, 0x300C, 0x300C, 0x300C,
         0x180C, 0x1FFC, 0x07FC, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C,
         0x000C, 0x000C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'Q'  
  */ 
         0x0000, 0x07E0, 0x1FF8, 0x381C, 0x700E, 0x6006, 0xE003, 0xC003,
         0xC003, 0xC003, 0xC003, 0xC003, 0xE007, 0x6306, 0x3F0E, 0x3C1C,
         0x3FF8, 0xF7E0, 0xC000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'R'  
  */ 
         0x0000, 0x0FFE, 0x1FFE, 0x3806, 0x3006, 0x3006, 0x3006, 0x3806,
         0x1FFE, 0x07FE, 0x0306, 0x0606, 0x0C06, 0x1806, 0x1806, 0x3006,
         0x3006, 0x6006, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'S'  
  */ 
         0x0000, 0x03E0, 0x0FF8, 0x0C1C, 0x180C, 0x180C, 0x000C, 0x001C,
         0x03F8, 0x0FE0, 0x1E00, 0x3800, 0x3006, 0x3006, 0x300E, 0x1C1C,
         0x0FF8, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'T'  
  */ 
         0x0000, 0x7FFE, 0x7FFE, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'U'  
  */ 
         0x0000, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C,
         0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x300C, 0x1818,
         0x1FF8, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'V'  
  */ 
         0x0000, 0x6003, 0x3006, 0x3006, 0x3006, 0x180C, 0x180C, 0x180C,
         0x0C18, 0x0C18, 0x0E38, 0x0630, 0x0630, 0x0770, 0x0360, 0x0360,
         0x01C0, 0x01C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'W'  
  */ 
         0x0000, 0x6003, 0x61C3, 0x61C3, 0x61C3, 0x3366, 0x3366, 0x3366,
         0x3366, 0x3366, 0x3366, 0x1B6C, 0x1B6C, 0x1B6C, 0x1A2C, 0x1E3C,
         0x0E38, 0x0E38, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'X'  
  */ 
         0x0000, 0xE00F, 0x700C, 0x3018, 0x1830, 0x0C70, 0x0E60, 0x07C0,
         0x0380, 0x0380, 0x03C0, 0x06E0, 0x0C70, 0x1C30, 0x1818, 0x300C,
         0x600E, 0xE007, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'Y'  
  */ 
         0x0000, 0xC003, 0x6006, 0x300C, 0x381C, 0x1838, 0x0C30, 0x0660,
         0x07E0, 0x03C0, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'Z'  
  */ 
         0x0000, 0x7FFC, 0x7FFC, 0x6000, 0x3000, 0x1800, 0x0C00, 0x0600,
         0x0300, 0x0180, 0x00C0, 0x0060, 0x0030, 0x0018, 0x000C, 0x0006,
         0x7FFE, 0x7FFE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '['  
  */ 
         0x0000, 0x03E0, 0x03E0, 0x0060, 0x0060, 0x0060, 0x0060, 0x0060,
         0x0060, 0x0060, 0x0060, 0x0060, 0x0060, 0x0060, 0x0060, 0x0060,
         0x0060, 0x0060, 0x0060, 0x0060, 0x0060, 0x03E0, 0x03E0, 0x0000,
/** 
  * @brief        '\'  
  */ 
         0x0000, 0x0030, 0x0030, 0x0060, 0x0060, 0x0060, 0x00C0, 0x00C0,
         0x00C0, 0x01C0, 0x0180, 0x0180, 0x0180, 0x0300, 0x0300, 0x0300,
         0x0600, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        ']'  
  */ 
         0x0000, 0x03E0, 0x03E0, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,
         0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,
         0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x03E0, 0x03E0, 0x0000,
/** 
  * @brief        '^'  
  */ 
         0x0000, 0x0000, 0x01C0, 0x01C0, 0x0360, 0x0360, 0x0360, 0x0630,
         0x0630, 0x0C18, 0x0C18, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '_'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '''  
  */ 
         0x0000, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'a'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03F0, 0x07F8,
         0x0C1C, 0x0C0C, 0x0F00, 0x0FF0, 0x0CF8, 0x0C0C, 0x0C0C, 0x0F1C,
         0x0FF8, 0x18F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'b'  
  */ 
         0x0000, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x03D8, 0x0FF8,
         0x0C38, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x0C38,
         0x0FF8, 0x03D8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'c'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03C0, 0x07F0,
         0x0E30, 0x0C18, 0x0018, 0x0018, 0x0018, 0x0018, 0x0C18, 0x0E30,
         0x07F0, 0x03C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'd'  
  */ 
         0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1BC0, 0x1FF0,
         0x1C30, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1C30,
         0x1FF0, 0x1BC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'e'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03C0, 0x0FF0,
         0x0C30, 0x1818, 0x1FF8, 0x1FF8, 0x0018, 0x0018, 0x1838, 0x1C30,
         0x0FF0, 0x07C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'f'  
  */ 
         0x0000, 0x0F80, 0x0FC0, 0x00C0, 0x00C0, 0x00C0, 0x07F0, 0x07F0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'g'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0DE0, 0x0FF8,
         0x0E18, 0x0C0C, 0x0C0C, 0x0C0C, 0x0C0C, 0x0C0C, 0x0C0C, 0x0E18,
         0x0FF8, 0x0DE0, 0x0C00, 0x0C0C, 0x061C, 0x07F8, 0x01F0, 0x0000,
/** 
  * @brief        'h'  
  */ 
         0x0000, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x07D8, 0x0FF8,
         0x1C38, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818,
         0x1818, 0x1818, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'i'  
  */ 
         0x0000, 0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'j'  
  */ 
         0x0000, 0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00F8, 0x0078, 0x0000,
/** 
  * @brief        'k'  
  */ 
         0x0000, 0x000C, 0x000C, 0x000C, 0x000C, 0x000C, 0x0C0C, 0x060C,
         0x030C, 0x018C, 0x00CC, 0x006C, 0x00FC, 0x019C, 0x038C, 0x030C,
         0x060C, 0x0C0C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'l'  
  */ 
         0x0000, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'm'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3C7C, 0x7EFF,
         0xE3C7, 0xC183, 0xC183, 0xC183, 0xC183, 0xC183, 0xC183, 0xC183,
         0xC183, 0xC183, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'n'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0798, 0x0FF8,
         0x1C38, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818,
         0x1818, 0x1818, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'o'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03C0, 0x0FF0,
         0x0C30, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x0C30,
         0x0FF0, 0x03C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'p'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03D8, 0x0FF8,
         0x0C38, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x0C38,
         0x0FF8, 0x03D8, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0000,
/** 
  * @brief        'q'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1BC0, 0x1FF0,
         0x1C30, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1C30,
         0x1FF0, 0x1BC0, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x0000,
/** 
  * @brief        'r'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07B0, 0x03F0,
         0x0070, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030, 0x0030,
         0x0030, 0x0030, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        's'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03E0, 0x03F0,
         0x0E38, 0x0C18, 0x0038, 0x03F0, 0x07C0, 0x0C00, 0x0C18, 0x0E38,
         0x07F0, 0x03E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        't'  
  */ 
         0x0000, 0x0000, 0x0080, 0x00C0, 0x00C0, 0x00C0, 0x07F0, 0x07F0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x07C0, 0x0780, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'u'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1818, 0x1818,
         0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1C38,
         0x1FF0, 0x19E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'v'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x180C, 0x0C18,
         0x0C18, 0x0C18, 0x0630, 0x0630, 0x0630, 0x0360, 0x0360, 0x0360,
         0x01C0, 0x01C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'w'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x41C1, 0x41C1,
         0x61C3, 0x6363, 0x6363, 0x6363, 0x3636, 0x3636, 0x3636, 0x1C1C,
         0x1C1C, 0x1C1C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'x'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x381C, 0x1C38,
         0x0C30, 0x0660, 0x0360, 0x0360, 0x0360, 0x0360, 0x0660, 0x0C30,
         0x1C38, 0x381C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        'y'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3018, 0x1830,
         0x1830, 0x1870, 0x0C60, 0x0C60, 0x0CE0, 0x06C0, 0x06C0, 0x0380,
         0x0380, 0x0380, 0x0180, 0x0180, 0x01C0, 0x00F0, 0x0070, 0x0000,
/** 
  * @brief        'z'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FFC, 0x1FFC,
         0x0C00, 0x0600, 0x0300, 0x0180, 0x00C0, 0x0060, 0x0030, 0x0018,
         0x1FFC, 0x1FFC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/** 
  * @brief        '{'  
  */ 
         0x0000, 0x0300, 0x0180, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0,
         0x00C0, 0x0060, 0x0060, 0x0030, 0x0060, 0x0040, 0x00C0, 0x00C0,
         0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x0180, 0x0300, 0x0000, 0x0000,
/** 
  * @brief        '|'  
  */ 
         0x0000, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0000,
/** 
  * @brief        '}'  
  */ 
         0x0000, 0x0060, 0x00C0, 0x01C0, 0x0180, 0x0180, 0x0180, 0x0180,
         0x0180, 0x0300, 0x0300, 0x0600, 0x0300, 0x0100, 0x0180, 0x0180,
         0x0180, 0x0180, 0x0180, 0x0180, 0x00C0, 0x0060, 0x0000, 0x0000,
/** 
  * @brief        '~'  
  */ 
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x10F0, 0x1FF8, 0x0F08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
void disp_char_1624(uint16_t x,uint16_t y,uint8_t c,uint16_t charColor,uint16_t bkColor)
{

  uint16_t i=0;
  uint16_t j=0;
  
  uint16_t tmp_char=0;

    for (i=0;i<24;i++)
    {
      tmp_char=ASCII_Table_16x24[((c-0x20)*24)+i];
      for (j=0;j<16;j++)
      {
        if ( ((tmp_char >> j) & 0x01) == 0x01)
          {
          	tft_set_point(x+j,y+i,charColor);
          }
          else
          {
          	tft_set_point(x+j,y+i,bkColor);
          }
      }
    }
  
}

void disp_string(uint16_t x,uint16_t y,const char * string,uint16_t charColor,uint16_t bkColor)
{
	while(*string != '\0')
	{
		disp_char_1624(x,y,*string,charColor,bkColor);
		string++;
		x+=16;
	}
}

//static lv_obj_t * scr_test;
void disp_pic_update()
{
	LCD_Clear(0x0000);
	disp_string(120,150,"PIC Updating...",0xffff,0x0000);
}

void disp_font_update()
{
	LCD_Clear(0x0000);
	disp_string(120,150,"FONT Updating...",0xffff,0x0000);
}


#endif

