#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
long long a[MAXN];
long long n,p[MAXN];

int main()
{
	long long i,c=0,sum=0;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		if(p[i]<=i){
			c++;
			sum+=i-p[i];
			a[n-(i-p[i])]++;
		}
		else{
			c--;
			sum+=p[i]-i;
			a[p[i]-i]++;
		}
	}
	//printf(" %d %d\n",c,sum);
	long long k=0,mn=sum;
	for(i=1;i<n;i++){
		sum+=c;
		sum+=2*p[n-i+1]-n-2;
		c-=2;
		c+=a[i]*2;
		if(sum<mn){
			mn=sum;
			k=i;
		}
		//printf(" %d %d\n",i,sum);
	}
	cout<<mn<<" "<<k<<endl;
//	printf("%d %d\n",mn,k);
 return 0;
}

