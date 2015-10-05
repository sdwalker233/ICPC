#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,a[1010],x[1010],key[1010];
int root,ch[1010][2];

void Insert(int x)
{
	int rt=root;
	if(rt==0){
		root=x;
		return;
	}
	while(ch[rt][a[x]>a[rt]]){
		rt=ch[rt][a[x]>a[rt]];
	}
	ch[rt][a[x]>a[rt]]=x;
}

void Find(int x)
{
	int rt=root;
	while(ch[rt][x>a[rt]]){
		if(x>a[rt]) putchar('W');
		else if(x<a[rt]) putchar('E');
		else break;
		rt=ch[rt][x>a[rt]];
	}
	puts("");
}

void fuck()
{
	int i;
	root=0;
	memset(ch,0,sizeof(ch));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
		Insert(i);
	for(i=1;i<=q;i++){
		Find(x[i]);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


