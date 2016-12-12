#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
int n,m;
int a[MAXN],sum[MAXN],dp[MAXN];
int qu[MAXN],front,tail;

int up(int i,int j)
{
	return sum[i]*sum[i]+dp[i]-sum[j]*sum[j]-dp[j];
}

int down(int i,int j)
{
	return 2*(sum[i]-sum[j]);
}

void fuck()
{
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	front=0;tail=0;
	qu[tail++]=0;
	for(i=1;i<=n;i++){
		while(front+1<tail&&sum[i]*down(qu[front+1],qu[front])>=up(qu[front+1],qu[front])) front++;
		dp[i]=dp[qu[front]]+(sum[i]-sum[qu[front]])*(sum[i]-sum[qu[front]])+m;
		while(front+1<tail&&up(i,qu[tail-1])*down(qu[tail-1],qu[tail-2])<=up(qu[tail-1],qu[tail-2])*down(i,qu[tail-1])) tail--;
		qu[tail++]=i;
	}
	printf("%d\n",dp[n]);
}

int main()
{
	while(~scanf("%d%d",&n,&m)) fuck();
 return 0;
}

