#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k,r,i,sum=0;
	scanf("%d%d",&k,&r);
	for(i=1;i<=10;i++){
		if(k*i%10==r||k*i%10==0) break;
	}
	cout<<i<<endl;
 return 0;
}

