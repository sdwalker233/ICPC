#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a,b;
char str[1010];
bool vis[11010][1010],key[110][110],s[11010][1010];


bool in(int x,int y)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(key[i][j]&&s[i+x-1][j+y-1])
				return 0;
	return 1;
}

void fuck()
{
	int i,j;
	bool flag;
	memset(vis,0,sizeof(vis));
	memset(key,0,sizeof(key));
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",str+1);
		for(j=1;j<=m;j++){
			if(str[j]=='#') key[i][j]=1;
		}
	}
	scanf("%d%d",&a,&b);
	a+=n;
	for(i=n+1;i<=a;i++){
		scanf("%s",str+1);
		for(j=1;j<=b;j++){
			if(str[j]=='#') s[i][j]=1;
		}
	}
	for(i=1;i<=b;i++)
		vis[1][i]=1;
	for(i=2;i<=a;i++){
		flag=0;
		for(j=1;j<=b-m+1;j++){
			if(vis[i][j]) continue;
			if(vis[i-1][j]||(j-1>=1&&vis[i][j-1])||(j+1<=b&&vis[i][j+1])){
				if(in(i,j)){
					vis[i][j]=1;
					//printf(" %d %d\n",i,j);
					flag=1;
					if(j-1>=1&&!vis[i][j-1]) j-=2;
				}
			}
		}
		if(!flag) break;
	}
	if(i>a) printf("The key can fall through.\n");
	else printf("The key falls to depth %d.\n",i-2);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}


