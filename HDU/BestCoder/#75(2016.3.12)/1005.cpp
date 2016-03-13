#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct edge {
    int to, next, cap, flow, cost;
}edge[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;
int n,k,m,P,Q;
int s[210],t[210],p[210];

void init(int n) 
{
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int cap, int cost) 
{
    edge[tol].to = v; edge[tol].cap = cap;
    edge[tol].cost = cost; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = 0;
    edge[tol].cost = -cost; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

bool spfa(int s, int t) 
{
    queue<int> q;
    for(int i = 0; i < N; i++) 
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0; vis[s] = true;
    q.push(s);
    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        { 
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) 
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v]) 
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1) return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s, int t, int &cost) 
{
    int flow = 0;
    cost = 0;
    while(spfa(s, t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) 
        {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) 
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

void fuck()
{
	int i,j,ans;
	scanf("%d%d",&n,&k);
	init(5+2*n+2);
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	scanf("%d%d%d",&m,&P,&Q);
	for(i=1;i<=m;i++)
		scanf("%d%d",&s[i],&t[i]);
	addedge(1,2,INF,0);
	addedge(1,3,INF,0);
	addedge(2,4,k,0);
	for(i=1;i<=n;i++){
		addedge(4,4+i,INF,0);
	}
	for(i=P;i<=n;i++)
		addedge(3,i+4,INF,Q);
	for(i=1;i<=n;i++)
		addedge(i+4,i+4+n,p[i],0);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i+t[j]>n) continue;
			addedge(i+4+n,i+t[j]+4,INF,s[j]);
		}
	}
	for(i=1;i<=n;i++)
		addedge(i+4+n,5+2*n,INF,0);
	minCostMaxflow(1,5+2*n,ans);
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}