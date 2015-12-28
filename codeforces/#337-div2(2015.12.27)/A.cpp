#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,ans;
	scanf("%d",&n);
	if(n%2){
		printf("0\n");
		return 0;
	}
	printf("%d\n",((n/2)-1)/2);
 return 0;
}