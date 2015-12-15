#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100010];
bool vis[100010]={0},b[100010]={0};

int main()
{
	int n,i,mx=0,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=1;
		if(vis[a[i]-1]) b[a[i]]=1;
	}
	for(i=1;i<=n;i++){
		if(b[i]){
			sum++;
			mx=max(mx,sum);
		}
		else sum=0;
	}
	printf("%d\n",n-mx-1);
 return 0;
}


