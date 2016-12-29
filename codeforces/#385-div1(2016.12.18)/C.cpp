#include <bits/stdc++.h>
using namespace std;
int n;
char col[20][10];
int r[20],b[20];
bool vis[20];
int a[20];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s%d%d",&col[i][0],&r[i],&b[i]);
	}
	int left=0,right=1000000000,mid;
	while(left<right){
		mid=(left+right)/2;
		if(check(mid))
	}
	for(i=1;i<=n;i++) a[i]=i;
	int 
 return 0;
}

