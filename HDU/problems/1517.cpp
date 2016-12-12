#include <bits/stdc++.h>
using namespace std;
double n;

void fuck()
{
	while(n>18) n/=18;
	if(n<=9) printf("Stan wins.\n");
	else printf("Ollie wins.\n");
}

int main()
{
	while(~scanf("%lf",&n)) fuck();
 return 0;
}

