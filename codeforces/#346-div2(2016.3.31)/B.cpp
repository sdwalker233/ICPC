#include<bits/stdc++.h>
using namespace std;
struct node{
	char name[20];
	int s;
	int r;
}a[100010];

bool cmp(const node& x,const node& y)
{
	if(x.r!=y.r) return x.r<y.r;
	if(x.s!=y.s) return x.s>y.s;
	return strcmp(x.name,y.name)<0;
}

int main()
{
    int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s%d%d",a[i].name,&a[i].r,&a[i].s);
	}
	sort(a+1,a+1+n,cmp);
	a[0].r=0;
	int cnt;
	for(i=1;i<=n;i++){
		if(a[i].r!=a[i-1].r){
			if(a[i+2].r!=a[i].r){
				printf("%s %s\n",a[i].name,a[i+1].name);
				continue;
			}
			if(a[i+1].s!=a[i+2].s){
				printf("%s %s\n",a[i].name,a[i+1].name);
				continue;	
			}
			printf("?\n");
		}
	}
 return 0;
}

