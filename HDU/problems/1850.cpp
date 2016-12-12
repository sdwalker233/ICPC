#include <bits/stdc++.h>
using namespace std;
int a[1000010],n;

void fuck()
{
	int i,j,cnt=0,sum=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum^=a[i];
	}
	if(sum==0){
		printf("0\n");
		return;
	}
	for(i=1;i<=n;i++)
		if((sum^a[i])<a[i]) ++cnt;
	printf("%d\n",cnt);
}

int main()
{
	while(~scanf("%d",&n)&&n) fuck();
 return 0;
}

