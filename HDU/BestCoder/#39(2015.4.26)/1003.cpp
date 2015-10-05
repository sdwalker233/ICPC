#include<iostream>
#include<cstdio>
#define N 10000
#define m 10007
using namespace std;
int n;

 void run()
 {
 	int i,j,x,num[N+10]={0},cnt[N+10]={0},tmp[N+10]={0},ans=0,p,t;
 	for(i=1;i<=n;i++){
 		scanf("%d",&x);
 		num[x]++;
 	}
 	for(i=N;i>1;i--){
 		for(j=i;j<=N;j+=i){
 			cnt[i]=(cnt[i]+num[j])%m;
 		}
 		tmp[i]=cnt[i]*cnt[i]%m;
 		for(j=i*2;j<=N;j+=i){
 			tmp[i]=(tmp[i]-tmp[j]+m)%m;
 		}
 		ans=(ans+tmp[i]*i%m*(i-1)%m)%m;
 		//printf(" %d %d\n",i,cnt[i]);
 	}
 	printf("%d\n",ans);
 }

int main()
{
	while(~scanf("%d",&n))
		run();
 return 0;
}

