#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int a,v1,v2;
	double t1,t2;
	while(~scanf("%d%d%d",&a,&v1,&v2)){
		if(a==0){
			printf("0\n");
			continue;
		}
		if(v1<=v2){
			printf("Infinity\n");
			continue;
		}
		t1=(double)a/(v1+v2);
		t2=v2*t1/(v1-v2);
		printf("%.10f\n",t1+t2);
	}
 return 0;
}

