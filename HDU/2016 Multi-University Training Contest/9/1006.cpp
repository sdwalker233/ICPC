//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <cstdlib>
#include <math.h>
#define MAXN 200010
using namespace std;
struct E{
	int to,next;
}edge[MAXN<<1];
int MAX_LOG,MAXDEEP;
int tot,head[MAXN];
int n,q,m;
int A,B,C;
int fa[19][MAXN],dep[MAXN],mxdep[MAXN],sec[MAXN];
int da1,da2;
int root;

inline int scan()
{
	int res = 0, ch;
	ch = getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch  >= '0' && ch <= '9' ){
		res = res * 10 + ch - '0';
		ch=getchar();
	}
	return res;
}

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void Dfs(int p,int pre,int d,int s){
	//printf("%d %d %d %d\n",p,pre,d,s);
    fa[0][p] = pre;
    dep[p] = d;
	MAXDEEP=max(MAXDEEP,d);
    mxdep[p] = d;
	sec[p]=s;
    for(int i = head[p]; ~i; i = edge[i].next){
        int v = edge[i].to;
        if(v == pre) continue;
		int ss=s;
		if(ss==-1) ss=v;
        Dfs(v,p,d + 1,ss);
		mxdep[p]=max(mxdep[p],mxdep[v]);
		if(p==root){
			da2=max(da2,mxdep[v]);
			if(da2>da1) swap(da1,da2);
		}
    }
}
    
void Pre(){
    Dfs(root,-1,0,-1);
	MAX_LOG=log(MAXDEEP*1.0)/log(2.0)+1;
    for(int k = 0; k + 1 < MAX_LOG; ++k){
        for(int v = 1; v <= n; ++v){
            if(fa[k][v] < 0) fa[k + 1][v] = -1;
            else fa[k + 1][v] = fa[k][fa[k][v]];
        }
    }
}

int Lca(int u,int v){
    if(dep[u] > dep[v]) swap(u,v);
    for(int k = MAX_LOG - 1; k >= 0; --k){
        if((dep[v] - dep[u]) & (1 << k))
            v = fa[k][v];
    }
    if(u == v) return u; //u为v的根
    for(int k = MAX_LOG - 1; k >= 0; --k){
        if(fa[k][u] != fa[k][v]){
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    return fa[0][u]; //u离lca只差一步
}

void fuck()
{
	int i,u,v,d,f;
	long long res=0,ans;
	tot=0;da1=da2=-1;MAXDEEP=0;
	memset(head,-1,sizeof(head));
	//scanf("%d%d%d",&n,&q,&m);
	n=scan();q=scan();m=scan();
	for(i=2;i<=n;i++){
		//scanf("%d",&f);
		f=scan();
		addedge(i,f);
		addedge(f,i);
	}
	root=rand()%n+1;
	root=6;
	Pre();
	//printf("%d\n",MAX_LOG);
	//scanf("%d%d%d%d%d%d",&u,&v,&d,&A,&B,&C);
	u=scan();v=scan();d=scan();
	A=scan();B=scan();C=scan();
	//for(i=1;i<=n;i++) printf(" %d\n",sec[i]);
	printf(" %d %d %d\n",root,da1,da2);
	for(i=1;i<=q;i++){
		printf(" %d %d %d\n",u,v,d);
		ans=-1;
		if(u==v) ans=0;
		else{
			int l=Lca(u,v);
			if(dep[u]+dep[v]-2*dep[l]>=d) ans=1;
			else{
				if(l==u){
					if(mxdep[v]-dep[v]>=d) ans=2;
				}
				else if(l==v){
					if(mxdep[u]-dep[u]>=d) ans=2;
				}
				else if(mxdep[u]-dep[u]>=d||mxdep[v]-dep[v]>=d) ans=2;
				if(ans==-1){
					if(dep[u]>=d&&dep[v]>=d) ans=2;
					else if(l!=root&&da2!=-1){
						int haha=da1;
						if(haha==mxdep[sec[u]]) haha=da2;
						printf("haha:%d ",haha);
						if(dep[u]+haha>=d&&dep[v]+haha>=d) ans=2;
					}
				}
			}
		}
		printf(" %lld\n",ans);
		u=(1ll*A*u+B+ans)%n+1;
		v=(1ll*B*v+C+ans)%n+1;
		d=(1ll*C*d+A+ans)%m;
		res+=(ans+1)*i;
	}
	printf("%lld\n",res);
}

int main()
{	//int begin=clock();
	//freopen("in.txt","r",stdin);
	srand(time(NULL));
	int t;
	//scanf("%d",&t);
	t=scan();
	while(t-->0) fuck();
	//printf("%d\n",(clock()-begin)/1000);
 return 0;
}

