#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int w,s,index;
}a[1010];

int n,pre[1010];

bool cmp(const node& x,const node& y)
{
	if(x.w!=y.w) return x.w<y.w;
	return x.s<y.s;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n=1,i,j,mx,pos;
	int dp[1010]={0},ans[1010],cnt=0;
	
	while(~scanf("%d%d",&a[n].w,&a[n].s)){
		a[n].index=n;
		n++;
	}
	n--;
	//printf("%d\n",n);
	/*
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].s);
		a[i].index=i;
	}*/
	//for(i=1;i<=n;i++) printf("  %d %d\n",a[i].w,a[i].s);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		mx=0;
		dp[i]=1;pre[i]=i;
		for(j=1;j<i;j++){
			if(a[j].s>a[i].s&&dp[j]>mx){
				mx=dp[j];pos=j;
			}
		}
		if(mx){
			dp[i]=dp[pos]+1;
			pre[i]=pos;
		}
		//printf(" %d %d\n",pre[i],dp[i]);
	}
	mx=0;
	for(i=1;i<=n;i++){
		if(dp[i]>mx){
			mx=dp[i];
			pos=i;
		}
	}
	do{
		//printf("%d\n",pos);
		ans[++cnt]=pos;
		pos=pre[pos];
	}while(pre[pos]!=pos);
	ans[++cnt]=pos;
	printf("%d\n",cnt);
	for(i=cnt;i>=1;i--){
		printf("%d\n",a[ans[i]].index);
	}
 return 0;
}
