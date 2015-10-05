#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t,y,m,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&y,&m,&d);
		if((m+d)%2==0||(d==30&&(m==9||m==11)))
			printf("YES\n");
		else printf("NO\n");
	}
 return 0;
}

