#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k,m;

void fuck()
{
	int i,j,x,c,r,cnt;
	bool a[10000]={0},ok=1;
	for(i=1;i<=k;i++){
		scanf("%d",&x);
		a[x]=1;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&c,&r);
		cnt=0;
		for(j=1;j<=c;j++){
			scanf("%d",&x);
			cnt+=a[x];
		}
		if(cnt<r) ok=0;
	}
	if(ok) printf("yes\n");
	else printf("no\n");
}
int main()
{
	while(~scanf("%d",&k)&&k){
		scanf("%d",&m);
		fuck();
	}
 return 0;
}


