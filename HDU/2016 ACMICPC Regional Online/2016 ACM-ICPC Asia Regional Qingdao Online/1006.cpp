#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n,m,a[MAXN],d[MAXN];

void fuck()
{
	int i,x,y,ji=0,ans=0,t,ans2=0,ans3=0;
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans3=max(ans3,a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
	}
	for(i=1;i<=n;i++){
		if(d[i]&1) ji++;
	}
	if(m==0){
		printf("%d\n",ans3);
		return;
	}
	if(!(ji==0||ji==2)){
		printf("Impossible\n");
		return;
	}
	for(i=1;i<=n;i++)
		if(((d[i]+1)/2)%2) ans^=a[i];
	if(ji==0){
		for(i=1;i<=n;i++)
			if(d[i]) ans2=max(ans2,ans^a[i]);
	}
	else ans2=ans;
	printf("%d\n",ans2);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

