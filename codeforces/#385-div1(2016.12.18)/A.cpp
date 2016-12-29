#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[1010],a[1010],num[1010];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	int i,x,y,fx,fy;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		fa[i]=i;
		num[i]=1;
	}
	for(i=1;i<=k;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		fx=find(x);
		fy=find(y);
		fa[fx]=fy;
		num[fy]+=num[fx];
	}
	int sum=0,mx=0,sumx=0;
	for(i=1;i<=k;i++){
		x=num[find(a[i])];
		sum+=x*(x-1)/2;
		mx=max(mx,x);
		sumx+=x;
	}
	sum-=mx*(mx-1)/2;
	mx+=n-sumx;
	sum+=mx*(mx-1)/2;
	cout<<sum-m<<endl;
 return 0;
}

