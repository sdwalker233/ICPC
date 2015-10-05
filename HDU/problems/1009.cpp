#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int j,f;
	double r;
}a[1000];
int m,n;

 bool cmp(node x,node y)
 {
 	return x.r>y.r;
 }

 void run()
 {
 	int i;
 	double ans=0;
 	for(i=0;i<n;i++){
 		scanf("%d%d",&a[i].j,&a[i].f);
 		a[i].r=(double)a[i].j/a[i].f;
 	}
 	sort(a,a+n,cmp);
 	for(i=0;i<n;i++)
 		if(a[i].f<m){
 			ans+=a[i].j;
 			m-=a[i].f;
 		}
 		else{
 			ans+=(double)a[i].j*m/a[i].f;
 			break;
 		}
 	printf("%.3lf\n",ans);
 }

int main()
{
	while(1){
		scanf("%d%d",&m,&n);
		if(m==-1&&n==-1) return 0;
		run();
	}
 return 0;
}

