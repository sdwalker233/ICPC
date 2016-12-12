#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
const int mod=1e9+7;
bool not_prime[MAXN];
int tot=0,prime[MAXN],N=1000000;
long long res[MAXN],n;
int pnum[MAXN][10],cnt[MAXN];

void init()
{
	int i,j;
	for(i=2;i<=N;i++){
		if(!not_prime[i]){
			prime[++tot]=i;
		}
		for(j=1;j<=tot&&i*prime[j]<=N;j++){
			not_prime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	for(int p=1;p<=N;p++){
		//printf("%d\n",p);
		int x=p;
		i=1;
		while(x>1){
			if(!not_prime[x]){
				pnum[p][++cnt[p]]=x;
				break;
			}
			if(x%prime[i]==0){
				pnum[p][++cnt[p]]=prime[i];
				while(x%prime[i]==0) x/=prime[i];
			}
			i++;
		}
	}
}

long long cal(int p,int pnum[],int cnt)
{
	int i=1,j;
	long long ans=0;
	for(i=0;i<(1<<cnt);++i){
		int bit=0;
		int mul=1;
		for(j=1;j<=cnt;++j){
			if(i&(1<<(j-1))){
				bit++;
				mul*=pnum[j];
			}
		}
		if(bit%2==0) ans+=(n/p)/mul-p/mul;
		else ans-=(n/p)/mul-p/mul;
		//ans=(ans+mod)%mod;
	}
	return ans;
}

void fuck()
{
	int i,p;
	long long sum=0;
	scanf("%lld",&n);
	for(p=1;(long long)p*p<=n;p++){
		//printf(" %d\n",p);
		res[p]=cal(p,pnum[p],cnt[p]);
		//printf("%d\n",res[p]);
		//res[p]-=phi[p];
		sum=(sum+res[p])%mod;
	}
	sum=(sum*2+1)%mod;
	printf("%lld\n",sum);
}

int main()
{
	init();
	//printf("***\n");
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

