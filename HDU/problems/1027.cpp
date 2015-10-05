#include<stdio.h>
int n,m,a[]={1,1,2,6,24,120,720,5040,40320};

 void run()
 {
 	int i,ans[1001],len=0,left,num;
 	bool used[1001]={0};
 	for(i=1;i<=n-8;i++){
 		ans[++len]=i;
 		used[i]=1;
 	}
 	left=n-len;
 	m--;
 	while(left){
 		num=m/a[left-1]+1;
 		for(i=1;i<=n;i++){
 			if(used[i]==0) num--;
 			if(num==0) break;
 		}
 		ans[++len]=i;
 		used[i]=1;
 		m%=a[left-1];
 		left--;
 		
 	}
 	for(i=1;i<n;i++)
 		printf("%d ",ans[i]);
 	printf("%d\n",ans[n]);
 }

int main()
{
	int i;
	while(scanf("%d%d",&n,&m)!=EOF)
		run();
 return 0;
}

