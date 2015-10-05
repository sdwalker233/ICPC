#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i,j;
    double ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        ans=1;
        for(j=1;j<=m;j++)
            ans+=log10(double(j));
        printf("%d\n",(int)ans);
    }
 return 0;
}
