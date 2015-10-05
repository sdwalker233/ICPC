#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}

void print(int ans)
{
    if(ans>21600) ans=43200-ans;
    int g=gcd(ans,120);
    if(ans==0) printf("0 ");
    else if(g==120) printf("%d ",ans/120);
    else printf("%d/%d ",ans/g,120/g);
}

void fuck()
{
    int h,m,s,t,ans,g;
    scanf("%d:%d:%d",&h,&m,&s);
    if(h>=12) h-=12;
    t=h*3600+m*60+s;
    ans=t*11%43200;
    print(ans);
    ans=t*719%43200;
    print(ans);
    ans=t*708%43200;
    print(ans);
    printf("\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        fuck(); 
 return 0;
}
