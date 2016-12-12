#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,k;
int a[MAXN],sum[MAXN];
double dp[MAXN];
int qu[MAXN],front,tail;

struct FastIO {
    static const int S = 1000000;
    int wpos, pos, len;
    char wbuf[S];
    FastIO():wpos(0){}
    inline int xchar() {
        static char buf[S];
        if (pos == len) pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos++];
    }
    inline int xint() {
        int c = xchar(), x = 0;
        while (c <= 32 && ~c) c = xchar();
        if (c == -1) return -1;
        for (; c >= '0' && c <= '9'; c = xchar()) x = x * 10 + (c - '0');
        return x;
    }
} io;

double getDP(int i,int j)
{
	return (double)(sum[i]-sum[j])/(i-j);
}

int getUP(int i,int j)
{
	return sum[i]-sum[j];
}

int getDOWN(int i,int j)
{
	return i-j;
}

void fuck()
{
	int i;
	double mx=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//a[i]=io.xint();
		sum[i]=sum[i-1]+a[i];
	}
	front=0;tail=0;
	//qu[tail++]=0;
	for(i=k;i<=n;i++){
		int j=i-k;
		while(tail-front>1&&getUP(j,qu[tail-1])*getDOWN(qu[tail-1],qu[tail-2])<=getUP(qu[tail-1],qu[tail-2])*getDOWN(j,qu[tail-1]) ) tail--;
		qu[tail++]=j;
		while(tail-front>1&&getUP(i,qu[front+1])*getDOWN(i,qu[front])>=getUP(i,qu[front])*getDOWN(i,qu[front+1])) front++;
		mx=max(mx,getDP(i,qu[front]));
	}
	printf("%.2lf\n",mx);
}

int main()
{
	while(1){
		//n = io.xint(); k = io.xint();
		if(scanf("%d%d",&n,&k)==-1) break;
		if(n==-1) break;
		fuck();
	}
 return 0;
}

