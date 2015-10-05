#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char s[5];
	int x,y;
	int num,t;
}a[510];
int n,m,g[110][110];

bool cmp(node x,node y)
{
	return x.t>y.t;
}

void fuck()
{
	int i,j,k;
	bool ok;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=1;i<=m;i++){
		scanf("%s%d%d",a[i].s,&a[i].x,&a[i].y);
		a[i].num=i;a[i].t=0;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			if(a[j].t) continue;
			if(a[j].s[0]=='H'){
				for(k=1;k<=n;k++){
					if(g[a[j].x][k]!=a[j].y&&g[a[j].x][k]!=0) break;
				}
				if(k>n){
					a[j].t=i;
					for(k=1;k<=n;k++){
						g[a[j].x][k]=0;
					}
					break;
				}
			}
			if(a[j].s[0]=='L'){
				for(k=1;k<=n;k++){
					if(g[k][a[j].x]!=a[j].y&&g[k][a[j].x]!=0) break;
				}
				if(k>n){
					a[j].t=i;
					for(k=1;k<=n;k++){
						g[k][a[j].x]=0;
					}
					break;
				}
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<m;i++)
		printf("%d ",a[i].num);
	printf("%d\n",a[i].num);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}


