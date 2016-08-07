#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[5][20];
void sort(int n)
{
    int i,j;
	char temp[20];  
	for(j=0;j<n;j++)  
	  for(i=0;i<n-j-1;i++)  
	    {
	       if(strcmp(a[i],a[i+1])<0)
		      {
			      strcpy(temp,a[i]);
				  strcpy(a[i],a[i+1]);    
				  strcpy(a[i+1],temp);   
			  }  
	    }
}
main()
{
     int i;
	 char c;
	 for (i=0;i<5;i++)
	   {
	        gets(a[i]);     			
	   }
    sort(5);
	for(i=0;i<5;i++)
	puts(a[i]);
}
