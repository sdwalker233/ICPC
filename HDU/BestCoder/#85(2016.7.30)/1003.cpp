#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define MAXN 100010
using namespace std;
bool flag[MAXN]={0};  
int prime[MAXN],cnt=0;
long long x,xx;

void init(){
    for(int i=2;i<MAXN;i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<MAXN;j++)
            flag[i*j]=true;
    }
}

bool check(int n)
{
	if(n<=1) return 0;
	int i;
	for(i=0;i<cnt&&prime[i]<=n;i++){
		if(n%prime[i]==0){
			n/=prime[i];
			if(n%prime[i]==0) return 0;
		}
	}
	return 1;
}

void fuck()
{
	int i=0;
	scanf("%lld",&x);
	if(x==1){printf("3\n");return;}
	if(x==2){printf("2\n");return;}
	xx=sqrt(x*1.0+0.5);
	int num=0;
	long long ans=x,tmp;
	while(num<=6){
		tmp=xx+i;
		if(check(tmp)){
			ans=min(ans,llabs(tmp*tmp-x));
			num++;
		}
		tmp=xx-i;
		if(check(tmp)){
			ans=min(ans,llabs(tmp*tmp-x));
			num++;
		}
		i++;
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

