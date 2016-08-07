#include<stdio.h>
main()
{
	int line1,line2=1, list1,list2=0,n=1;
	scanf("%d",&line1);
	list1=line1;
	for(;line2<=line1;line2++)
		{
			for(;list2<list1;list2++)
				{
					printf("%3d",n);
					n+=1;	
				}
			printf("\n");
			list2=0;
		}
}
