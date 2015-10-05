#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char s[2];
	int x,y;
	int t,num;
}op[510];
int n,m,g[110][110];

bool cmp(node x,node y)
{
	return x.t>y.t;
}

void fuck()
{
	int i,j,k,h[110],l[110],tmp;
	memset(h,-1,sizeof(h));
	memset(l,-1,sizeof(l));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=1;i<=m;i++){
		scanf("%s%d%d",op[i].s,&op[i].x,&op[i].y);
		op[i].t=0;op[i].num=i;
	}
	for(k=1;k<=m;k++){
		for(i=1;i<=n;i++){
			if(l[i]==-1){
				tmp=0;
				for(j=1;j<=n;j++){
					if(tmp==0&&g[i][j]>0) tmp=g[i][j];
					else if(tmp!=0&&g[i][j]>0&&g[i][j]!=tmp) break;
				}
				if(j>n) l[i]=tmp;
			}
			if(h[i]==-1){
				tmp=0;
				for(j=1;j<=n;j++){
					if(tmp==0&&g[j][i]>0) tmp=g[j][i];
					else if(tmp!=0&&g[j][i]>0&&g[j][i]!=tmp) break;
				}
				if(j>n) h[i]=tmp;
			}
		}
		/*
		for(i=1;i<=n;i++)
			printf(" %d",l[i]);
		printf("\n");
		for(i=1;i<=n;i++)
			printf(" %d",h[i]);
		printf("\n\n");
		*/
		for(i=1;i<=m;i++){
			if(!op[i].t){
				if(op[i].s[0]=='L'&&(l[op[i].x]==op[i].y||l[op[i].x]==0)){
					op[i].t=k;
					for(j=1;j<=n;j++) g[j][op[i].x]=0;
					l[op[i].x]=0;
					break;
				}
				if(op[i].s[0]=='H'&&(h[op[i].x]==op[i].y||h[op[i].x]==0)){
					op[i].t=k;
					for(j=1;j<=n;j++) g[op[i].x][j]=0;
					h[op[i].x]=0;
					break;
				}
			}	
		}
	}
	sort(op+1,op+m+1,cmp);
	for(i=1;i<m;i++)
		printf("%d ",op[i].num);
	printf("%d\n",op[i].num);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}


