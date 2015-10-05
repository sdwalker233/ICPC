#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int num,v,c;
}a[100010];

 bool cmp1(node x,node y)
 {
	 return x.v<y.v;
 }

 bool cmp2(node x,node y)
 {
	 return x.num<y.num;
 }

int main()
{
	int n,h,i,ans1,ans2,s=1,ans;
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp1);
	ans1=a[n].v+a[n-1].v-a[1].v-a[2].v;
	ans2=max(a[n].v+a[n-1].v,a[n].v+a[1].v+h)-min(a[1].v+a[2].v+h,a[2].v+a[3].v);
	if(ans2<ans1){
		a[1].c=2;
		s=2;
	}
	for(i=s;i<=n;i++){
		a[i].c=1;
	}
	sort(a+1,a+n+1,cmp2);
	printf("%d\n",min(ans1,ans2));
	for(i=1;i<=n;i++)
		printf("%d ",a[i].c);
 return 0;
}

