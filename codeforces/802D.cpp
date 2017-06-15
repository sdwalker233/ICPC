#include <bits/stdc++.h>
using namespace std;
double a[5010];
int b[5010];

double check(double l,double r)
{
	int i;
	double cnt=0;
	for(i=l;i<=r;i++) cnt+=a[i];
	return cnt;
}

bool fuck()
{
	int i,x;
	double aver,sum=0;
	memset(b,0,sizeof(b));
	for(i=1;i<=250;i++){
		scanf("%d",&x);
		b[x]++;
	}
	memcpy(b,a,sieof(a));
	for(i=1;i<=250;i++){
		scanf("%d",&x);
		b[x]++;
	}
	for(i=1;i<=5000;i++){
		a[i]=(b[i-1]+b[i]+b[i+1])/3.0;
		sum+=a[i]*i;
	}
	aver=sum/250.0;
	double L=0,R=10000.0,mid;
	for(int t=1;t<=50;t++){
		mid=(L+R)/2;
		if(check(aver-mid,aver+mid)<250*0.9) L=mid;
		else R=mid;
	}
	double cnt=check(aver-mid/2,aver+mid/2);
	if(cnt>=250*0.6) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) if(fuck()) printf("poisson\n");
	else printf("uniform\n");
 return 0;
}

