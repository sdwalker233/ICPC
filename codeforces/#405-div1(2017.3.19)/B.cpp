#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,k;
struct node{
	int to,next;
}edge[MAXN<<1];
int tot,head[MAXN],fa[MAXN],step1[MAXN][6],step2[MAXN][6],step3[MAXN][6],step4[MAXN][6],x[MAXN],y[MAXN];

void add_edge(int x,int y)
{
	tot++;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS1(int x,int p)
{
	int i,j;
	fa[x]=p;
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==p) continue;
		DFS1(edge[i].to,x);
		for(j=0;j<k;j++){
			step1[x][j]+=step1[edge[i].to][(j-1+k)%k];
		}
		for(j=1;j<=k;j++){
			step3[x][j]+=step3[edge[i].to][j-1];
		}
	}
	step1[x][0]++;
	step3[x][0]++;
	printf(" %d %d\n",x,fa[x]);
	for(i=1;i<=k;i++) printf(" %d",step3[x][i]);
	printf("\n");
}

void DFS2(int x)
{
	int i;
	if(fa[x]){
		for(i=0;i<k;i++){
			step2[x][i]+=step2[fa[x]][(i-1+k)%k]-step1[x][(i-2+k+k)%k];
		}
		for(i=1;i<=k;i++){
			step4[x][i]+=step4[fa[x]][i-1];
			if(i>=2&&k>=2) step4[x][i]-=step3[x][i-2];
		}
	}
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==fa[x]) continue;
		DFS2(edge[i].to);
	}
}

void DFS3(int x,int p,int d,int r)
{
	if(d>k) return;
	int i,j;
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==p) continue;
		step3[r][d]++;
		DFS3(edge[i].to,x,d+1,r);
	}
}

int main()
{
	int i,j;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
		add_edge(y[i],x[i]);
	}
	DFS1(1,0);
	memcpy(step2,step1,sizeof(step1));
	memcpy(step4,step3,sizeof(step3));
	DFS2(1);
	//for(i=1;i<=n;i++)
		//DFS3(i,0,1,i);
	long long ans=0,cnt=0;
	int tmpx[6],tmpy[6];
	for(i=1;i<n;i++){
		if(fa[x[i]]==y[i]) swap(x[i],y[i]);
		memcpy(tmpy,step1[y[i]],sizeof(tmpy));
		for(j=0;j<k;j++) tmpx[j]=step2[x[i]][j]-tmpy[(j-1+k)%k];
		//tmpy[0];
		//tmpx[0]--;
		for(j=0;j<k;j++){
			ans+=tmpx[(j-1+k)%k]+tmpy[(j-1+k)%k];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			cnt+=step4[i][j];
			printf(" %d %d %d\n",i,j,step4[i][j]);
			
		}
	}
	cout<<ans<<" "<<cnt<<endl;
	cout<<ans-cnt/2<<endl;
 return 0;
}

