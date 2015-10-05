#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define MAXN 100010
#define LL long long
#define MOD 998244353

LL p[MAXN];

void init()
{
    p[0] = p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    for(int i = 4; i <= 100000; i++)
    {
        p[i] = 0;
        int flag = 1;
        for(int j = 1; ; j++)
        {
            int p1 = j * (3 * j - 1) / 2;
            int p2 = j * (3 * j + 1) / 2;
            if(p1 > i && p2 > i) break;
            if(p1 <= i) p[i] = (p[i] + flag * p[i - p1] + MOD) % MOD;
            if(p2 <= i) p[i] = (p[i] + flag * p[i - p2] + MOD) % MOD;
            flag *= (-1);
        }
    }
}

LL solve(int n, int k)
{
    LL ret = p[n];
    int flag = -1;
    for(int j = 1; ; j++)
    {
        int p1 = k * j * (3 * j - 1) / 2;
        int p2 = k * j * (3 * j + 1) / 2;
        if(p1 > n && p2 > n) break;
        if(p1 <= n) ret = (ret + flag * p[n - p1] + MOD) % MOD;
        if(p2 <= n) ret = (ret + flag * p[n - p2] + MOD) % MOD;
        flag *= (-1);
    }
    return ret;
}

int main()
{
//    freopen("4658.in", "r", stdin);

    init();
    int t, n,c,l,r,i;
    LL a=0;
    LL ans[100001];
    for(i=1;i<=100000;i++){
    	ans[i]=solve(i,2);
    }
    	
    scanf("%d", &t);
    while(t--)
    {
    	a=0;
        scanf("%d%d%d%d", &n,&c,&l,&r);
        for(i=l;i<=r;i++)
        	a=(ans[i-c]+a)%MOD;
        printf("%lld",a);
    }
    return 0;
}

