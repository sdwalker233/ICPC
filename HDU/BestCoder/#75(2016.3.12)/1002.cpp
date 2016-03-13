#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int xx[]={1,1,1,2,3,3,4,7};
int yy[]={3,7,9,8,7,9,6,9};
int zz[]={2,4,5,5,5,6,5,8};

bool fuck()
{
	int i,j,k,x,y;
	int a[12],b[12]={0};
	bool f=1;
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		scanf("%d",&a[i]);
		if(a[i]<1||a[i]>9) f=0;
		else{
			if(b[a[i]]) f=0;
			b[a[i]]=1;
		}
	}
	if(f==0) return 0;
	memset(b,0,sizeof(b));
	if(k<4) return 0;
	for(i=1;i<=k-1;i++){
		x=a[i];y=a[i+1];
		if(x>y) swap(x,y);
		for(j=0;j<8;j++)
			if(x==xx[j]&&y==yy[j]&&b[zz[j]]==0) return 0;
		b[a[i]]=1;
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(fuck()) printf("valid\n");
		else printf("invalid\n");
 return 0;
}