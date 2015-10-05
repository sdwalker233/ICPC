#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[100010];

int main()
{
	int i,j,p,q;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++){
		scanf("%d",&p);
		for(j=1;j<=p;j++)
			scanf("%d",&a[j]);
		if(a[1]==1){
			q=1;
			while(q<p&&a[q+1]==q+1) q++;
		}
	}
	printf("%d\n",n-k-(q-1)+n-q);
 return 0;
}

