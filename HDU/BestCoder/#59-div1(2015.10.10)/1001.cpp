#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int a[20];
	int step;
	int v;
	int last;
	bool b[20];
	node(){
		memset(b,0,sizeof(b));
	}
};
int n,a[20];
bool vis[(1<<19)+1];

int cal(node x)
{
	int i,v=0;
	for(i=1;i<=n;i++){
		if(x.b[i]) v+=(1<<(i-1));
	}
	return v;
}

int BFS()
{
	int i,j;
	memset(vis,0,sizeof(vis));
	node tmp,now;
	queue<node> qu;
	memcpy(tmp.a,a,sizeof(a));
	tmp.step=0;
	tmp.v=0;
	tmp.last=n+1;
	vis[tmp.v]=1;
	qu.push(tmp);
	while(!qu.empty()){
		now=qu.front();
		qu.pop();
		/*printf("%d  ",now.step);
		for(i=1;i<=n;i++)
			printf("%d ",now.a[i]);
		printf("\n");*/
		for(i=1;i<=n;i++)
			if(now.a[i]!=i) break;
		if(i>n) return now.step;
		for(i=1;i<=n;i++){
			if(!now.b[now.a[i]]){
				if(now.a[i]>=now.last) continue;
				tmp=now;
				tmp.b[now.a[i]]=1;
				tmp.v=cal(tmp);
				if(vis[tmp.v]) continue;
				tmp.step++;
				tmp.last=now.a[i];
				int t=now.a[i];
				for(j=i-1;j>=1;j--) tmp.a[j+1]=tmp.a[j];
				tmp.a[1]=t;
				vis[tmp.v]=1;
				qu.push(tmp);
			}
		}
	}
}

void fuck()
{
	int i,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//while(n>=0&&n==a[n]) n--;
	//printf("%d\n",BFS());
	for(i=1;i<=n;i++){
		if(a[i]==n){
			m=i;
			break;
		}
	}
	int ans=n,p=n;
	for(i=m;i>=1;i--){
		if(a[i]==p){
			p--;
			ans--;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}
