#include<stdio.h>
int a[100000000],cnt;

 int gcd(int x,int y)
 {
 	if(y==0) return x;
 	return gcd(y,x%y);
 }

int main()
{
	int n,i,t=0;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(i=n>>1;i<n;i++){
			if(gcd(n,i)==n-i)
				a[++cnt]=i;
			//printf("%d ",i^n);
		}
		printf("Case #%d:\n%d\n",++t,cnt);
		for(i=1;i<=cnt;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
 return 0;
}

