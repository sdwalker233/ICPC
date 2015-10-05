#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q,ans[510];
 int f(int a[])
 {
 	int i,tmp=0,mx=0;
 	for(i=1;i<=m;i++){
 		if(a[i]){
 			tmp++;
 			mx=max(mx,tmp);
 		}
 		else tmp=0;
 	}
 	return mx;
 }

int main()
{
	int i,j,a[510][510],x,y,mx=0,tmp;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++){
		ans[i]=f(a[i]);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(a[x][y]) a[x][y]=0;
		else a[x][y]=1;
		ans[x]=f(a[x]);
		mx=0;
		for(j=1;j<=n;j++){
			mx=max(ans[j],mx);
		}
		printf("%d\n",mx);
	}
 return 0;
}

