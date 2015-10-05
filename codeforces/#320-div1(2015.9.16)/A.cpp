#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==0){
		printf("%lf\n",(double)a/2);
		return 0;
	}
	if(a==b){
		printf("%d\n",a);
		return 0;
	}
	if(a<b){
		printf("-1\n");
		return 0;
	}
	double ans1=(double)(a-b)/((a-b)/(2*b))/2;
	double ans2=(double)(a+b)/((a+b)/(2*b))/2;
	printf("%.10lf\n",min(ans1,ans2));
 return 0;
}


