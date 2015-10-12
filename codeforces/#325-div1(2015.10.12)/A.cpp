#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long v[1000010],d[1000010],p[1000010];
int n,ans[100010],cnt=0;

int main()
{
	int i,j;
	long long dmg1,dmg2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d%I64d",&v[i],&d[i],&p[i]);
	}
	for(i=1;i<=n;i++){
		if(p[i]>=0){
			ans[++cnt]=i;
			dmg1=v[i];dmg2=0;
			for(j=i+1;j<=n;j++){
				if(p[j]<0) continue;
				p[j]-=dmg1+dmg2;
				if(p[j]<0) dmg2+=d[j];
				if(dmg1) dmg1--;
			}
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<cnt;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[cnt]);
 return 0;
}


