#ifndef  __KEYSCAN_H_
#define	 __KEYSCAN_H_

/*����ͷ�ļ�*/
#include<reg52.h>
#include<intrins.h>

/*�ض���ؼ���*/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/*�����������*/
#define GPIO_KEY P0

//--��������--//
void keyscan(void);
void Delay10ms(uint c);   //��� 0us 

/*�����ⲿ����*/
extern uint keyvalue;

#endif

