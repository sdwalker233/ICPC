#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void tran(long long x,int a[])
{
	int i=0;
	while(x){
		a[++i]=(x&1);
		x>>=1;
	}
	a[0]=i;
}

void fuck()
{
	int i,j;
	long long x,k,ans=0;
	int a[100]={0},b[100]={0};
	scanf("%I64d%I64d",&x,&k);
	tran(x,a);
	tran(k,b);
	j=0;
	for(i=1;i<=b[0];i++){
		j++;
		while(a[j]) j++;
		ans+=((long long)b[i]<<(j-1));
	}
	printf("%I64d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


