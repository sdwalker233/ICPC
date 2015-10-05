#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1010];

int main()
{
	int i,j;
	bool ok=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(j=1;j<=n;j++){
		for(i=1;i<=n;i++)
			if(a[i]!=i-1) break;
		if(i>n){
			ok=1;
			break;
		}
		for(i=1;i<=n;i++){
			if(i%2) a[i]++;
			else a[i]--;
			if(a[i]==-1) a[i]=n-1;
			if(a[i]==n) a[i]=0;
		}
	}
	if(ok) printf("Yes\n");
	else printf("No\n");
 return 0;
}

