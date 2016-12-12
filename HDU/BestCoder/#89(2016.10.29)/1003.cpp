#include <bits/stdc++.h>
#define MAXN 52
using namespace std;
const double eps=1e-8;
struct node{
	int to,next;
}edge[MAXN<<1];
int head[MAXN],tot,fa[MAXN],deep[MAXN];
int n,a[MAXN],c[MAXN],cnt;
int dfs[MAXN],in[MAXN],out[MAXN];
long double A[MAXN][MAXN],f[MAXN];
int top;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int pre,int d)
{
	int i;
	++tot;
	dfs[tot]=x;in[x]=tot;
	fa[x]=pre;deep[x]=d;
	for(i=head[x];~i;i=edge[i].next){
		int v=edge[i].to;
		if(v==pre) continue;
		DFS(v,x,d+1);
	}
	out[x]=tot;
}

void DFS2(int x)
{
	int i;
	if(c[x]==0){
		++cnt;
		//printf("  %d",x);
		for(i=in[x];i<=out[x];i++){
			if(deep[i]-deep[x]<=a[x]){
				//printf(" %d",i);
				c[i]^=1;
			}
		}
		//printf("\n");
	}
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==fa[x]) continue;
	 	DFS2(edge[i].to);
	}
}

void Gauss()
{
	for(int i = 0,j = 0;i <= n && j <= n;j ++)
    {
        for(int k = i;k <= n;k ++)
            if (A[k][j]) {swap(A[i],A[k]);break;}
        if (!A[i][j]) continue;
        for(int k = i + 1;k <= n;k ++)
            if (A[k][j])
            {
                long double r = A[k][j] / A[i][j];
                for(int p = j;p <= n + 1;p ++)
                    A[k][p] -= A[i][p] * r;
            }
        i ++;
    }
    memset(f,0,sizeof f);
    for(int i = n - 1;i >= 0;i --)
    {
        for(int j = 0;j <= n;j ++)
            if (i != j)
                f[i] += A[i][j] * f[j];
        f[i] += A[i][n + 1];
        f[i] = (-f[i]) / A[i][i];
    }
}

void fuck()
{
	int i,x,y;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	memset(A,0,sizeof(A));
	tot=0;cnt=0;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	tot=0;
	DFS(1,0,1);
	DFS2(1);
	A[0][0]=1;A[0][1]=-1;A[0][n+1]=-1;
	for(i=1;i<n;i++){
		A[i][i-1]=(long double)i/n;
		A[i][i]=-1;
		A[i][i+1]=(long double)(n-i)/n;
		A[i][n+1]=1;
	}
	A[n][n]=1;
	Gauss();
	//printf("%d\n",cnt);
	printf("%.3f\n",(double)f[n-cnt]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

