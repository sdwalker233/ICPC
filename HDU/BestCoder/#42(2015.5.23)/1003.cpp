#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int maze[110][110];
bool ok[110][110][110];
	
int main()
{
	int n,m,k,i,j,p;
	while(~scanf("%d%d%d",&n,&m,&k)){
		memset(ok,0,sizeof(ok));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&maze[i][j]);
		ok[1][1][0]=ok[1][1][maze[1][1]]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				for(p=0;p<=k;p++){
					if(ok[i][j][p]){
						if(i<n){
							ok[i+1][j][p]=1;
							if(p+maze[i+1][j]<=k)ok[i+1][j][p+maze[i+1][j]]=1;
						}
						if(j<m){
							ok[i][j+1][p]=1;
							if(p+maze[i][j+1]<=k)ok[i][j+1][p+maze[i][j+1]]=1;
						}
					}
				}
		for(i=k;i>=0;i--)
			if(ok[n][m][i]){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}

