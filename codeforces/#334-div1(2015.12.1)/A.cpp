#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j,l=0,p=0;
	int a[100010],b[100010]={0};
	int f=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(a[j]!=a[i]) break;
		}
		b[++l]=j-i;
		i=j-1;
	}

	for(i=1;i<=l;i++){
		//printf(" %d\n",b[i]);
		if(b[i]>2) f=2;
		if(b[i]>=2) p++;
	}
	if(p>=2) f=2;
	if(f==0&&p==1){
		f=1;
	}
	cout<<l+f<<endl;
	//cout<<l<<" "<<f;
	//scanf("%d",&n);
 return 0;
}
//100101 5
//101010 6