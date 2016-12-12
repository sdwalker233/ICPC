#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
int n,m,k,a[210];
int x[210],y[210];
long long C[1010][1010],dp[2][510][510];

void init()
{
	int i,j,k;
	for(i=1;i<=1000;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<1000;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}

void fuck()
{
	int i,xx,yy,p=0;
	scanf("%d%d%d",&n,&m,&k);
	a[0]=0;
	for(i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=250;y[i]+=250;
	}
	for(i=1;i<=m;i++){
		for(xx=0;xx<=500;xx++){
			for(yy=0;yy<=500;yy++){
				dp[i][xx][yy]=1;
				for(j=a[i-1]+1;j<=a[i];j++){
					int dx=abs(xx-x[i]);
					int dy=abs(yy-y[i]);
					if((dx+dy+k)%2){
						dp[i][xx][yy]=0;
						break;
					}
					long long res=C[k][(dx-dy+k)>>1]*C[k][(k-dx-dy)>>1]%mod;
					dp[i][xx][yy]*=res;
					dp[i][xx][yy]%=mod;
				}
			}
		}
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

