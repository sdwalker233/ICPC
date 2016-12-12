#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

vector<int> lk[maxn];
int stk[maxn],a[maxn],col[maxn],fc[maxn],dep[maxn],n,top;

void dfs(int now,int pre)
{
    dep[now] = dep[pre] + 1;
    int c = 0;
    for(int i = 1;i <= top;i ++)
        if (dep[now] - dep[stk[i]] <= a[stk[i]]) c ^= fc[stk[i]];
    if (!(col[now] ^ c)) fc[now] = 1;
    stk[++ top] = now;
    for(int i = 0;i < lk[now].size();i ++)
        if (lk[now][i] != pre)
            dfs(lk[now][i],now);
    top --;
}

long double f[maxn];

void gauss()
{
    static long double a[maxn][maxn];
    memset(a,0,sizeof a);
    a[n][n] = 1;
    for(int i = 0;i < n;i ++)
    {
        a[i][i] = 1;
        a[i][i + 1] = -(n - i) / (long double)(n);
        if (i) a[i][i - 1] = -i / (long double)(n);
        a[i][n + 1] = -1;
    }
    for(int i = 0,j = 0;i <= n && j <= n;j ++)
    {
        for(int k = i;k <= n;k ++)
            if (a[k][j]) {swap(a[i],a[k]);break;}
        if (!a[i][j]) continue;
        for(int k = i + 1;k <= n;k ++)
            if (a[k][j])
            {
                long double r = a[k][j] / a[i][j];
                for(int p = j;p <= n + 1;p ++)
                    a[k][p] -= a[i][p] * r;
            }
        i ++;
    }
    memset(f,0,sizeof f);
    for(int i = n - 1;i >= 0;i --)
    {
        for(int j = 0;j <= n;j ++)
            if (i != j)
                f[i] += a[i][j] * f[j];
        f[i] += a[i][n + 1];
        f[i] = (-f[i]) / a[i][i];
    }
} 

void work()
{
    memset(lk,0,sizeof lk);
    scanf("%d", &n);
    for(int i = 1;i < n;i ++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        lk[u].push_back(v),lk[v].push_back(u);
    }
    for(int i = 1;i <= n;i ++)
        scanf("%d", &col[i]);
    for(int i = 1;i <= n;i ++)
        scanf("%d", &a[i]);
    memset(fc,0,sizeof fc);
    dfs(1,0);
    gauss();
    int c = 0;
    for(int i = 1;i <= n;i ++)
        if (!fc[i])
            c ++;
	
    printf("%d\n%.3f\n", c,double(f[c]));
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t;t --) work();
    return 0;
}
