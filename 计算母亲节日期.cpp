#include <stdio.h>
#include <time.h>
main()
{
 struct tm *tm1;
 struct tm tm;
 time_t t;
 int n;
 printf("请输入要计算的年份：");
 scanf("%d", &n);
 tm.tm_year = n - 1900;
 tm.tm_mon = 4;
 tm.tm_mday = 1;
 tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
 t = mktime(&tm);
 tm1 = localtime(&t);
 n = 15 - tm1->tm_wday;
 if (n == 15)
  n = n - 7;
 printf("这一年的母亲节日期是是：5月%d日\n", n);
}
