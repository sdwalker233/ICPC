#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1000000000000
using namespace std;
int n;
double x[1000010],y[1000010];

 void fuck()
 {
 	int i;
 	for(i=1;i<=n;i++)
 		scanf("%lf%lf",&x[i],&y[i]);
 	sort(x+1,x+n+1);
 	sort(y+1,y+n+1);
 	if(n%2==0)	printf("%.2lf %.2lf\n",(x[n/2]+x[n/2+1])/2,(y[n/2]+y[n/2+1])/2);
 	else printf("%.2lf %.2lf\n",x[n/2+1],y[n/2+1]);
 }

int main()
{
	while(~scanf("%d",&n)&&n)
		fuck();
 return 0;
}

