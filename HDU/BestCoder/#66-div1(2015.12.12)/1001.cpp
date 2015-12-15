#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 50010
using namespace std;
int n,m,a[MAXN],b[MAXN],c[MAXN],mx[2][MAXN];

void fuck()
{
	int i,x,cnt=0;
	memset(c,0,sizeof(c));
	memset(mx,0,sizeof(mx));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		c[x]++;
	}
	for(i=n;i>=1;i--){
		c[i]+=c[i+1];
		b[i]+=c[i]; 
		mx[a[i]][i]=max(b[i],mx[a[i]][i+1]);
		mx[a[i]^1][i]=mx[a[i]^1][i+1];
	}
	for(i=1;i<=n;i++){
		if(b[i]>=mx[a[i]^1][i+1]) cnt++;
	}
	printf("%d\n",cnt);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


