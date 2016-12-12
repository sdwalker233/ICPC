#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d",&n);
		if(n&1) printf("Balanced\n");
		else printf("Bad\n");
	}
 return 0;
}

