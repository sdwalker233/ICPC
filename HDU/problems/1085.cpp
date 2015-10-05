#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,num1,num2,num5,max;
	bool ok[100000];
	while(~scanf("%d%d%d",&num1,&num2,&num5)){
		if(!num1&&!num2&&!num5) break;
		memset(ok,0,sizeof(ok));
		max=num1+num2*2+num5*5;
		for(i=0;i<=num1;i++) ok[i]=1;
		for(i=0;i<=num1;i++)
			for(j=0;j<=num2;j++)
				ok[i+j*2]=1;
		for(i=0;i<=num1+num2*2;i++)
			if(ok[i])
				for(j=0;j<=num5;j++)
					ok[i+j*5]=1;
		for(i=1;i<=max;i++)
			if(!ok[i]) break;
		printf("%d\n",i);
	}
 return 0;
}

