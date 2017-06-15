#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
const double pi=acos(-1.0);
struct circle{
	int x,y,r,p;
}c[MAXN];
int n;

bool cmp(const circle& x,const circle &y)
{
	return x.r>y.r;
}

bool in(int x,int y)
{
	return hypot(c[x].x-c[y].x,c[x].y-c[y].y)<max(c[x].r,c[y].r);
}

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
		c[i].p=0;
	}
	c[0].x=c[0].y=0;
	c[0].r=10000000;c[0].p=0;
	double S=0;
	sort(c+1,c+n+1,cmp);
	for(i=1;i<=n;i++){
		for(j=i-1;j>=0;j--){
			if(in(i,j)){
				c[i].p=c[j].p+1;
				//printf("%d %d %d %d\n",c[i].x,c[i].y,c[i].r,c[i].p);
				if(c[i].p<3||c[i].p%2==0) S+=pi*c[i].r*c[i].r;
				else S-=pi*c[i].r*c[i].r;
				break;
			}
		}
	}
	printf("%.15lf\n",S);
 return 0;
}

