#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int num=0,prime[50000];
bool is_prime[50000]={0};
int f[50000],rest[110],cnt;

void fuck()
{
	int n,i,j,a,t=2;
	long long ans=1;
	memset(f,0,sizeof(f));
	cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(j=1;j<=num&&a>1;j++)
			if(a%prime[j]==0){
				//printf("  %d\n",j);
				a/=prime[j];
				f[j]++;
				j--;
			}
		if(a>1) rest[++cnt]=a;
	}
	//printf(" %d %d\n",f[1],f[2]);
	for(i=1;i<=num&&t;i++){
		if(f[i]){
			ans*=prime[i];
			f[i]--;
			t--;
			i--;
		}
	}
	if(t){
		if(cnt<t){
			printf("-1\n");
			return;
		}
		sort(rest+1,rest+1+cnt);
		if(t==1) ans*=(long long)rest[1];
		if(t==2) ans*=(long long)rest[1]*rest[2];
	}
	printf("%lld\n",ans);
}

int main()
{
	int i,j;
	for(i=2;i<=50000;i++){
		if(!is_prime[i])
		for(j=i*2;j<=50000;j+=i)
			is_prime[j]=1;
	}
	for(i=2;i<=50000;i++){
		if(!is_prime[i]) prime[++num]=i;
	}
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


