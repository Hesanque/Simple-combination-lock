#ifndef  __KEYSCAN_H_
#define	 __KEYSCAN_H_

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

/*声明定义变量*/
#define GPIO_KEY P0

//--声明函数--//
void keyscan(void);
void Delay10ms(uint c);   //误差 0us 

/*声明外部变量*/
extern uint keyvalue;

#endif

