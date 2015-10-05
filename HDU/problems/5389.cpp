#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=258280327;

int n,A,B,a[100010],f[20]={0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
int b[12],c[12];

int root(int x)
{
    if(x<10) return x;
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return root(sum);
}

void fuck()
{
    int i,j,sum=0,ans=0;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d%d%d",&n,&A,&B);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum=root(sum);
    if(sum!=f[A+B]&&sum!=A&&sum!=B){
        printf("0\n");
        return;
    }
    for(i=1;i<=n;i++){
        c[a[i]]=(c[a[i]]+1)%mod;
        for(j=1;j<=9;j++){
            c[f[j+a[i]]]=(c[f[j+a[i]]]+b[j])%mod;
        }
        memcpy(b,c,sizeof(b));
    }
    //for(i=1;i<=9;i++)
    //    printf(" %d\n",b[i]);
    if(sum==B) printf("%d\n",b[A]+1);
    else printf("%d\n",b[A]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        fuck();
 return 0;
}
