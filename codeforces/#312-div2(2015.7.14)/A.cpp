#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x,a;
}l[100010],r[100010];

bool cmp(node x,node y)
{
	return x.x<y.x;
}

int main()
{
	int n,i,x,a,ll=0,rr=0,sum1=0,sum2=0,c1,c2,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&a);
		if(x>0){
			rr++;
			r[rr].x=x;
			r[rr].a=a;
		}
		else{
			ll++;
			l[ll].x=-x;
			l[ll].a=a;
		}
	}
	sort(l+1,l+ll+1,cmp);
	sort(r+1,r+rr+1,cmp);
	c1=1;c2=1;d=1;
	for(i=1;i<=n;i++){
		if(d==1){
			if(c1>rr) break;
			sum1+=r[c1++].a;
			d=0;
		}
		else{
			if(c2>ll) break;
			sum1+=l[c2++].a;
			d=1;
		}
	}
	c1=1;c2=1;d=0;
	for(i=1;i<=n;i++){
		if(d==1){
			if(c1>rr) break;
			sum2+=r[c1++].a;
			d=0;
		}
		else{
			if(c2>ll) break;
			sum2+=l[c2++].a;
			d=1;
		}
	}
	printf("%d\n",max(sum1,sum2));
 return 0;
}

