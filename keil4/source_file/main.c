#include"shumaguan.h"
#include"keyscan.h"

uchar x[]={17,17,17,17};  //�������ʾ���飬17��ʾû����
uchar NPW[]={1,2,3,4};   //��ǰ����
uchar keynum=0,j;         //keynum��ֵ��ʾ��ǰ�Ѿ���ʾ�˶���λ

//�������ܷ���
void fun_Enter();
void fun_Clear();
void fun_Del();
void fun_change_passwd();
void fun_nomal();


//������
void main(void)
{
    while(1)
    {
        keyscan();  //����ɨ��

        if(keyvalue!=17)       //�жϰ����Ƿ���
        {
            switch(keyvalue){
            
                case 15:    fun_Enter();    break;
                case 14:    fun_Clear();    break;
                case 13:    fun_Del();      break;
                case 12:    fun_change_passwd(); break;
                default :   fun_nomal();    break;
            }                              
            keyvalue=17;
        }

        led_display(x);        //��ʾ
    }
}

//'OK' �� ,��֤����
void fun_Enter()
{

    if(x[0]==NPW[0]&&x[1]==NPW[1]&&x[2]==NPW[2]&&x[3]==NPW[3])  //������ȷ
        for(j=0;j<4;j++) x[j]=10;               //��ʾȫa
 
    else                                                        //�������  
        for(j=0;j<4;j++) x[j]=11;               //��ʾȫb
            
    keynum=4;                       //��ʾ��4λ                             
    keyvalue=17;                    //���״̬
}
//'Clear' �� ,�����ʾ
void fun_Clear()
{
    keynum=0;                   //��ʾλ������

    for(j=0;j<4;j++)    x[j]=17;//��ʾ����
    keyvalue=17;
}

//'Del' �� ,���ǰһ������
void fun_Del()
{

    switch(keynum){

        case(0):break;              
        case(1):x[0]=17;keynum--;break;
        case(2):x[1]=17;keynum--;break;
        case(3):x[2]=17;keynum--;break;
        case(4):x[3]=17;keynum--;break;
    }
}

//"nomal���ּ�"   ��������֧��0-9
void fun_nomal()
{
    if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //��ʾ0~9
            x[keynum++]=keyvalue;           //��ʾ��ǰλ
 
}

//'change passwd' �� ,�޸�����
void fun_change_passwd()
{
    keynum=0;                   //��ʾλ������
    for(j=0;j<4;j++)            //��ʾ����
        x[j]=17;
    while(keyvalue!=15)
    {
        keyscan();  //����ɨ��
        if(keyvalue!=17)  //�жϰ����Ƿ���
        {
            if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //��ʾ0~9
            {
                x[keynum++]=keyvalue;                   //��ʾ��ǰλ
                keyvalue=17;
            }
            
            if(keyvalue==15)                        //ȷ����
            {
                if(x[0]==NPW[0]&&x[1]==NPW[1]&&x[2]==NPW[2]&&x[3]==NPW[3]) 
                {   
                    keynum=0;                       //��ʾλ������
                    for(j=0;j<4;j++)                //��ʾ����
                        x[j]=17;
                    while(keyvalue!=15||keynum!=4)
                    {
                        keyscan();                  //����ɨ��
                        if(keyvalue!=17)            //�жϰ����Ƿ���
                        {
                            if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //��ʾ0~9
                            {
                                x[keynum++]=keyvalue;               //��ʾ��ǰλ
                                NPW[keynum-1]=keyvalue;
                                keyvalue=17;
                            }

                        }
                        led_display(x);         //��ʾ
                    }

                    keynum=0;                   //��ʾλ������
                    for(j=0;j<4;j++)            //��ʾ����
                        x[j]=17;

                }
                else                            //���������ʾȫB
                {
                    for(j=0;j<4;j++)               
                        x[j]=11;
                    keynum=4;
                }
            }
        }
        led_display(x);        //��ʾ
    }
}