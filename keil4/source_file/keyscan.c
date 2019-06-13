#include"keyscan.h"

uint keyvalue=17;  //检测是否按下按键

/*延时函数*/
void Delay10ms(uint c)   //误差 0us
{
    uchar a, b;
    //--c已经在传递过来的时候已经赋值了，所以在for语句第一句就不用赋值了--//
    for (;c>0;c--)
    {
        for (b=38;b>0;b--)
        {
            for (a=130;a>0;a--);
        }          
    }       
}

void keyscan(void)
{
    //char a = 0;
    GPIO_KEY=0x0f;
    if(GPIO_KEY!=0x0f)//读取按键是否按下
    {
        Delay10ms(1);//延时10ms进行消抖
        if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
        {
            
            //测试列
            GPIO_KEY=0X0F;
            switch(GPIO_KEY)
            {
                case(0X07): keyvalue=12;break;
                case(0X0b): keyvalue=8;break;
                case(0X0d): keyvalue=4;break;
                case(0X0e): keyvalue=0;break;
            }
            //测试行
            GPIO_KEY=0XF0;
            switch(GPIO_KEY)
            {
                case(0X70): keyvalue=keyvalue+3;break;
                case(0Xb0): keyvalue=keyvalue+2;break;
                case(0Xd0): keyvalue=keyvalue+1;break;
                case(0Xe0): keyvalue=keyvalue;break;
            }

            /*while((a<50) && (GPIO_KEY!=0xf0))    //检测按键松手检测
            {
                Delay10ms(1);
                a++;
            }*/

			while(GPIO_KEY!=0xf0);
        }
    }
}
