#include <bits/stdc++.h>
using namespace std;
int step[700];
int sum[700][700];
int f[700][700];
int diff[700][700];
int diffsum[700][700];
int n,m,p;

int C(int x,int y)
{
	int c=0;
	while(y>0){
		c++;
		int t=x%y;
		x=y;y=t;
	}
	return c;
}

int F(int x,int y)
{
	int xx=x,yy=y;
	int c=0;
	while(y>0){
		c++;
		int t=x%y;
		x=y;y=t;
	}
	return xx/x*yy/x/c;
}

void init()
{
	int i,j,k;
	for(i=1;i<=666;i++)
		for(j=1;j<=i;j++)
			c[i][j]=C(i,j);
	for(i=1;i<=666;i++){
		for(j=1;j<=i;j++){
			for(k=0;k<c[i][j];k++){
				f[i][j][k]=F(i,j+k*i);
				sum[i][j][k]=sum[i][j][k-1]+f[i][j][k];
			}
			step[i][j]=F(i,j+k*i)-f[i][j][0];
		}
	}
}

void fuck()
{
	int i,j,q;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&p);
	swap(n,m);
	for(i=1;i<=n;i++){
		for(q=1;q<=i;q++){
			long long a1=sum[i][q][c[i][q]],N=m/i,d=step[i][p];
			ans+=(a1+a1+(N-1)*d)*N/2;
			ans+=sum[i][n%i]+m%i*N*d;
			ans%=p;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

