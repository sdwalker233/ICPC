#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long l,r;

int cal()
{
	long long i,j,num;
	int cnt=0;
	for(i=0;i<63;i++){
		for(j=0;j<i-1;j++){
			num=( ((1ll<<i)-1)^(1ll<<j) );
			if(num>=l&&num<=r){
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	scanf("%I64d%I64d",&l,&r);
	cout<<cal();
 return 0;
}


