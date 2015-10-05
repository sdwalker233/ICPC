#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
}p[100001];

 bool cmp(node x,node y)
 {
 	return x.b<y.b;
 }

int main()
{
	int n,r,avg,i,j;
	long long sum=0,ans=0;
	scanf("%d%d%d",&n,&r,&avg);
	for(i=0;i<n;i++){
		scanf("%d%d",&p[i].a,&p[i].b);
		sum+=avg-p[i].a;
		p[i].a=r-p[i].a;
	}
	sort(p,p+n,cmp);
	j=0;
	for(i=1;i<=sum;i++)
		if(p[j].a){
			ans+=p[j].b;
			p[j].a--;
		}
		else {j++;i--;}
	printf("%lld",ans);
 return 0;
}

