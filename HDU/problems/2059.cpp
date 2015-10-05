#include<stdio.h>
#define min(a,b) (a)<(b)?a:b
int l,n,c,t,vr,vt1,vt2,p[101];

 double f(int d)
 {
 	if(d<=c) return (double)d/vt1+t;
 	else return (double)c/vt1+(double)(d-c)/vt2+t;
 }

int main()
{
	int i,j;
	double ans[102];
	while(scanf("%d%d%d%d%d%d%d",&l,&n,&c,&t,&vr,&vt1,&vt2)!=EOF){
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
		p[n+1]=l;
		for(i=1;i<=n+1;i++){
			ans[i]=f(p[i])-t;
			for(j=1;j<i;j++)
				ans[i]=min(ans[i],ans[j]+f(p[i]-p[j]));
		}
		if(ans[n+1]>(double)l/vr) printf("Good job,rabbit!\n");
		else printf("What a pity rabbit!\n");
	}
 return 0;
}
