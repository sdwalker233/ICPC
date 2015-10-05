#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a,b[100],ans;

bool cmp(int x,int y)
{
	return x>y;
}

void DFS(int x,int p,int sum)
{
	if(p>n&&x!=0){
		return;
	}
	if(x==0){
		ans=min(sum,ans);
		return;
	}
	DFS(x%b[p],p+1,sum+1);
	DFS(x,p+1,sum);
}

void fuck()
{
	int i;
	ans=100;
	scanf("%d%d",&n,&a);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+1+n,cmp);
	DFS(a,1,0);
	if(ans==100) ans=-1;
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t); 
	while(t--)
		fuck();
 return 0;
}

