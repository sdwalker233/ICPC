#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int  s[1000010];
int main()
{
	int i,t,n;
	scanf("%d",&t);
	while(t-->0){
		int res=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&s[i]);
			if(s[i]<5) res^=s[i];
		}
		if(res==0) printf("Second player wins.\n");
		else printf("First player wins.\n");
	}
 return 0;
}

