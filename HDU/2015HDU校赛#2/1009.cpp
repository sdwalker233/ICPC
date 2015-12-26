#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[10];

bool fuck()
{
	int h1,a1,d1,h2,a2,d2,dam1,dam2,t1,t2;
	bool turn;
	scanf("%d%d%d%d%d%d",&h1,&a1,&d1,&h2,&a2,&d2);
	dam1=max(0,a1-d2);
	dam2=max(0,a2-d1);
	if(dam1==0) return 0;
	if(dam2==0) return 1;
	t2=h1/dam2+(h1%dam2>0);
	t1=h2/dam1+(h2%dam1>0);
	if(ch[0]=='W'){
		if(t1<=t2+1) return 1;
		else return 0;
	}
	else{
		if(t2<=t1+1) return 0;
		else return 1;
	}
}

int main()
{
	while(~scanf("%s",ch))
		if(fuck()) printf("Warrior wins\n");
		else printf("Warrior loses\n");
 return 0;
}


