#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100010];

bool fuck()
{
	int i,last=0;
	bool del=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	del=0;last=0;a[0]=0;
	for(i=1;i<=n;i++){
		if(a[i]>=last){
			last=a[i];
			continue;
		}
		if(!del&&a[i]>=a[i-2]) del=1;
		else if(!del&&a[i]<a[i-2]){
			del=1;
			continue;
		}
		else break;
		last=a[i];
	}
	if(i>n) return 1;
	del=0;last=100010;a[0]=100010;
	for(i=1;i<=n;i++){
		if(a[i]<=last){
			last=a[i];
			continue;
		}
		if(!del&&a[i]<=a[i-2]) del=1;
		else if(!del&&a[i]>a[i-2]){
			del=1;
			continue;
		}
		else break;
		last=a[i];
	}
	if(i>n) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(fuck()) printf("YES\n");
		else printf("NO\n");
 return 0;
}