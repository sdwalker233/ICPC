#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,a,b;
   scanf("%d%d%d",&n,&a,&b);
   a+=b;
   a=(a%n+n)%n;
   if(a==0) a=n;
   cout<<a;
 return 0;
}

