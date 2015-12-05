#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define mod 1000000007
using namespace std;

long long p,k;
long long a[MAXN];
long long loop[MAXN]={0},b[MAXN]={0};
bool vis[MAXN]={0};

int main()
{
	int i,j,cnt;
	long long ans=1;
	scanf("%I64d%I64d",&p,&k);
	if(k==0){
		for(i=1;i<p;i++)
			ans=(ans*p)%mod;
		cout<<ans<<endl;
		return 0;
	} 
	for(i=0;i<p;i++)
		a[i]=(i*k)%p;
	for(i=0;i<p;i++){
		if(vis[i]) continue;
		j=a[i];vis[i]=1;cnt=1;
		while(j!=i){
			vis[j]=1;
			++cnt;
			j=a[j];
		}
		loop[cnt]++;
		//printf(" %d\n",cnt);
	}
	for(i=1;i<p;i++){
		if(loop[i]==0) continue;
		for(j=i;j<p;j+=i){
			b[j]=(b[j]+loop[i]*i)%mod;
		}
	}
	for(i=1;i<=p;i++)
		if(loop[i]) 
			for(j=1;j<=loop[i];j++)
				ans=(ans*b[i])%mod;
	cout<<ans<<endl;
	//cin>>p;
 return 0;
}

