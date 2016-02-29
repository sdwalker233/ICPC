#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n;
long long d[10]={0};
long long t[MAXN];
long long a,b,c;

void de(long long &x,long long &y)
{
	if(x>y) {x-=y;y=0;}
	else {x=0;y-=x;}
}
int f1()
{
	int i,j;
	long long m[10]={0,a,b,c,a+b,a+c,b+c,a+b+c};
	int cnt=0;
	for(i=1;i<=n;i++)
		for(j=7;j>=0;j--)
			if(t[i]>m[j]){
				d[j]++;
				break;
			}
	long long ra=d[5],rb=d[4],rc=d[3];
	if(d[7]) return -1;
	cnt+=d[6]+d[5]+d[4]+d[3];
	de(d[2],rc);
	de(d[1],rc);
	de(d[1],rb);
	de(d[0],rc);
	de(d[0],rb);
	de(d[0],ra);
	if(d[0]+d[1]+d[2]==0) return cnt;
	if(d[2]>=d[1]&&d[2]>=d[0]){
		cnt+=max(d[0],d[1])+(d[2]-max(d[0],d[1])-1)/2+1;
	}
	else if(d[1]>=d[0]&&d[1]>=d[2]) cnt+=max(d[0],(d[1]+d[2]-1)/2+1);
	else cnt+=(d[0]+d[1]+d[2]-1)/3+1;
	return cnt;
}

int f2()
{
	int i,j;
	long long m[10]={0,a,b,c,a+b,a+c,b+c,a+b+c};
	int cnt=0;
	for(i=1;i<=n;i++)
		for(j=7;j>=0;j--)
			if(t[i]>m[j]){
				d[j]++;
				break;
			}
	long long ra=d[5],rb=d[4],rc=0,rab=d[3];
	if(d[7]) return -1;
	cnt+=d[6]+d[5]+d[4]+d[3];
	de(d[2],rab);
	de(d[1],rb);
	de(d[0],rb);
	de(d[0],ra);
	if(d[0]+d[1]+d[2]==0) return cnt;
	if(d[2]>=d[1]&&d[2]>=d[0]){
		cnt+=max(d[0],d[1])+(d[2]-max(d[0],d[1])-1)/2+1;
	}
	else if(d[1]>=d[0]&&d[1]>=d[2]) cnt+=max(d[0],(d[1]+d[2]-1)/2+1);
	else cnt+=(d[0]+d[1]+d[2]-1)/3+1;
	return cnt;
}

int main()
{
	int i,x[5];
	scanf("%d",&n);
	scanf("%d%d%d",&x[1],&x[2],&x[3]);
	for(i=1;i<=n;i++)
		scanf("%I64d",&t[i]);
	sort(x+1,x+4);
	a=x[1];b=x[2];c=x[3];
	if(a+b>=c) printf("%d\n",f1());
	else printf("%d\n",f2());
 return 0;
}

