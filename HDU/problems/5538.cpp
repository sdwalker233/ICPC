#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int n,m,a[55][55];

void fuck()
{
	int i,j,k,ans=0,xx,yy;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==0) continue;
			ans++;
			for(k=0;k<4;k++){
				xx=i+dx[k];
				yy=j+dy[k];
				if(a[i][j]>a[xx][yy])
					ans+=a[i][j]-a[xx][yy];
			}
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