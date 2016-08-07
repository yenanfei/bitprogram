#include<stdio.h>
#include<windows.h>//基本型态定义。支援型态定义函数。使用者界面函数 图形装置界面函数。
#include<conio.h>	 //用户通过按键盘产生的对应操作 (控制台） 
#include<stdlib.h> 
#include<time.h> //日期和时间头文件 
#define LEN 30
#define WID 25
int Snake[LEN][WID] = {0};	 //数组的元素代表蛇的各个部位 
char Sna_Hea_Dir = 'a';//记录蛇头的移动方向
int Sna_Hea_X, Sna_Hea_Y;//记录蛇头的位置
int Snake_Len = 3;//记录蛇的长度
clock_t Now_Time;//记录当前时间，以便自动移动
int Wait_Time ;//记录自动移动的时间间隔
int Eat_Apple = 1;//吃到苹果表示为1
int Level ;
int All_Score = -1;
int Apple_Num = -1;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出的句柄 <windows.h>
//句柄 ：标志应用程序中的不同对象和同类对象中的不同的实例 方便操控，
void gotoxy(int x, int y)//设置光标位置
 {
     COORD pos = {x,y};	 //定义一个字符在控制台屏幕上的坐标POS
     
    SetConsoleCursorPosition(hConsole, pos);	//定位光标位置的函数<windows.h>
 
}
 
void Hide_Cursor()//隐藏光标 固定函数 
 {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
    SetConsoleCursorInfo(hConsole, &cursor_info);	 
 }
 
void SetColor(int color)//设置颜色
 {
     SetConsoleTextAttribute(hConsole, color);
//是API设置字体颜色和背景色的函数 格式：SetConsoleTextAttribute(句柄,颜色);
 }

void Print_Snake()//打印蛇头和蛇的脖子和蛇尾
 {
     int iy, ix, color;
     for(iy = 0; iy < WID; ++iy)
         for(ix = 0; ix < LEN; ++ix)
         {
 
            if(Snake[ix][iy] == 1)//蛇头
             {
                 SetColor(0xf);            //oxf代表分配的内存地址  setcolor:34行自定义设置颜色的函数 
                 gotoxy(ix*2, iy);
                 printf("※");
             }
             if(Snake[ix][iy] == 2)//蛇的脖子
             {
                 color = rand()%15 + 1;	 //rand()函数是产生随机数的一个随机函数。C语言里还有 srand()函数等。
//头文件:stdlib.h 
                 if(color == 14)
                     color -= rand() % 13 + 1;	//变色 
                 SetColor(color);
                 gotoxy(ix*2, iy);
                 printf("■");
             }
             if(Snake[ix][iy] == Snake_Len)
             {
                 gotoxy(ix*2, iy);
                 SetColor(0xe);
                 printf("≈");
             }
         }
 }
 
void Clear_Snake()//擦除贪吃蛇
 {
     int iy, ix;
     for(iy = 0; iy < WID; ++iy)
         for(ix = 0; ix < LEN; ++ix)
         {
             gotoxy(ix*2, iy);
             if(Snake[ix][iy] == Snake_Len)
                 printf("  ");
         }
 }
 
void Rand_Apple()//随机产生苹果
 {
     int ix, iy;
 
    do
     {
         ix = rand() % LEN;
         iy = rand() % WID;
     }while(Snake[ix][iy]);
 
    Snake[ix][iy] = -1;
     gotoxy(ix*2, iy);
     printf("⊙");
     Eat_Apple = 0;
 }
 
void Game_Over()//蛇死掉了
 {
     gotoxy(30, 10);
     printf("Game Over");
     Sleep(3000);
     system("pause > nul");
     exit(0);
 }
 
