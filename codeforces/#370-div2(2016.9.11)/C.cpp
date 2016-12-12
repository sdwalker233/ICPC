#include <bits/stdc++.h>
using namespace std;
int a,b,c;

void f()
{
	int arry[3]={a,b,c};
	sort(arry,arry+3);
	a=arry[0];b=arry[1];c=arry[2];
}

int main()
{
	int x,y,ans=0x7fffffff,t,i;
	scanf("%d%d",&x,&y);
	for(i=y;i<x;i++){
		a=b=c=x;t=1;
		a=i;
		while(1){
			f();
			if(c==y) break;
			t++;
			c=max(y,b-a+1);
		}
		ans=min(ans,t);
	}
	printf("%d\n",ans);
 return 0;
}

