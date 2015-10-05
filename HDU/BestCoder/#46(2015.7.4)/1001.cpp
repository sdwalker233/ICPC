#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int ttt=360*12000;
int de;

void run()
{
	int i,j,k,t,x,y,z;
	for(i=0;i<=11;i++){
		for(j=0;j<=59;j++){
			for(k=0;k<=5;k++){
				t=k+6*j+i*360;
				x=(12000*t)%ttt;
				y=(1000*t)%ttt;
				z=x-y>0?x-y:y-x;
				if(z>=180*12000) z=ttt-z;
				if(z==de) printf("%02d:%02d:%d0\n",i,j,k);
			}
		}
	}
}
int main()
{
	while(~scanf("%d",&de))
		run(); 
 return 0;
}

