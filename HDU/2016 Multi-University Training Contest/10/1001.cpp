#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int A[100010];

void fuck()
{
	int i,p,a,b,c,d,l1,l2,r1,r2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	while(m-->0){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long ans=0;
		if(l1>l2){
			swap(l1,l2);
			swap(r1,r2);
		}
		if(r1>r2) swap(r1,r2);
		if(r1<l2){
			a=r1-l1+1;
			b=r2-l2+1;
			p=(a+b+1)/2;
			if(p<=a) ans+=A[l1+p-1];
			else ans+=A[l2+p-a-1];
			p=(a+b+2)/2;
			if(p<=a) ans+=A[l1+p-1];
			else ans+=A[l2+p-a-1];
		}
		else{
			a=l2-l1;
			b=r1-l2+1;
			c=r2-r1;
			p=(a+2*b+c+1)/2;
			if(p<=a) ans+=A[l1+p-1];
			else if(p>a+2*b) ans+=A[l2+p-a-b-1];
			else ans+=A[l1+(p-a+1)/2+a-1];
			p=(a+2*b+c+2)/2;
			if(p<=a) ans+=A[l1+p-1];
			else if(p>a+2*b) ans+=A[l2+p-a-b-1];
			else ans+=A[l1+(p-a+1)/2+a-1];
		}
		printf("%.1lf\n",ans/2.0);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

