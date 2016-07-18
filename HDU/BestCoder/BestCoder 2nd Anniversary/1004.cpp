#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct node{
    long long x,y;
	int f;
}a[MAXN];
long long mn;
int n,b[MAXN],f=0,found=0;
 
 bool cmpx(node a,node b)
 {
     return a.x<b.x;
 }
 
 bool cmpy(int aa,int bb)
 {
     return a[aa].y<a[bb].y;
 }
 
 long long cal(node& a,node& b)
 {
     long long tmp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	 if(f==1&&found==0&&tmp==mn){
		 a.f=1;b.f=2;found=1;
	 }
	 return tmp;
 }

 long long dis(int left,int right)
 {
     int i,j,mid=(left+right)/2,count=0;
     long long m;
     //printf("%d %d\n",left,right);
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

void fuck()
{
	int i;
	f=found=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].f=0;
	}
	sort(a,a+n,cmpx);
	mn=dis(0,n-1);
	f=1;
	dis(0,n-1);
	for(i=0;i<n;i++)
		if(a[i].f==1){
			break;
		}
	for(;i<n-1;i++) swap(a[i],a[i+1]);
	sort(a,a+n-1,cmpx);
	long long t1=dis(0,n-2);
	for(i=0;i<n;i++)
		if(a[i].f==2){
			break;
		}
	for(;i<n-1;i++) swap(a[i],a[i+1]);
	long long t2=dis(0,n-2);
	long long ans=(n-2)*mn+t1+t2;
	//cout<<" "<<t1<<" "<<t2<<endl;
	cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
