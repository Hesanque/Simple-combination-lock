#include"shumaguan.h"

//共阴数码管 段码表
uchar table_K[18]={0x3f,0x06,0x5b,0x4f,
                0x66,0x6d,0x7d,0x07,
                0x7f,0x6f,0x77,0x7c,
                0x39,0x5e,0x79,0x71,0x80,0x00};//0~f，以及小数点，还有不显示。
//共阳数码管 段码表
uchar table_A[18]={0xC0,0xF9,0xA4,0xB0,
                0x99,0x92,0x82,0xF8,
                0x80,0x90,0x88,0x83,
                0xC6,0xA1,0x86,0x8E,0x7f,0xff};//0~f，以及小数点，还有不显示。

/*延时函数*/
void Delay1ms(uint c)   //误差 0us
{
    uchar a,b;
    //--c已经在传递过来的时候已经赋值了，所以在for语句第一句就不用赋值了--//
    for (;c>0;c--)
    {
        for (b=38;b>0;b--)
        {
            for (a=13;a>0;a--);
        }          
    }       
}




/*显示*/
void led_display(uchar x[])
{
    uchar duan;
    duan=table[x[0]];
    GPIO_data=duan;
    wei1=on;
    Delay1ms(1);
    wei1=off;
    Delay1ms(1);

	GPIO_data=0xff;
	
    duan=table[x[1]];
    GPIO_data=duan;
    wei2=on;
    Delay1ms(1);
    wei2=off;
    Delay1ms(1);
	GPIO_data=0xff;

    duan=table[x[2]];
    GPIO_data=duan;
    wei3=on;
    Delay1ms(1);
    wei3=off;
    Delay1ms(1);
	GPIO_data=0xff;

	
    duan=table[x[3]];
    GPIO_data=duan;
    wei4=on;
    Delay1ms(1);
    wei4=off;
    Delay1ms(1);
	GPIO_data=0xff;

}
