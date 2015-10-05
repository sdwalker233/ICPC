#include<stdio.h>

int main()
{
	int n,t,i,a;
	bool b[30001]={0};
	scanf("%d%d",&n,&t);
	b[1]=1;
	for(i=1;i<=n-1;i++){
		scanf("%d",&a);
		if(b[i]) b[i+a]=1;
	}
	if(b[t]) printf("YES\n");
	else printf("NO\n");
 return 0;
}

