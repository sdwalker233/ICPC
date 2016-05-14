#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int h,m,s;
	int ang;
}a[10];

bool cmp(const node& x,const node& y)
{
	if(x.ang!=y.ang) return x.ang<y.ang;
	return x.s<y.s;
}

void fuck()
{
	for(int i=1;i<=5;i++){
		scanf("%2d:%2d",&a[i].h,&a[i].m);
		a[i].s=a[i].h*60+a[i].m;
		a[i].ang=11*a[i].s%720;
		if(a[i].ang<0) a[i].ang=-a[i].ang;
		a[i].ang=min(a[i].ang,720-a[i].ang);
	}
	sort(a+1,a+6,cmp);
	printf("%02d:%02d\n",a[3].h,a[3].m);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}

