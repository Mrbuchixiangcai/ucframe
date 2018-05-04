#include "platform.h"
//#include "public.h"
#include  "adc.h"
#include "param.h"
/*****************************************************
*define  data
******************************************************/
u16 adc_temp [4];
u8  adc_times=0;


void  Adc_SetUp_Init(void);
void  adcc(void);

// 
void Set_adc_chan(unsigned char channel )
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;    
  ADC1->CSR = 0x03;                     // ADC_CSR=0x03;//0x03;   //4通道打开，不开中断g
  ADC1->CR1 = 0x20;                     // ADC_CR1=0x20;          // F/8  CONT=1;
  ADC1->CR2 = 0x08;                     // ADC_CR2=0x08;//0x0a;   //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;           // ADC_CR1_ADON = 1;      //启动转换	
}

// 
void  Adc_SetUp_Init(void)
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc============
  ADC1->CSR = 0x24;                     // ADC_CSR=0x24;          //AIN4通道打开；开中断
  ADC1->CR1 = 0x40;                     // ADC_CR1=0x40;          // F/8 连续 CONT=0;
  ADC1->CR2 = 0x0a;                     // ADC_CR2=0x0a;          //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;           // ADC_CR1_ADON = 1;      //启动转换-----------		
}

// 
void  Adc_SetUp_ch(unsigned char ch)
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc============
  ADC1->CSR = ch;       // ADC_CSR=ch;          //AIN4通道打开；开中断
  ADC1->CR1 = 0x00;     // ADC_CR1=0x00;          // F/8 连续 CONT=0;
  ADC1->CR2 = 0x08;     // ADC_CR2=0x08;          //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;   // ADC_CR1_ADON = 1;      //启动转换-----------		
}

//
void  Adc_SetUp_ch1(void)
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc============
  ADC1->CSR = 0x06;             // ADC_CSR=0x06;          //AIN4通道打开；开中断
  ADC1->CR1 = 0x00;             // ADC_CR1=0x00;          // F/8 连续 CONT=0;
  ADC1->CR2 = 0x08;             // ADC_CR2=0x08;          //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;   // ADC_CR1_ADON = 1;      //启动转换-----------		
}

// 
void  Adc_SetUp_ch2(void)//2
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc============
  ADC1->CSR = 0x05;             // ADC_CSR=0x05;          //AIN4通道打开；开中断
  ADC1->CR1 = 0x00;             // ADC_CR1=0x00;          // F/8 连续 CONT=0;
  ADC1->CR2 = 0x08;             // ADC_CR2=0x08;          //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;   // ADC_CR1_ADON = 1;      //启动转换-----------	
}

// 
void  Adc_SetUp_ch3(void)//3
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc============
  ADC1->CSR = 0x04;             // ADC_CSR=0x04;          //AIN4通道打开；开中断
  ADC1->CR1 = 0x00;             // ADC_CR1=0x00;          // F/8 连续 CONT=0;
  ADC1->CR2 = 0x08;             // ADC_CR2=0x08;          //40 开启触发，单
  ADC1->CR1 |= ADC1_CR1_ADON;   // ADC_CR1_ADON = 1;      //启动转换-----------	
}

// 
void Adc_Start(void)
 {
   ADC1->CR1 |= ADC1_CR1_ADON;  // ADC_CR1_ADON = 1; ADC_CR1_ADON = 1;
 }

// 
void adcc(void)
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //打开adc
  ADC1->CSR = 0x24;                     // ADC_CSR=0x24;          //4通道打�       k
  ADC1->CR1 = 0x70;                     // ADC_CR1=0x70;          // F/8  CONT=1;
  ADC1->CR2 = 0x4a;                     // ADC_CR2=0x4a;//0x0a;   //40 开启触发�   扫描模式
  ADC1->CR1 |= ADC1_CR1_ADON;           // ADC_CR1_ADON = 1;      //启动转换
}

// 
void Adc_Scan_timetrig_init()
{
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      //set-off  adc===========  
  ADC1->CSR = 0x24;                     // ADC_CSR=0x24;          //扫描通道！============== 
  //不连续转换CONT=1;=======
  ADC1->CR1 = 0x70;                     // ADC_CR1=0x70;          //时钟分频 F/8 触发模式无效
  //开启转换完成触发中断
  ADC1->CR2 = 0x0a;                     // ADC_CR2=0x0a;//0x0a;   //40 time触发模式-扫描模式
  ADC1->CR1 |= ADC1_CR1_ADON;           // ADC_CR1_ADON = 1;      //启动转换=================    
}

