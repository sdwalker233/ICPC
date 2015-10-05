#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool ok[1000010]={0};

int main()
{
	int i,p,x;
	for(i=1;i<=1000000;i++){
		p=x=i;
		while(x){
			p+=x%10;
			x/=10;
		}
		if(p>1000000) continue;
		else ok[p]=1;
	}
	for(i=1;i<=1000000;i++)
		if(!ok[i]) printf("%d\n",i);
 return 0;
}


