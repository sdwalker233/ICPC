#include <bits/stdc++.h>
using namespace std;
int fa[200010];
int a[200010];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	int n,i,root=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==a[i]) root=i;
		//printf(" %d %d %d\n",i,a[i],find(i));
		if(find(i)!=i||find(i)==find(a[i])){
			a[i]=0;
		}
		else{
			fa[i]=a[i];
		}
	}
	int cnt=-1;
	if(root==0){
		for(i=1;i<=n;i++)
			if(find(i)==i){
				root=i;
				break;
			}
		cnt++;
	}
	for(i=1;i<=n;i++){
		if(fa[i]==i){
			if(a[i]!=root)
			a[i]=root;
			++cnt;
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
 return 0;
}