// Adc_mode_trig_init()
void Adc_Scan_pwmtrig_init()
{  
  ADC1->CR1 &= (~ADC1_CR1_ADON);        // ADC_CR1_ADON = 0;      // set-off  adc===========
  ADC1->CSR = 0x25;                     // ADC_CSR=0x25;          //扫描通道！==============  
  ADC1->CR1 = 0x70;                     // ADC_CR1=0x70;          //时钟分频 F/8 触发模式无效
  //不连续转换CONT=1;=======
  ADC1->CR2 = 0x4a;                     // ADC_CR2=0x4a;//0x0a;   //40 PWM触发模式-扫描模式 
  //开启转换完成触发中断
  ADC1->CR1 |= ADC1_CR1_ADON;           // ADC_CR1_ADON = 1;      //启动转换-----------				 
}

//
void  Getval_prc_updata()
{
  static unsigned char TempCnt = 0;
  
  if( (0<=Motordata.prct.clcount) && (Motordata.prct.clcount<5) )	
  {   			
    Motordata.prct.bufovp += (ADC1->DB1RH<<8)+ADC1->DB1RL;      // ADC_DB1R;
    Motordata.prct.bufsep += (ADC1->DB3RH<<8)+ADC1->DB3RL;      // ADC_DB3R;
    Motordata.prct.bufocp += (ADC1->DB2RH<<8)+ADC1->DB2RL;      // ADC_DB2R;
    Motordata.prct.bufoct += (ADC1->DB0RH<<8)+ADC1->DB0RL;      // ADC_DB0R;
    Motordata.prct.clcount = Motordata.prct.clcount+1;
  }
 
// /**************************************************
// /*		  Motordata.hopeduty  = ADC_DB3R;/**  speed**/
// /*	    Motordata.prct.Anp=ADC_DB2R;     /**  ocp**/
// /*		  Motordata.prct.Volt=ADC_DB1R;    /**  ovp**/
// /*		  Motordata.prct.Tempr=ADC_DB0R;   /**  otp**/
// /*                   u16  bufovp;//欠压保护
//  u16  bufsep;//过压保护
//  u16  bufocp;//过流保护
//  u16  bufoct;//过温保护
//  u8   clcount;	//计数
// /*************************************************/
 
  if(Motordata.prct.clcount>=5)
  {
    Motordata.hopeduty = Motordata.prct.bufsep>>2;
    Motordata.prct.Anp = Motordata.prct.bufocp/5;
    Motordata.prct.Volt= Motordata.prct.bufovp/5;
    Motordata.prct.Tempr=Motordata.prct.bufoct/5;
		
///////////////////////modify by goldjun//////////////////////////		
//judge curr which  temp
    TempCnt ++;
    if((TempCnt&0x01)==0x01)
    {
//stroe curr mostemp	
      Motordata.prct.MosTemp = Motordata.prct.Tempr;
//switch next mosaddbattemp
//input
      GPIOD->DDR &= 0xef;       // PD_DDR&=0xef;
      GPIOD->CR1 &= 0xef;       // PD_CR1&=0xef;
      GPIOD->CR2 &= 0xef;       // PD_CR2&=0xef;
    }
    else
    {
//store curr mosaddbattemp	
      Motordata.prct.MosAddBatTemp = Motordata.prct.Tempr;
//switch next mostemp
//output 0
      GPIOD->DDR |= 0x10;       // PD_DDR|=0x10;
      GPIOD->CR1 &= 0xef;       // PD_CR1&=0xef;
      GPIOD->CR2 &= 0xef;       // PD_CR2&=0xef;
      GPIOD->ODR &= 0xef;       // PD4_OUT=0;
    }
///////////////////////modify by goldjun//////////////////////////

    Motordata.prct.clcount=0;
    Motordata.prct.bufovp=0;
    Motordata.prct.bufsep=0;
    Motordata.prct.bufocp=0;
    Motordata.prct.bufoct=0;
  }
	/**********************存储器更新 ****************/	
	/**************************缓存清零*****************/
}






