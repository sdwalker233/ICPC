#include<stdio.h>
int n;

 void run(int x)
 {
 	int i,m,a[100001],b=0,tmp=1,start=1,end,ans=-1001;
 	scanf("%d",&m);
 	for(i=1;i<=m;i++)
 		scanf("%d",&a[i]);
 	for(i=1;i<=m;i++){
 		if(b>=0) b+=a[i];
 		else{
 			b=a[i];
 			tmp=i;
 		}
 		if(b>ans){
 			ans=b;
 			start=tmp;
 			end=i;
 		}
 	}
 	printf("%d %d %d\n",ans,start,end);
	if(x!=n) printf("\n");
 }

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Case %d:\n",i);
		run(i);
	}
 return 0;
}

