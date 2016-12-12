#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
struct point{
    int x,y;
	int index;
	point(int _x=0,int _y=0,int _index=0){
		x=_x;y=_y;index=_index;
	}
	point operator-(const point &b)const{
		return point(x-b.x,y-b.y);
	}
}p[2010],center;
int n;
double ang[4010],ang1[4010];

void fuck()
{
	int i,j,k,l,r,pos;
	double sum;
	long long cnt1,cnt2=0;
	point one(1,0);
	for(i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].index=i;
	}
	for(i=1;i<=n;i++){
		center=p[i];
		swap(p[i],p[n]);
		for(j=1;j<n;j++){
			point pp=p[j]-center;
			ang1[j]=fabs(atan2(pp.y,pp.x));
			if(pp.y<0) ang1[j]=2*pi-ang1[j];
		}
		sort(ang1+1,ang1+n);
		for(j=1;j<=n-2;j++){
			ang[j]=ang1[j+1]-ang1[j];
		}
		ang[n-1]=2*pi-(ang1[n-1]-ang1[1]);
		for(j=n;j<=2*n-2;j++)
			ang[j]=ang[j-n+1];
		l=1;r=0;sum=0;cnt1=0;
		//for(j=1;j<n;j++) printf(" %.2f",ang[j]);printf("\n");
		for(l=1;l<n;l++){
			while(sum+ang[r+1]<pi/2){
				sum+=ang[r+1];
				r++;
			}
			cnt1+=r-l+1;
			//printf("  %d %d\n",l,r);
			if(ang[l]>pi/2){
				r=l;
				sum=0;
			}
			else sum-=ang[l];
		}
		cnt2+=(n-1)*(n-2)/2-cnt1;
		//printf(" ===%d\n",cnt1);
		swap(p[i],p[n]);
	}
	printf("%lld\n",(long long)n*(n-1)*(n-2)/6-cnt2);
}

int main()
{
//	freopen("4.in","r",stdin);
//	freopen("4.out","w",stdout);
	while(~scanf("%d",&n)) fuck();
 return 0;
}

