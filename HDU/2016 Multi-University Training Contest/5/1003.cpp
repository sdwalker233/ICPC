#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
long long a[1000010];

void fuck()
{
	int i,cnt=0;
	long long sum=0;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=n;i>=1;i--){
		sum+=a[i];
		if(sum>=0){
			sum=0;
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main()
{
	while(~scanf("%d",&n)) fuck();
 return 0;
}

