#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node{
	double x,y;
}a[100000];
int n,b[100000];
 
 bool cmpx(node a,node b)
 {
 	return a.x<b.x;
 }
 
 bool cmpy(int aa,int bb)
 {
 	return a[aa].y<a[bb].y;
 }
 
 double min(double a,double b)
 {
 	return a<b?a:b;
 }
 
 double cal(node a,node b)
 {
 	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 }

 double dis(int left,int right)
 {
 	int i,j,mid=(left+right)/2,count=0;
 	double m;
 	//printf("%d %d\n",left,right);
 	//if(left==right) return 1e20;
 	if(left+1==right) return cal(a[left],a[right]);
 	if(left+2==right)
 		return min(cal(a[left],a[left+1]),min(cal(a[left],a[left+2]),cal(a[left+1],a[left+2])));
 	m=min(dis(left,mid),dis(mid+1,right));
 	for(i=left;i<=mid;i++)
 		if(a[mid+1].x-a[i].x<m)
 			b[count++]=i;
 	for(i=mid+1;i<=right;i++)
 		if(a[i].x-a[mid].x<m)
 			b[count++]=i;
	//printf("%d\n",count);
	sort(b,b+count,cmpy);
 	for(i=0;i<count;i++)
 		for(j=i+1;j<count;j++){
 			if(a[b[j]].y-a[b[i]].y>=m) break;
 			m=min(cal(a[b[i]],a[b[j]]),m);
 		}
 	return m;
 }

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	int i;
	while(1){
		scanf("%d",&n);
		if(n==0) return 0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,cmpx);
		printf("%.2lf\n",dis(0,n-1)/2);
	}
}

