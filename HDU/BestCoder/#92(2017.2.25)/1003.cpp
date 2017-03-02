#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[110],k,ans;
char s[110];

void DFS(int x,int p,int cnt)
{
	int i;
	if(x>k){
		if(a[x]-a[x-1]>=3) cnt++;
		ans=max(ans,cnt);
		return;
	}
	int tmp=a[x];
	for(i=p;i<=n-k+x;i++){
		if(m-abs(tmp-i)>=0){
			m-=abs(tmp-i);
			a[x]=i;
			if(i-a[x-1]>=3) cnt++;
			DFS(x+1,i+1,cnt);
			if(i-a[x-1]>=3) cnt--;
			m+=abs(tmp-i);
			a[x]=tmp;
		}
	}
}

void fuck()
{
	int i;
	scanf("%d%d%s",&n,&m,s+1);
	m/=2;k=0;ans=0;
	int l=strlen(s+1);
	for(i=1;i<=l;i++){
		if(s[i]=='2') a[++k]=i;
	}
	a[0]=-100;
	a[k+1]=n+1;
	DFS(1,1,-1);
	printf("%d\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	int i,t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

