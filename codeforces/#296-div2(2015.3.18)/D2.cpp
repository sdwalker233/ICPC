#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int x,w,a,b;
}p[200011];

 bool cmp(node x,node y)
 {
 	return x.a<y.a;
 }

int main()
{
	int n,i,c,m=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].w);
		p[i].a=p[i].x+p[i].w;
		p[i].b=p[i].x-p[i].w;
	}
	c=-0x80000000;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++){
		if(p[i].b>=c){
			c=p[i].a;
			m++;
		}
	}
	printf("%d\n",m);
 return 0;
}

