#ifndef  __SHUMAGUAN_H_
#define	 __SHUMAGUAN_H_

/*包含头文件*/
#include<reg52.h>
#include<intrins.h>

/*重定义关键词*/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

// #if 0 表示使用 共阳段码表 
// #if 1 表示使用 共阴段码表
#if 0
    
    #define table table_K       //使用共阴段码表

    #define on      1
    #define off     0 

#else

    #define   table table_A     //使用共阳段码表

    #define on      0 
    #define off     1 
#endif


/*定义声明变量*/
#define GPIO_data P1
sbit wei1=P2^3;
sbit wei2=P2^4;
sbit wei3=P2^5;
sbit wei4=P2^6;//位选

/*函数的声明*/
void Delay1ms(uint c);
void HC595SendData(uchar duan);
void led_display(uchar []); 

#endif