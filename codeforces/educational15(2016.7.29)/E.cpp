#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n;
long long k;
int f[MAXN],w[MAXN];
int nxt[MAXN][40],ww[MAXN][40];
long long sum[MAXN][40];

pair<long long,int> cal(int x,long long step)
{
	if(step==0) return pair<long long,int>(0ll,0x7fffffff);
	int p=log(step)/log(2.0);
	pair<long long,int> tmp=cal(nxt[x][p],step-(1ll<<p));
	tmp.first+=sum[x][p];
	tmp.second=min(tmp.second,ww[x][p]);
	return tmp;
}

int main()
{
	int i,j;
	cin>>n>>k;
	for(i=0;i<n;i++){
		scanf("%d",&f[i]);
		nxt[i][0]=f[i];
	}
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		sum[i][0]=ww[i][0]=w[i];
	}
	for(i=1;i<=35;i++){
		for(j=0;j<n;j++){
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
			sum[j][i]=sum[j][i-1]+sum[nxt[j][i-1]][i-1];
			ww[j][i]=min(ww[j][i-1],ww[nxt[j][i-1]][i-1]);
		}
	}
	for(i=0;i<n;i++){
		pair<long long,int> tmp=cal(i,k);
		printf("%I64d %d\n",tmp.first,tmp.second);
	}
 return 0;
}

