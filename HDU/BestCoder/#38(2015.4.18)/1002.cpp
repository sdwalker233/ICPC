#include<iostream>
#include<cstdio>
#define MAX 100000
using namespace std;
int n;
void run()
{
	int i,j,x,t[100010]={0},mx=1,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		t[x]++;
		mx=max(mx,x);
	}
	for(i=mx;i>=1;i--){
		cnt=0;
		for(j=i;j<=mx;j+=i)
			cnt+=t[j];
		if(cnt>=2){
			printf("%d\n",i);
			return;
		}
	}
}

int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		run();
	}
 return 0;
}
