#include<iostream>
#include<cstdio>
#include<algorithm>
#define m 1000000007
using namespace std;
int n,a[110];
long long num[110],fact[110];

 void run()
 {
 	int i,j;
 	bool visit[110]={0};
 	long long sum=0,rev[110],c=0,count[110]={0};
 	for(i=1;i<=n;i++)
 		scanf("%d",&a[i]);
 	for(i=1;i<=n;i++){
 		for(j=1;j<a[i];j++)
 			if(!visit[j]) count[i]++;
 		visit[a[i]]=1;
 		rev[i]=count[i]*fact[n-i]%m;
 		sum=(sum+count[i]*num[n-i]%m+fact[n-i]*(count[i]*(count[i]-1))/2%m)%m;
 	}
 	for(i=n;i>1;i--){
 		c+=rev[i];
 		sum=(sum+c*count[i-1])%m;
 	}
 	printf("%I64d\n",sum);
 	//for(i=1;i<=n;i++)
 		//printf("%d %I64d %I64d\n",i,count[i],rev[i]);
 }

int main()
{
	num[1]=0;num[2]=1;
	fact[0]=1;
	for(int i=3;i<=100;i++){
		fact[i-2]=fact[i-3]*(i-2)%m;
		num[i]=fact[i-2]*((i*i*(i-1)*(i-1))/4)%m;
	}
	fact[98]=(fact[97]*98)%m;
	fact[99]=(fact[98]*99)%m;
	while(~scanf("%d",&n))
		run();
 return 0;
}

