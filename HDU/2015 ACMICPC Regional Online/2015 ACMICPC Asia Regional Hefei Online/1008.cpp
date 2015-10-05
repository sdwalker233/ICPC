#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s1,s2,d;

void fuck()
{
	int i,p,a[50]={0},num=0,n1=0;
	long long ans=0;
	scanf("%d%d%d",&d,&s1,&s2);
	while(d){
		if(d%2) n1++;
		a[++num]=d%2;
		d>>=1;
	}
	do{
		for(i=1;i<=num;i++){
			if(a[i]==0) break;
		}
		p=i;a[p]=1;n1++;
		if(p>num) num++;
		for(i=p-1;i>=1&&n1>s1;i--){
			if(a[i]==1){
				a[i]=0;
				n1--;
			}
		}
	}while(n1<s1||n1>s2);
	for(i=1;i<=num;i++){
		if(a[i]) ans+=(1ll<<(i-1));
	}
	printf("%I64d\n",ans);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}


