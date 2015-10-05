#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

void fuck()
{
	int i=2;
	while(n>1){
		if(n%i==0){
			printf("%d",i);
			n/=i;
			if(n==1) printf("\n");
			else printf("*");
		}
		else i++;
	}
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}