#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int v,index,x,y;
	bool use;
}edge[100010];
int n,m;

bool cmp1(const node& x,const node& y)
{
	if(x.v==y.v) return x.use>y.use;
	return x.v<y.v;
}

bool cmp2(const node& x,const node& y)
{
	return x.index<y.index;
}

int main()
{
	int i,j,v,u,p=1,x=1,y=3;
	long long q=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&v,&u);
		edge[i].index=i;
		edge[i].v=v;
		edge[i].use=u;
	}
	sort(edge+1,edge+1+m,cmp1);
	for(i=1;i<=m;i++){
		if(edge[i].use==1){
			edge[i].x=1;
			edge[i].y=++p;
		}
		else{
			x++;
			if(x>=y){
				y++;
				x=2;
			}
			if(y>p){
				printf("-1\n");
				return 0;
			}
			edge[i].x=x;
			edge[i].y=y;
		}
	}
	sort(edge+1,edge+1+m,cmp2);
	for(i=1;i<=m;i++){
		printf("%d %d\n",edge[i].x,edge[i].y);
	}
 return 0;
}