void Move_Snake()//让蛇动起来
 {
     int ix, iy;
     
    for(ix = 0; ix < LEN; ++ix)//先标记蛇头
         for(iy = 0; iy < WID; ++iy)
             if(Snake[ix][iy] == 1)
             {
                switch(Sna_Hea_Dir)//根据新的蛇头方向标志蛇头
                 {
                     case 'w':
                         if(iy == 0)
                             Game_Over();
                         else
                             Sna_Hea_Y = iy - 1;
                         Sna_Hea_X = ix;
                       
                        break;
                     case 's':
                         if(iy == (WID -1))
                                 Game_Over();
                         else
                             Sna_Hea_Y = iy + 1;
                         Sna_Hea_X = ix;
                     
                         break;
                     case 'a':
                         if(ix == 0)
                                 Game_Over();
                         else
                             Sna_Hea_X = ix - 1;
                         Sna_Hea_Y = iy;
                     
                         break;
                     case 'd':
                         if(ix == (LEN - 1))
                                 Game_Over();
                         else
                             Sna_Hea_X = ix + 1;
                         Sna_Hea_Y = iy;
                 
                        break;
                     default:
                         break;
                 }
             }
      
     if(Snake[Sna_Hea_X][Sna_Hea_Y]!=1&&Snake[Sna_Hea_X][Sna_Hea_Y]!=0&&Snake[Sna_Hea_X][Sna_Hea_Y]!=-1)
         Game_Over();
 
    if(Snake[Sna_Hea_X][Sna_Hea_Y] < 0)//吃到苹果
     {
         ++Snake_Len;
         Eat_Apple = 1;
     }
     for(ix = 0; ix < LEN; ++ix)//处理蛇尾
         for(iy = 0; iy < WID; ++iy)
         {
             if(Snake[ix][iy] > 0)
             {
                 if(Snake[ix][iy] != Snake_Len)
                     Snake[ix][iy] += 1;
                 else
                     Snake[ix][iy] = 0;
             }
         }

Snake[Sna_Hea_X][Sna_Hea_Y] = 1;//处理蛇头    
}
 
void Get_Input()//控制蛇的移动方向
 {
     if(kbhit())
     {
         switch(getch())
         {
         case 87:
             
                 Sna_Hea_Dir = 'w';
             break;
         case 83:
             
             Sna_Hea_Dir = 's';
             break;
         case 65:
             
             Sna_Hea_Dir = 'a';
             break;
         case 68:
             
             Sna_Hea_Dir = 'd';
             break;
         default:
             break;
         }
     }
     
    if(clock() - Now_Time >= Wait_Time)//蛇到时间自动行走
     {
         Clear_Snake();
         Move_Snake();
         Print_Snake();
         Now_Time = clock();
     }
 }
 
void Init()//初始化
 {
     system("title 贪吃蛇");
     system("mode con: cols=80 lines=25");
     Hide_Cursor();
 
    gotoxy(61, 4);
     printf("You Score:");
     gotoxy(61, 6);
     printf("You Level:");
     gotoxy(61, 8);
     printf("The Lenght:");
     gotoxy(61, 10);
     printf("The Speed:");
     gotoxy(61, 12);
     printf("Apple Num:");
 
    int i;
     for(i = 0; i < Snake_Len; ++i)//生成蛇
         Snake[10+i][15] = i+1;
 
    int iy, ix;//打印蛇
     for(iy = 0; iy < WID; ++iy)
         for(ix = 0; ix < LEN; ++ix)
         {
             if(Snake[ix][iy])
             {
                 SetColor(Snake[ix][iy]);            
                 gotoxy(ix*2, iy);
                 printf("■");
             }
         }
 }
 
void Pri_News()//打印信息
 {
     SetColor(0xe);
     gotoxy(73,4);
     All_Score += Level;
     printf("%3d", All_Score);
     gotoxy(73, 6);
     printf("%3d", Level);
     gotoxy(73, 8);
     printf("%3d",Snake_Len);
     gotoxy(73, 10);
     printf("0.%3ds", Wait_Time/10);
     gotoxy(73, 12);
     printf("%d", Apple_Num);
 }
 
void Lev_Sys()//等级系统
 {
     if(((Apple_Num-1) / 10) == Level)
     {
         ++Level;
         if(Wait_Time > 50)
             Wait_Time -= 50;
         else
             if(Wait_Time > 10)
                 Wait_Time -= 10;
             else
                 Wait_Time -= 1;
     }    
}
 
int main(void)
 {
     Init();
     srand((unsigned)time(NULL));//设置随机数的种子
     Now_Time = clock();
     int speed1=1000,speed2,a;
     printf("\n");
     printf("请输入你想要的速度\n");
     scanf("%d",&speed2);
     Level=1;
     Wait_Time=speed1-speed2;
     printf("请输入你想要的苹果数\n");
     scanf("%d",&a);
     
     while(a--)
     Rand_Apple();
    while(1)
     {
         if(Eat_Apple)
         {
             ++Apple_Num;
             Rand_Apple();
             Lev_Sys();
             Pri_News();
         }
         Get_Input();
         Sleep(10);
     }
     return 0;
 }
