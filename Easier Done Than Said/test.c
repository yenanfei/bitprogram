#include<stdio.h>
int main()
{
    int i;
    char str[25]={0};
    while(~scanf("%s",&str))
    {
		int y=0,f=0,vowel=0,flag=1;
		if(str[0]=='h'&&str[1]=='o'&&str[2]=='u')
			goto Y;
        for(i=0;str[i]!=0;i++) 
        {
        	if((str[i]==str[i-1])&&(str[i]!='e'&&str[i]!='o'))
            	{
             		goto N;
           		}
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') 
                vowel++;
            if(vowel==0)
            	goto N;
			if(97==str[i]||101==str[i]||105==str[i]||111==str[i]||117==str[i])
				{
					y++;
					f=0;
					if(3==y)
					{
						goto N;
					}
				}
				else
				{
					f++;
					y=0;
					if(3==f)
					{
						goto N;
					}
				}
		}
        Y:   printf("<%s> is acceptable.\n",str);
        while(0)
       	N:  printf("<%s> is not acceptable.\n",str);
    }
    return 0;
}
