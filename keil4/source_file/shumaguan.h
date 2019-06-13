#ifndef  __SHUMAGUAN_H_
#define	 __SHUMAGUAN_H_

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

// #if 0 ��ʾʹ�� ��������� 
// #if 1 ��ʾʹ�� ���������
#if 0
    
    #define table table_K     //ʹ�ù��������

    #define on      0
    #define off     1 

#else

    #define   table table_A     //ʹ�ù��������

    #define on      1 
    #define off     0 
#endif

/*����GPIO����*/
sbit SH_CP=P2^0;    //��������ʱ����
sbit DS   =P2^1;     
sbit ST_CP=P2^2;    //74hc595��spi�ӿڵ�λ����

sbit wei1=P2^3;
sbit wei2=P2^4;
sbit wei3=P2^5;
sbit wei4=P2^6;     //λѡ

/*����������*/
void Delay1ms(uint c);
void HC595SendData(uchar duan);
void led_display(uchar []); 

#endif