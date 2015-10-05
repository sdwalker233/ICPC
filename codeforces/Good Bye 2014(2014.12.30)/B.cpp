#include<stdio.h>
#include<algorithm>
using namespace std;
int fa[301],a[301];
struct node{
	int pos[301];
	int n;
}b[301];

 int find(int x)
 {
 	if(fa[x]==x) return x;
 	return fa[x]=find(fa[x]);
 }

 void fuck(node x)
 {
 	int i,c[301];
 	for(i=1;i<=x.n;i++)
 		c[i-1]=a[x.pos[i]];
 	sort(c,c+x.n);
 	for(i=1;i<=x.n;i++)
 		a[x.pos[i]]=c[i-1];
 }

int main()
{
	int i,j,n,f;
	char x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		fa[i]=i;
	}
	getchar();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			x=getchar();
			if(x=='1'&&find(i)!=find(j))
				fa[i]=j;
		}
		getchar();
	}
	for(i=1;i<=n;i++){
		f=find(i);
		b[f].pos[++b[f].n]=i;
	}
	for(i=1;i<=n;i++)
		if(b[i].n>1) fuck(b[i]);
	for(i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
 return 0;
}

