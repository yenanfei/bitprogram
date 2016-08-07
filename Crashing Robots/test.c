#include<stdio.h>
struct map
{
    int x, y, dir;
}robot[102];

int main()
{
    int T, i, j,k,num, count,flag,A, B, n, m;
    char letter;
    scanf("%d",&T);
    while(T--)
	    {
	    	flag=0;
	        scanf("%d%d%d%d",&A, &B, &n, &m);
	        for(i = 1; i <= n; i++)
		        {
		            scanf("%d %d %c",&robot[i].x, &robot[i].y, &letter);
		            if(letter == 'E')
		                robot[i].dir = 0;
		            if(letter == 'S')
		                robot[i].dir = 1;
		            if(letter == 'W')
		                robot[i].dir = 2;
		            if(letter == 'N')
		                robot[i].dir = 3;
		        }
	        for(i = 0; i < m; i++)
		        {
		            scanf("%d %c %d",&num, &letter, &count);
		            if(letter == 'F'&&!flag)
			            {
				            for(j = 0; j < count; j++)
					            {
					                if(robot[num].dir == 0)
					                      robot[num].x++;
					                if(robot[num].dir == 1)
					                    robot[num].y--;
					                if(robot[num].dir == 2)
					                    robot[num].x--;
					                if(robot[num].dir == 3)
					                    robot[num].y++;
					                if(robot[num].x <= 0 || robot[num].x > A || robot[num].y <= 0 || robot[num].y > B)
					  					{
					    					printf("Robot %d crashes into the wall\n",num);
					    					flag=1;
					    					break;
					   					}
									for(k = 1; k <= n; k++)
										if(robot[num].x == robot[k].x && robot[num].y == robot[k].y&&k!=num)
											{
											    printf("Robot %d crashes into robot %d\n",num,k);
											    flag=1;
											    break;
											}
									if(flag==1)
										break;
					   						flag=0;
					            }
			            }
		            if(letter == 'L')
		                robot[num].dir = (robot[num].dir - count % 4+4) % 4;
		            if(letter == 'R')
		                robot[num].dir = (robot[num].dir + count % 4) % 4;
		        }
	        if(!flag)
	            printf("OK\n");
	    }
}
