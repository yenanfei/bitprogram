#include<stdio.h>  
#include<math.h>
int main()  
{  
 int n,i=1,k=0; double x=0;
 	scanf("%d\n",&n);   
	 for(i=1;i<n/2;i++)
 		{    
			x=((-1+sqrt(1-4*(-i*i+i-2*n)))/2);
 				 if(x!=floor(x))
				  continue;
				 else
				 {
				 	printf("%d~%.0lf\n",i,x);k=1;
				 }  
 		}  
 if(k==0)printf("None\n");  
}  
