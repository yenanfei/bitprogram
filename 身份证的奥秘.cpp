#include<stdio.h>
#include<string.h>
void shengji(char str[])
{
	int n=strlen(str);char newstr[19];int i;char temp[4];
	for(i=0;i<6;i++)
		newstr[i]=str[i];//前六位地址码（省地县三级）
	for(i=8;i<17;i++)//newstr中的到第位
		newstr[i]=str[i-2];
	newstr[6]='1';
	temp[0]=str[12];
	temp[1]=str[13];
	temp[2]=str[14];
	temp[3]='\0';
	if(strcmp(temp,"996")==0||strcmp(temp,"997")==0||strcmp(temp,"998")==0||strcmp(temp,"999")==0)
		newstr[7]='8';
	else newstr[7]='9';
//下面是校检码,0的ascii码值是
	int Wi[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};int S=0;int y;
	for(i=0;i<17;i++)
		S+=Wi[i]*((int)(newstr[i])-48);
	y=S%11;
	switch(y)
	{ 
		case 0:newstr[17]='1';break;
		case 1:newstr[17]='0';break;
		case 2:newstr[17]='X';break;
		case 3:newstr[17]='9';break;
		case 10:newstr[17]='2';break;
		default:newstr[17]=(char)(12-y+48);break;
	}
		newstr[18]='\0';
		strcpy(str,newstr);
}

int IscheckedValid(char str[])
{int n=strlen(str);//n=18
int num[17];//保存前位
int i;
for(i=0;i<17;i++)//保存前位
num[i]=(int)str[i]-48;
//下面是校检码,0的ascii码值是
int Wi[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//权重
int S=0;
for(i=0;i<17;i++)
S=S+Wi[i]*num[i];
int y;
y=S%11;
char lastnum;
switch(y)
{case 0:lastnum='1';break;
case 1:lastnum='0';break;case 2:lastnum='X';break;
case 3:lastnum='9';break;
case 10:lastnum='2';break;
default:
lastnum=(char)(12-y+48);break;}
if(lastnum==str[17])
return 1;
else
return 0;//0表示不合法
}

void run(char str[])
{int n=strlen(str);
if(n==15)
{shengji(str);
printf("%s\n",str);}
else if(n==18)
{if(!IscheckedValid(str))
printf("Invalid\n");
else printf("Valid\n");}
else printf("Invalid\n");}

int main()
{int n;
scanf("%d\n",&n);
char str[25];
for(int i=0;i<n;i++)
{gets(str);
run(str);}}
