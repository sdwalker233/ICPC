#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
struct bits{
    long long v0,v1;
    bits(long long _v0=0,long long _v1=0){
        v0=_v0;v1=_v1;
    }
    bits left(int p){
        if(p<=64){
            long long t=(v0>>(64-p));
            return bits( v0<<p,v1<<p|t );
        }
        else return bits( 0,v0<<(p-64) );
    }
    long long pos(int p){
        if(p<=64) return 1ll<<p&v0;
        else return 1ll<<(p-64)&v1;
    }
    bits oorr(bits x){
        return bits( v0|x.v0,v1|x.v1 );
    }
}dp[11];
struct node{
    int v,index;
}a[55];
int n,m,b[5],pos[55],code[55][55][55];
int ok[130000];

inline int scan()
{
    int res = 0, ch, flag = 0;
    if((ch = getchar()) == '-')
    flag = 1;
    else if(ch >= '0' && ch <= '9')
        res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9' )
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}

bool cmp(const node &x,const node &y)
{
    return x.index<y.index;
}

int check()
{
    int i,j,k,c[55]={0};
    c[b[1]]=c[b[2]]=c[b[3]]=1;
    for(i=0;i<=10;i++)
        dp[i].v0=dp[i].v1=0;
    dp[0].v0=1;
    for(i=1;i<=n;i++){
        if(c[i]||a[i].v>87) continue;
        for(j=10;j>=1;j--){
            dp[j]=dp[j].oorr(dp[j-1].left(a[i].v));
            //for(k=87;k>=a[i].v;k--)
                //if(dp[j-1][k-a[i].v]) dp[j][k]=1;
        }
        if(dp[10].pos(87)) return i;
    }
    return 0;
}

void fuck()
{
    int i,j,k,p,pp=n,cnt=0;
    int f=1;
    memset(ok,0,sizeof(ok));
    b[1]=b[2]=b[3]=0;
    n=scan();
    //scanf("%d",&n);
    for(i=1;i<=n;i++){
        a[i].v=scan();
        //scanf("%d",&a[i].v);
        a[i].index=i;
    }
    m=scan();
    //scanf("%d",&m);
    while(m-->0){
        b[1]=scan();b[2]=scan();b[3]=scan();
        //scanf("%d%d%d",&b[1],&b[2],&b[3]);
        sort(b+1,b+4);
        if(ok[code[b[1]][b[2]][b[3]]]==1) printf("Yes\n");
        else if(ok[code[b[1]][b[2]][b[3]]]==-1) printf("No\n");
        else{
            p=check();
            //printf(" %d\n",p);
            if(p==0){
                ok[code[b[1]][b[2]][b[3]]]=-1;
                printf("No\n");
                continue;
            }
            ok[code[b[1]][b[2]][b[3]]]=1;
            printf("Yes\n");
            for(i=p+1;i<=pp;i++)
                for(j=i;j<=n;j++)
                    for(k=j;k<=n;k++)
                        ok[code[i][j][k]]=1;
            pp=min(p,pp);
        }
    }
}

void init()
{
    int i,j,k;
    for(i=1;i<=50;i++)
        for(j=i;j<=50;j++)
            for(k=j;k<=50;k++)
                code[i][j][k]=i+50*j+50*50*k;
}

int main()
{
    init();
    int t;
    t=scan();
    //scanf("%d",&t);
    while(t-->0) fuck();
 return 0;
}
