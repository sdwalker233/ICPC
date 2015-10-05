#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	double t;
	int num;
}a[100000];
int n,m,k;

 bool cmp1(node x,node y)
 {
 	return x.t>y.t;
 }
 
 bool cmp2(node x,node y)
 {
 	return x.num>y.num;
 }

 void run()
 {
 	int i,j,ans[100000];
 	double max,x;
 	for(i=0;i<m;i++){
 		a[i].t=0;
 		a[i].num=i+1;
 	}
 	for(i=1;i<=n;i++)
 		for(j=0;j<m;j++){
 			scanf("%lf",&x);
 			a[j].t+=x;
 		}
 	sort(a,a+m,cmp1);
 	sort(a,a+k,cmp2);
 	for(i=0;i<k-1;i++)
 		printf("%d ",a[i].num);
 	printf("%d\n",a[k-1].num);
 }

int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
		run();
 return 0;
}

