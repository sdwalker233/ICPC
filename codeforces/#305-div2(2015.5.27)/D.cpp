#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 200010
using namespace std;
struct node{
	int p,num;
	bool operator<(node x)const{
		return num>x.num;
	}
}a[MAXN];
int n,fa[MAXN],num[MAXN];
bool use[MAXN]={0};

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unio(int x,int y)
{
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
	num[yy]+=num[xx];
}

int main()
{
	int i,j,c,now=1,maxp=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		a[i].p=i;
		fa[i]=i;
		num[i]=1;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		use[a[i].p]=1;
		if(use[a[i].p-1]) unio(a[i].p-1,a[i].p);
		if(use[a[i].p+1]) unio(a[i].p+1,a[i].p);
		c=find(a[i].p);
		if(num[c]>=now){
			for(j=now;j<=num[c];j++)
			printf("%d ",a[i].num);
			now=num[c]+1;
		}
	}
 return 0;
}

