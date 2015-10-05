#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int x,w,a,b;
}p[200011];

 bool cmp(node x,node y)
 {
 	return x.x<y.x;
 }

 int Bsearch(int c[],int v,int l,int r)
 {
 	int m=(l+r)>>1;
 	if(l==r) return l;
 	if(c[m+1]>v) return Bsearch(c,v,l,m);
 	return Bsearch(c,v,m+1,r);
 }

int main()
{
	int n,i,j,c[200011],m=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].w);
		p[i].a=p[i].x+p[i].w;
		p[i].b=p[i].x-p[i].w;
		c[i]=0x7fffffff;
	}
	c[0]=-0x80000000;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++){
		//printf(" %d %d\n",p[i].x,p[i].w);
		for(j=Bsearch(c,p[i].b,0,m);j>=0;j--)
			if(p[i].b>=c[j]&&p[i].a<c[j+1]){
				c[j+1]=p[i].a;
				if(j==m) m++;
				//printf("%d %d\n",p[i].a,m);
				break;
			}
	}
	printf("%d\n",m);
 return 0;
}

