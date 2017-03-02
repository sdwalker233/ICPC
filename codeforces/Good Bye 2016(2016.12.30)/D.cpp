#include <bits/stdc++.h>
using namespace std;
int dx[]={0,-1,-1,-1,0,1,1,1},dy[]={1,1,0,-1,-1,-1,0,1};
int n,t[100],a[410][410];

void f(int k,int x,int y,int d)
{
	if(k>n) return;
	int i,j,b;
	for(i=1;i<=t[k];i++){
		a[x+dx[d]*i][y+dy[d]*i]=k;
	}
	f(k+1,x+dx[d]*t[k],y+dy[d]*t[k],(d+1)%8);
	if(d%4==0){
		b=x;
		for(i=1;i<=400;i++)
			for(j=1;j<=400;j++)
				if(a[i][j]>k&&2*b-i>0&&2*b-i<=400) a[2*b-i][j]=a[i][j];
	}
	else if(d%4==2){
		b=y;
		for(i=1;i<=400;i++)
			for(j=1;j<=400;j++)
				if(a[i][j]>k&&2*b-j>0&&2*b-j<=400) a[i][2*b-j]=a[i][j];
	}
	else if(d%4==1){
		b=x+y;
		for(i=1;i<=400;i++)
			for(j=1;j<=400;j++)
				if(a[i][j]>k&&b-i>0&&b-i<=400&&b-j>0&&b-j<=400) a[b-j][b-i]=a[i][j];
	}
	else if(d%4==3){
		b=x-y;
		for(i=1;i<=400;i++)
			for(j=1;j<=400;j++)
				if(a[i][j]>k&&j+b>0&&j+b<=400&&i-b>0&&i-b<=400) a[j+b][i-b]=a[i][j];

	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&t[i]);
	f(1,200,200,0);
	int ans=0;
	for(i=1;i<=400;i++)
		for(j=1;j<=400;j++)
			if(a[i][j]>0){
				//printf(" %d %d\n",i,j);
				ans++;
			}
	cout<<ans<<endl;
 return 0;
}

