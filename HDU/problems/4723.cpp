#include <stdio.h>
#include <math.h>
#define MAXN 100010
using namespace std;
int a,b,n,m,x1[MAXN],x2[MAXN];

double cal(int p,int q)
{
    return hypot((double)(x1[p]-x2[q]),(double)(a-b));
}

void fuck()
{
    int i,j;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&x1[i]);
    for(i=1;i<=m;i++) scanf("%d",&x2[i]);
    int l=2,r=2;
    double l1,l2,ans=cal(1,1);
    while(l<=n||r<=m){
        if(r<=m) l1=cal(l-1,r);
        else l1=1e50;
        if(l<=n) l2=cal(l,r-1);
        else l2=1e50;
        if(l1<l2){
            ans+=l1;
            r++;
        }
        else{
            ans+=l2;
            l++;
        }
        //printf("%d %d\n",l,r);
    }
    printf("%.2f\n",ans);
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("Case #%d: ",i);
        fuck();
    }
 return 0;
}
