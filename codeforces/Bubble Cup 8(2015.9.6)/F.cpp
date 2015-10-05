#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,l[5010],r[5010];

bool in(int x,int p)
{
	if(l[p]<=x&&r[p]>=x) return 1;
	return 0;
}

int main()
{
	int i,ll,rr;
	long long sum=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	ll=rr=x;
	for(i=1;i<=n;i++){
		if(r[i]<ll){
			rr=ll;
			ll=r[i];
			sum+=rr-ll;
		}
		else if(l[i]>rr){
			ll=rr;
			rr=l[i];
			sum+=rr-ll;
		}
		else{
			ll=max(ll,l[i]);
			rr=min(rr,r[i]);
		}
	}
	printf("%I64d\n",sum);
 return 0;
}
