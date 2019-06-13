#include"shumaguan.h"


//��������� �����
uchar table_K[18]={0x3f,0x06,0x5b,0x4f,
                0x66,0x6d,0x7d,0x07,
                0x7f,0x6f,0x77,0x7c,
                0x39,0x5e,0x79,0x71,0x80,0x00};//0~f���Լ�С���㣬���в���ʾ��
//��������� �����
uchar table_A[18]={0xC0,0xF9,0xA4,0xB0,
                0x99,0x92,0x82,0xF8,
                0x80,0x90,0x88,0x83,
                0xC6,0xA1,0x86,0x8E,0x7f,0xff};//0~f���Լ�С���㣬���в���ʾ��                                                               

/*��ʱ����*/
void Delay1ms(uint c)   //��� 0us
{
    uchar a,b;
    //--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
    for (;c>0;c--)
    {
        for (b=38;b>0;b--)
        {
            for (a=13;a>0;a--);
        }          
    }       
}


/*����һ���ֽ�*/
void HC595SendData(uchar duan)
{  
    uchar i;

    //--���͵�һ���ֽ�--//
    for(i=0;i<8;i++)
    {
        DS = duan>>7;   //�Ӹ�λ����λ
        duan<<= 1;

        SH_CP = 0;
        SH_CP = 1;      
    }

    //--���--//
    ST_CP = 0; //set dataline low
    ST_CP = 1; //Ƭѡ
    ST_CP = 0; //set dataline low
}

/*��ʾ*/
void led_display(uchar x[])
{
    uchar duan;

    //��ʾ��һλ
    duan=table[x[0]];
    HC595SendData(duan);
    wei1=on;
    Delay1ms(1);
    wei1=off;
    Delay1ms(1);
    
    //��ʾ�ڶ�λ
    duan=table[x[1]];
    HC595SendData(duan);
    wei2=on;
    Delay1ms(1);
    wei2=off;
    Delay1ms(1);

    //��ʾ����λ
    duan=table[x[2]];
    HC595SendData(duan);
    wei3=on;
    Delay1ms(1);
    wei3=off;
    Delay1ms(1);

    //��ʾ����λ
    duan=table[x[3]];
    HC595SendData(duan);
    wei4=on;
    Delay1ms(1);
    wei4=off;
    Delay1ms(1);
}
