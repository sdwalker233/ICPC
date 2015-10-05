#include<stdio.h>
#include<math.h>

int main()
{
	double x,y;
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		x=(double)b*log10((double)a);
		y=(double)d*log10((double)c);
		if(fabs(x-y)<=1e-8) printf("=\n");
		else if(x>y) printf(">\n");
			 else printf("<\n");
	}
 return 0;
}

