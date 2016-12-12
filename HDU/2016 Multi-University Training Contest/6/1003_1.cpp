#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,a,b,c,v1,v2,v3,x[3][10000]={0};
	x[0][0]=1;x[1][1]=1;x[2][2]=1;
	for(i=1;i<=100;i++){
		for(a=1;a<=i;a++)
			for(b=a;a+b<i&&i-a-b>=b;b++){
				c=i-a-b;
				//if((a^b^c)<3) x[a^b^c][i]=1;
				for(v1=0;v1<3;v1++)
					for(v2=0;v2<3;v2++)
						for(v3=0;v3<3;v3++)
							if(x[v1][a]&&x[v2][b]&&x[v3][c])
								x[v1^v1^v3][i]=1;
			}
	}
	for(i=1;i<=100;i++)
		printf("%2d %d %d %d\n",i,x[0][i],x[1][i],x[2][i]);
 return 0;
}

