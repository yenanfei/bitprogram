#include<stdio.h>
#include<math.h>
int main()
{
        int n,i,ans=0;
        double t1,t2,s,H,S1,V,L,K,Vmin,Vmax;
        scanf("%lf%lf%lf%lf%lf%d",&H,&S1,&V,&L,&K,&n);
	    for(i=0;i<n;i++)
		    if(i<=(S1-V*sqrt(2*(H-K)/10)+L+0.00001)&&i>=(S1-V*sqrt(2*H/10)-0.00001))
	            ans++;
	    printf("%d\n",ans);
}
