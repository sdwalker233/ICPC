#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> PII;
int k,w;
int a[2010],b[2010];
double ans;

int gao(int k,int w,int u)
{
	if(u<=1) return u;
	if(w==1) return k+(k!=u);
	int res=u,x;
	x=u/2+a[u];
	if(k>=x) res=min(res,gao(k-x,w,u-x)+1);
	else res=min(res,gao(k,w-1,x-1)+1);
	return res;
}

void DFS(int x)
{
	if(x>k){
		int i;
		double res=0;
		for(i=0;i<=k;i++){
			int tmp=gao(i,w,k);
			res+=tmp;
		}
		ans=min(res,ans);
		if(res<=29){
			for(i=1;i<k;i++)
				if(i/2+a[i]>(i+1)/2+a[i+1]) return;
			for(i=1;i<=k;i++)
				printf(" %d",i/2+a[i]);
			printf("\n");
			//exit(0);
		}
		return;
	}
	a[x]=0;
	DFS(x+1);
	if(x>2){
		a[x]=1;
		DFS(x+1);
	}
}

void fuck()
{
	int i;
	memset(b,0,sizeof(b));
	ans=1000000;
	b[k]=1;
	for(i=k;i>=2;i--)
		if(b[i]) b[i/2]=b[i/2+1]=1;
	DFS(1);
	/*for(i=0;i<=k;i++){
		int tmp=gao(i,w,k);
		printf(" %d %d\n",i,tmp);
		ans+=tmp;
	}*/
	printf("%.6f\n",ans/(k+1));
}

int main()
{
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&k,&w)) fuck();
	//scanf("%d%d",&k,&w); fuck();
 return 0;
}

