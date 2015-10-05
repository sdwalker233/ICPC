#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,i,j,a[110][110],cnt=0;
	bool b[110]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			switch(a[i][j]){
				case(3):b[i]=b[j]=1;break;
				case(1):b[i]=1;break;
				case(2):b[j]=1;break;
			}
		}
	for(i=1;i<=n;i++)
		if(!b[i]) cnt++;
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		if(!b[i]) printf("%d ",i);
 return 0;
}

