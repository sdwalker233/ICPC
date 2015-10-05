#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[20],l,r,x,cnt=0;
bool use[20];

 void DFS(int p)
 {
 	if(p>n){
 		int i,sum=0,mx=0,mn=0x7fffffff;
 		for(i=1;i<=n;i++){
 			if(use[i]){
 				sum+=a[i];
 				mx=max(mx,a[i]);
 				mn=min(mn,a[i]);
 			}
 		}
 		if(sum>=l&&sum<=r&&mx-mn>=x) cnt++;
 		return;
 	}
 	use[p]=1;
 	DFS(p+1);
 	use[p]=0;
 	DFS(p+1);
 }

int main()
{
	int i;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	DFS(1);
	printf("%d\n",cnt);
 return 0;
}

