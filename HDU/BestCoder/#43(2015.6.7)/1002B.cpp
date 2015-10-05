#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;long long p;long long a[100010];void fuck(){int i,pos;long long mx=0;a[0]=0;for(i=1;i<=n;i++){scanf("%I64d",&a[i]);a[i]%=p;}sort(a+1,a+n+1);for(i=1;i<=n;i++){pos=lower_bound(a+1,a+n+1,p-a[i])-a;if(i<n) mx=max((a[i]+a[n])%p,mx);if(pos>1){if(pos-1==i&&(pos<=2||a[pos-2]!=a[pos-1])){if(pos>2&&a[pos-2]!=a[pos-1])mx=max(a[pos-2]+a[i],mx);continue;}mx=max(a[pos-1]+a[i],mx);}}printf("%I64d\n",mx);}int main(){while(~scanf("%d%I64d",&n,&p)){fuck();}return 0;}
