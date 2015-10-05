#include<iostream>
#include<cstdio>
using namespace std;

 long long max(int x,int y)
 {
 	return x>y?x:y;
 }
 
 long long min(int x,int y)
 {
 	return x<y?x:y;
 }

int main()
{
	int n,i;
	long long sum=0,A,d[200010];
	scanf("%d%I64d",&n,&A);
	for(i=1;i<=n;i++){
		scanf("%I64d",&d[i]);
		sum+=d[i];
	}
	for(i=1;i<=n;i++){
		printf("%I64d ",d[i]-(min(d[i],A-n+1)-max(A-(sum-d[i]),1)+1));
	}
 return 0;
}

