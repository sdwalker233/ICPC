#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[70],b[70];

int main()
{
    int i,j;
    long long mn;
    b[0]=1;a[1]=1;
    for(i=1;i<63;i++) b[i]=b[i-1]*2;
    for(i=2;i<=64;i++){
        mn=0x7fffffffffffffff;
        for(j=0;j<i;j++){
            if(j+1>62) break;
            mn=min(mn,2*a[i-j-1]+b[j+1]-1);
        }
        a[i]=mn;
    }
    int n;
    while(~scanf("%d",&n))
        cout<<a[n]<<endl;
 return 0;
}
