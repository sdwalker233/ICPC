#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXM=4000005;
const int INF=0x7fffffff;

int head[MAXM],next[MAXM],point[MAXM],size,p[MAXM];
bool visit[MAXM];
bool v[MAXM];
bool z[MAXM],ok=0;

void add(int a,int b,int f){
	if(f){
		point[size]=b;
		next[size]=head[a];
		p[size]=size+1;
		head[a]=size++;
		point[size]=a;
		next[size]=head[b];
		p[size]=size-1;
		head[b]=size++;
	}
	else{
		point[size]=b;
		next[size]=head[a];
		p[size]=size;
		head[a]=size++;
	}
}

void dfs(int s){
	int i,j;
	z[s]=v[s]=1;
	for(i=head[s];~i;i=next[i]){
		if(visit[i])continue;
		int t=point[i];
		visit[i]=1;
		visit[p[i]]=1;
		if(z[t]){ok=1;return;}
		if(v[t])continue;
		dfs(t);
	}
	z[s]=0;
}

void fuck()
{
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	int i,j;
	size=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=m1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b,1);
	}
	for(i=1;i<=m2;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b,0);
	}
	ok=0;
	memset(v,0,sizeof(v));
	memset(visit,0,sizeof(visit));
	memset(z,0,sizeof(z));
	for(i=1;i<=n;i++){
		if(ok)break;
		if(!v[i]){
			dfs(i);
		}
	}
	if(!ok)printf("NO\n");
	else printf("YES\n");
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

