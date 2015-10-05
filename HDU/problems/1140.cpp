#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
using namespace std;
struct node{
	double x,y,z;
}a[110],b[110];
const double R=40000/2/acos(-1);
int k,m;

void fuck()
{
	int i,j,ans=0;
	double dis,d;
	bool ok[110]={0};
	for(i=1;i<=k;i++)
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	for(i=1;i<=m;i++)
		scanf("%lf%lf%lf",&b[i].x,&b[i].y,&b[i].z);
	for(i=1;i<=k;i++){
		dis=a[i].x*a[i].x+a[i].y*a[i].y+a[i].z*a[i].z-R*R;
		for(j=1;j<=m;j++){
			if(ok[j]) continue;
			d=(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y)+(a[i].z-b[j].z)*(a[i].z-b[j].z);
			if(d<=dis){
				ans++;
				ok[j]=1;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	while(~scanf("%d%d",&k,&m)&&k&&m)
		fuck();
 return 0;
}


