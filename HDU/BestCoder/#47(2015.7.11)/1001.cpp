#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffffff
using namespace std;
long long n,p,a[1010];

 void fuck()
 {
	 long long i,j,tmp;
	 bool ok;
	 long long ans,k,sum;
	 scanf("%lld%lld",&n,&p);
	 ans=p;
	 for(i=1;i<=n;i++)	scanf("%lld",&a[i]);
	 for(i=1;i<=n;i++){
		 swap(p,a[i]);
		 k=a[1];sum=0;
		 for(j=1;j<=n;j++){
			 sum+=a[j];
			 if(sum<0){
				 k=max(k,a[j]);
				 sum=0;
			 }
			 else{
				 k=max(k,sum);
			 }
		 }
		 ans=max(ans,k);
		 swap(p,a[i]);
	 }
	 printf("%lld\n",ans);
 }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

