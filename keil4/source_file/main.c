#include"shumaguan.h"
#include"keyscan.h"

uchar x[]={17,17,17,17};  //数码管显示数组，17表示没按下
uchar NPW[]={1,2,3,4};   //当前密码
uchar keynum=0,j;         //keynum数值表示当前已经显示了多少位

//按键功能分配
void fun_Enter();
void fun_Clear();
void fun_Del();
void fun_change_passwd();
void fun_nomal();


//主函数
void main(void)
{
    while(1)
    {
        keyscan();  //按键扫描

        if(keyvalue!=17)       //判断按键是否按下
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

        led_display(x);        //显示
    }
}

//'OK' 键 ,验证密码
void fun_Enter()
{

    if(x[0]==NPW[0]&&x[1]==NPW[1]&&x[2]==NPW[2]&&x[3]==NPW[3])  //密码正确
        for(j=0;j<4;j++) x[j]=10;               //显示全a
 
    else                                                        //密码错误  
        for(j=0;j<4;j++) x[j]=11;               //显示全b
            
    keynum=4;                       //显示了4位                             
    keyvalue=17;                    //清除状态
}
//'Clear' 键 ,清除显示
void fun_Clear()
{
    keynum=0;                   //显示位数清零

    for(j=0;j<4;j++)    x[j]=17;//显示清零
    keyvalue=17;
}

//'Del' 键 ,清除前一个输入
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

//"nomal数字键"   输入数据支持0-9
void fun_nomal()
{
    if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //显示0~9
            x[keynum++]=keyvalue;           //显示当前位
 
}

//'change passwd' 键 ,修改密码
void fun_change_passwd()
{
    keynum=0;                   //显示位数清零
    for(j=0;j<4;j++)            //显示清零
        x[j]=17;
    while(keyvalue!=15)
    {
        keyscan();  //按键扫描
        if(keyvalue!=17)  //判断按键是否按下
        {
            if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //显示0~9
            {
                x[keynum++]=keyvalue;                   //显示当前位
                keyvalue=17;
            }
            
            if(keyvalue==15)                        //确定键
            {
                if(x[0]==NPW[0]&&x[1]==NPW[1]&&x[2]==NPW[2]&&x[3]==NPW[3]) 
                {   
                    keynum=0;                       //显示位数清零
                    for(j=0;j<4;j++)                //显示清零
                        x[j]=17;
                    while(keyvalue!=15||keynum!=4)
                    {
                        keyscan();                  //按键扫描
                        if(keyvalue!=17)            //判断按键是否按下
                        {
                            if(keyvalue>=0&&keyvalue<=9&&keynum<4)  //显示0~9
                            {
                                x[keynum++]=keyvalue;               //显示当前位
                                NPW[keynum-1]=keyvalue;
                                keyvalue=17;
                            }

                        }
                        led_display(x);         //显示
                    }

                    keynum=0;                   //显示位数清零
                    for(j=0;j<4;j++)            //显示清零
                        x[j]=17;

                }
                else                            //密码错误，显示全B
                {
                    for(j=0;j<4;j++)               
                        x[j]=11;
                    keynum=4;
                }
            }
        }
        led_display(x);        //显示
    }
}