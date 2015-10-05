#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,a,sum=0,num0=0,num5=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a==0) num0++;
		else num5++;
	}
	if(num0==0){
		printf("-1");
		return 0;
	}
	if(num5>=9){
		for(i=1;i<=num5/9;i++) printf("555555555");
		for(i=1;i<=num0;i++) printf("0");
	}
	else if(num0){
		printf("0");
	}
	else printf("-1");
	return 0;
}

