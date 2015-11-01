#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100000
using namespace std;
int n,m,a[MAXN+10],tree1[MAXN+10],tree2[MAXN+10];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int value,int tree[])
{
	for(int i=x;i<=MAXN;i+=lowbit(i)){
		tree[i]+=value;
	}
}

int get(int x,int tree[])
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i)){
		sum+=tree[i];
	}
	return sum;
}

void fuck()
{
	int i;
	long long sum=0,ans;
	memset(tree1,0,sizeof(tree1));
	memset(tree2,0,sizeof(tree2));
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	for(i=n;i>m;i--){
		add(a[i],1,tree2);
		sum+=get(a[i]-1,tree2);
	}
	ans=sum;
	for(i=1;i<=n-m;i++){
		add(a[i+m],-1,tree2);
		sum+=get(MAXN,tree1)-get(a[i],tree1);
		sum+=get(a[i]-1,tree2);
		sum-=get(MAXN,tree1)-get(a[i+m],tree1);
		sum-=get(a[i+m]-1,tree2);
		add(a[i],1,tree1);
		ans=min(ans,sum);
		//printf(" %d\n",sum);
	}
	printf("%I64d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d%d",&n,&m);
		fuck();
	}
 return 0;
}