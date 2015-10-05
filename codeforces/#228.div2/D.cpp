#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
bool g[950][950]={0};

int pos(int x,int y)
{
	return (x-1)*30+y+2;
}

int main()
{
	int i,j,x,y;
	for(i=3;i<=32;i++)
		g[1][i]=g[i][1]=1;
	for(i=2;i<=30;i++){
		for(j=1;j<i;j++){
			x=pos(i,j);
			y=pos(i-1,j);
			g[x][y]=g[y][x]=1;
		}
		for(j;j<=30;j++){
			x=pos(i,j);
			y=pos(i-1,29);
			g[x][y]=g[y][x]=1;
			y=pos(i-1,30);
			g[x][y]=g[y][x]=1;
		}
	}
	scanf("%d",&k);
	for(i=29;i>=0;i--){
		if(k>=(1<<i)){
			x=pos(30,i+1);
			g[2][x]=g[x][2]=1;
			k-=(1<<i);
		}
	}
	printf("902\n");
	for(i=1;i<=902;i++){
		for(j=1;j<=902;j++){
			if(g[i][j]) printf("Y");
			else printf("N");
		}
		printf("\n");
	}
 return 0;
}

