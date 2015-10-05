#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;

int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

void fuck()
{
	int i,j,k,l,g1,g2;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			g1=gcd(i,j);
			for(k=1;k<=n;k++)
				for(l=1;l<=n;l++){
					g2=gcd(k,l);
					sum+=g1/gcd(g1,g2)*g2;
				}
			}
	printf("%d\n",sum);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

