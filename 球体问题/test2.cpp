#include<stdio.h>
#include<math.h> 
#define Pi 2*acos(0.0)
void calculate();
int main(int argc, const char * argv[])
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        calculate();
return 0;

}
void calculate()
{
	double R1,R2,D,W,V,S,x;
	long double s,Density;
	scanf("%lf%lf%lf%lf%Lf",&R1,&R2,&D,&W,&s);
	x=(R1*R1-R2*R2)/(0.2*D);
	double tmp1=Pi/3*(R1-(R1*R1-R2*R2+D*D)/(2*D))*(R1-(R1*R1-R2*R2+D*D)/(2*D))*(3*R1-(R1-(R1*R1-R2*R2+D*D)/(2*D)));
	double tmp2=Pi/3*(R2-(R2*R2-R1*R1+D*D)/(2*D))*(R2-(R2*R2-R1*R1+D*D)/(2*D))*(3*R2-(R2-(R2*R2-R1*R1+D*D)/(2*D)));
	V=4.0/3*Pi*(R1*R1*R1+R2*R2*R2)-(tmp1+tmp2);
	S=2*Pi*R1*(x+R1)+2*Pi*R2*(R2+D-x);
	printf("%.4lf%.4lf\n",V,S);
	Density=W/V;
	if(Density>s)
		printf("The Paired-Sphere Sinks.\n");
	else
		printf("The Paired-Sphere Floats.\n");
}
