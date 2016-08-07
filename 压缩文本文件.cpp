#include"string.h"
#include"stdio.h"
#define N 20000
main()
{
	int i,j,k,num=0,p=0,q=0,m,n=0,flag=0;
	char data[N][100],code[N][100],stor[N][100],t;
	while(gets(code[num])!=NULL)
   		{
			j=0;i=0;
			for(;;i++)
      			{
					 flag=1;
					 if((code[num][i]>=65&&code[num][i]<=90)||(code[num][i]>=97&&code[num][i]<=122))
  					 {
					 	stor[p][q]=code[num][i];
						q++;
					 }
   					 else
    				{
						if(q!=0)stor[p][q]='\0';
      						if(i==0)goto x;
     					else  if(!((code[num][i-1]>=65&&code[num][i-1]<=90)||(code[num][i-1]>=97&&code[num][i-1]<=122)))
      					goto x;
      					else
						{
						  	for(m=0;m<n;m++)
      						if(data[m][0]==stor[p][0])
       						{
						   		if(strcmp(data[m],stor[p])==0)
       							{
							   		printf("%d",m+1);
									flag=0;
        							goto x;
								} 
							}    
        					if(flag)
         					{
								 strcpy(data[n],stor[p]);
            			     	n++;
						     	printf("%s",data[n-1]);
							} 
						}
    					x: if(code[num][i]!='\0') printf("%c",code[num][i]);
    					j=i+1;
    					p++;
    					q=0;
    					if(code[num][i]=='\0') break; 
					}  
				}
			num++;
    		printf("\n");
   		}
 }
