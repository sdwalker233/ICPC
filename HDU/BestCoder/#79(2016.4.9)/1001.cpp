#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffffffffffff
using namespace std;
long long a,b,c,d,ans;

bool takeout(long long x,int p)
{
	return x&(1ll<<(p-1));
}

void dfs(long long a,long long b,long long c,long long d,int p,long long res)
{
	if(p==0){
		ans=max(ans,res);
		return;
	}
	if(a==INF&&b==0&&c==INF&&d==0){
		int i;
		for(i=p;i>=1;i--) res|=(1ll<<(i-1));
		dfs(a,b,c,d,0,res);
		return;
	}
	int aa=takeout(a,p),bb=takeout(b,p),cc=takeout(c,p),dd=takeout(d,p);
	int f=0;
	if(aa==bb) f++;
	if(cc==dd) f++;
	if(f==2){
		dfs(a,b,c,d,p-1,res|((long long)(aa^cc)<<(p-1)));
		return;
	}
//	printf(" %d %d %d %d %d %d %d %d %d\n",a,b,c,d,p,aa,bb,cc,dd);
	if(cc==dd){
		swap(aa,cc);
		swap(a,c);
		swap(bb,dd);
		swap(b,d);
	}
//	printf(" %d %d %d %d %d %d %d %d %d\n",a,b,c,d,p,aa,bb,cc,dd);
	if(aa==bb&&aa==1){
		dfs(a,b,INF,d,p-1,res|(1ll<<(p-1)));
		return;
	}
	if(aa==bb&&aa==0){
		dfs(a,b,c,0,p-1,res|(1ll<<(p-1)));
		return;
	}
	dfs(INF,b,c,0,p-1,res|(1ll<<(p-1)));
	dfs(a,0,INF,d,p-1,res|(1ll<<(p-1)));
}

void fuck()
{
	ans=0;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	dfs(b,a,d,c,60,0);
	printf("ll%d\n",ans);
}

int main()
{
    int t,i;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

