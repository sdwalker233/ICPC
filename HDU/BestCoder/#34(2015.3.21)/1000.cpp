#include<iostream>
#include<cstdio>
int n,m;

 int min(int x,int y)
 {
 	return x<y?x:y;
 }

 void run()
 {
 	int i,j,a,w,v,ans=0x7fffffff;
 	for(i=1;i<=m;i++){
 		scanf("%d%d",&v,&w);
 		if(n%v==0) a=n/v;
 		else a=n/v+1;
 		ans=min(ans,w*a);
 	}
 	printf("%d\n",ans);
 }
int main()
{
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}

