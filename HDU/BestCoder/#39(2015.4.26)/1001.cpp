#include<iostream>
#include<cstdio>
using namespace std;
int n;

 void run()
 {
 	int i,x,m=0,k;
	bool c[110]={0};
 	for(i=1;i<=n;i++){
 		scanf("%d",&x);
 		if(!c[x]) c[x]=1;
 		else m++;
 	}
 	scanf("%d",&k);
 	if(m>=k) printf("%d\n",n-m);
 	else printf("%d\n",n-k);
 }

int main()
{
	while(~scanf("%d",&n))
		run();
 return 0;
}

