#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c;
}c[10000];
int n;

 bool cmp(node x,node y){
 	if(x.a!=y.a) return x.a>y.a;
 	if(x.b!=y.b) return x.b<y.b;
 	return x.c<y.c;
 }

int main()
{
	int i,a,b;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			c[i].a=a-b;
			c[i].b=b;
			c[i].c=i;
		}
		sort(c,c+n,cmp);
		for(i=0;i<n-1;i++)
			printf("%d ",c[i].c);
		printf("%d\n",c[n-1].c);
	}
 return 0;
}

