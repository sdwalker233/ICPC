#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,k,n1=0,n0=0,x,i;
	bool ok=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(x%2==1) n1++;
		else n0++;
	}
	if(n==k){
		if(n1%2) ok=0;
		else ok=1;
	}
	else if((n-k)%2)
	{
		if(n1<=(n-k)/2) ok=1;
		else if(k%2==0&&n0<=(n-k)/2) ok=1;
	}
	else {
		if(k%2&&n0<=(n-k)/2) ok=0;
		else ok=1;
	}
	if(ok) printf("Daenerys");
	else printf("Stannis");
 return 0;
}

