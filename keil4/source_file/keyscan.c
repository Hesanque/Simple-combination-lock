#include"keyscan.h"

uint keyvalue=17;  //����Ƿ��°���

/*��ʱ����*/
void Delay10ms(uint c)   //��� 0us
{
    uchar a, b;
    //--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
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
    if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
    {
        Delay10ms(1);//��ʱ10ms��������
        if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
        {
            
            //������
            GPIO_KEY=0X0F;
            switch(GPIO_KEY)
            {
                case(0X07): keyvalue=12;break;
                case(0X0b): keyvalue=8;break;
                case(0X0d): keyvalue=4;break;
                case(0X0e): keyvalue=0;break;
            }
            //������
            GPIO_KEY=0XF0;
            switch(GPIO_KEY)
            {
                case(0X70): keyvalue=keyvalue+3;break;
                case(0Xb0): keyvalue=keyvalue+2;break;
                case(0Xd0): keyvalue=keyvalue+1;break;
                case(0Xe0): keyvalue=keyvalue;break;
            }

            /*while((a<50) && (GPIO_KEY!=0xf0))    //��ⰴ�����ּ��
            {
                Delay10ms(1);
                a++;
            }*/

			while(GPIO_KEY!=0xf0);
        }
    }
}
