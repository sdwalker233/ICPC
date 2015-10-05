#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int x,y;
	bool ok;
	scanf("%d%d",&x,&y);
	while(1){
		ok=0;
		if(x>=2&&y>=2){
			x-=2;y-=2;
			ok=1;
		}
		else if(x>=1&&y>=12){
			x-=1;y-=12;
			ok=1;
		}
		else if(x>=0&&y>=22){
			y-=22;ok=1;
		}
		if(ok==0){
			printf("Hanako\n");
			break;
		}
		ok=0;
		if(x>=0&&y>=22){
			y-=22;ok=1;
		}
		else if(x>=1&&y>=12){
			x-=1;y-=12;
			ok=1;
		}
		else if(x>=2&&y>=2){
			x-=2;y-=2;
			ok=1;
		}
		if(ok==0){
			printf("Ciel\n");
			break;
		}
	}
 return 0;
}

