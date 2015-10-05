#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int s[110][110];
int a[110],b[110]={0},vis[110]={0};

int main()
{
	int i,j,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%1d",&s[i][j]);
		}
	}
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(1){
		bool flag=0;
		for(i=0;i<n;i++)
			if(a[i]==b[i]){
				vis[i]=1;
				for(j=0;j<n;j++) b[j]+=s[i][j];
				flag=1;
				break;
			}
			if(!flag) break;
	}
	for(i=0;i<n;i++)
		if(vis[i]) cnt++;
	printf("%d\n",cnt);
	for(i=0;i<n;i++)
		if(vis[i]) printf("%d\n",i+1);
 return 0;
}
