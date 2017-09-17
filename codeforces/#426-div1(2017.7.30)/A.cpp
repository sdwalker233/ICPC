#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,tt;
	scanf("%d",&tt);
	while(tt-->0){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long l=1,r=1e6+1,mid,t;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*mid*mid<=a*b){
				l=mid+1;
				t=mid;
			}
			else r=mid-1;
		}
		if(t*t*t==a*b&&a%t==0&&b%t==0) printf("Yes\n");
		else printf("No\n");
	}
 return 0;
}

