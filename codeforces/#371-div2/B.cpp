#include <bits/stdc++.h>
using namespace std;
int n,a[100010];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int k=unique(a+1,a+n+1)-a-1;
	if(k>3) printf("NO\n");
	else if(k==3){
		if(a[1]+a[3]==2*a[2]) printf("YES\n");
		else printf("NO\n");
	}
	else if(k==2){
		printf("YES\n");
	}
	else if(k==1){
		printf("YES\n");
	}
 return 0;
}

