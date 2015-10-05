#include<iostream>
#include<cstdio>
int n,w,h;
long long a[200000],a1[200000],a2[200000];

 long long min(long long x,long long y)
 {
 	return x<y?x:y;
 }

 void run()
 {
 	int i,p;
	long long sum=0,ans=0x7ffffffffff,t,t1,t2;
	a1[0]=a2[0]=0;
	for(i=1;i<=w;i++){
		a1[i]=h+a1[i-1];
		a2[i]=0;
	}
 	for(i=w+1;i<=w+n;i++){
 		scanf("%d",&p);
 		sum+=p;
 		if(h>p){
 			a1[i]=h-p+a1[i-1];
 			a2[i]=a2[i-1];
 		}
 		else{
 			a1[i]=a1[i-1];
 			a2[i]=p-h+a2[i-1];
 		}
 	}
 	for(i=w+n+1;i<=2*w+n;i++){
 		a1[i]=a1[i-1]+h;
 		a2[i]=a2[i-1];
 	}
 	if(sum<(long long)w*h){
 		printf("-1\n");
 		return;
 	}
 	for(i=1;i<=w+n;i++){
 		t1=a1[i+w-1]-a1[i-1];
 		t2=a2[i+w-1]-a2[i-1];
 		t=t1-t2;
 		if(t>0) t=t+t2;
 		else t=-t+t1;
 		if(t<ans) ans=t;
 		//ans=min(ans,t);
 	}
 	printf("%I64d\n",ans);
 }

int main()
{
	freopen("in.txt","r",stdin);
	while(~scanf("%d%d%d",&n,&w,&h))
		run();
 return 0;
}
