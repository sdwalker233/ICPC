#include<stdio.h>

 long long int lcm(long long int a,int b)
 {
 	int ans=a;
 	while(ans%b) ans+=a;
 	return ans;
 }

 void run()
 {
 	int n,i,a;
 	long long int ans;
 	scanf("%d%d",&n,&ans);
 	for(i=1;i<n;i++){
 		scanf("%d",&a);
 		ans=lcm(ans,a);
 	}
 	printf("%d\n",ans);
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}

