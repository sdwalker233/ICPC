#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<=n/2) printf("%d\n",m+1);
	else if(m-1>0) printf("%d\n",m-1);
	else printf("%d\n",m);
 return 0;
}


