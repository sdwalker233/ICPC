#include<bits/stdc++.h>
using namespace std;
int n;
char a[110][110];
int xx[]={1,1,1,2},yy[]={-1,0,1,0};

bool f(int x,int y)
{
	a[x][y]='.';
	int i;
	for(i=0;i<4;i++){
		int nx=x+xx[i];
		int ny=y+yy[i];
		if(nx<1||nx>n||ny<1||ny>n) return 0;
		if(a[nx][ny]=='.') return 0;
		a[nx][ny]='.';
	}
	return 1;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",&a[i][1]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i][j]=='#'){
				if(!f(i,j)){
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
 return 0;
}
