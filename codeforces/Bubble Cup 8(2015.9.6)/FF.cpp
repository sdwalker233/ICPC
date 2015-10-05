#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffffffffffff
using namespace std;
int n,x,l[5010],r[5010];
long long dp1[5010][3]={0},dp2[5010][3]={0};

int cost(int x,int p)
{
	if(l[p]>x) return l[p]-x;
	if(r[p]<x) return x-r[p];
	return 0;
}

int abs(int x)
{
	return x>0?x:-x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,t=0;
	while(~scanf("%d%d",&n,&x)){
	printf("Case #%d:",++t);
	long long ans=INF,tmp;	
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	l[0]=r[0]=x;
	for(i=n;i>=0;i--){
		dp1[i][0]=dp1[i][1]=INF;
		tmp=0;
		for(j=i+1;j<=n;j++){
			dp1[i][0]=min(dp1[i][0],tmp+abs(l[i]-l[j])+dp1[j][0]);
			dp1[i][0]=min(dp1[i][0],tmp+abs(l[i]-r[j])+dp1[j][1]);
			tmp+=cost(l[i],j);
		}
		dp1[i][0]=min(dp1[i][0],tmp);
		tmp=0;
		for(j=i+1;j<=n;j++){
			dp1[i][1]=min(dp1[i][1],tmp+abs(r[i]-l[j])+dp1[j][0]);
			dp1[i][1]=min(dp1[i][1],tmp+abs(r[i]-r[j])+dp1[j][1]);
			tmp+=cost(r[i],j);
		}
		dp1[i][1]=min(dp1[i][1],tmp);
	}
	for(i=0;i<=n;i++){
		dp2[i][0]=dp2[i][1]=INF;
		tmp=0;
		for(j=i-1;j>=0;j--){
			dp2[i][0]=min(dp2[i][0],tmp+abs(l[i]-l[j])+dp2[j][0]);
			dp2[i][0]=min(dp2[i][0],tmp+abs(l[i]-r[j])+dp2[j][1]);
			tmp+=cost(l[i],j);
		}
		dp2[i][0]=min(dp2[i][0],tmp);
		tmp=0;
		for(j=i-1;j>=0;j--){
			dp2[i][1]=min(dp2[i][1],tmp+abs(r[i]-l[j])+dp2[j][0]);
			dp2[i][1]=min(dp2[i][1],tmp+abs(r[i]-r[j])+dp2[j][1]);
			tmp+=cost(r[i],j);
		}
		dp2[i][1]=min(dp2[i][1],tmp);
	}
	for(i=0;i<=n;i++){
		ans=min(ans,min(dp1[i][0]+dp2[i][0],dp1[i][1]+dp2[i][1]));
		printf("%I64d %I64d %I64d %I64d\n",dp1[i][0],dp2[i][0],dp1[i][1],dp2[i][1]);
	}
	printf("%I64d\n",ans);
	
	}
 return 0;
}


