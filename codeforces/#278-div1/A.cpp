#include <bits/stdc++.h>
using namespace std;
int h,a,d;
int h1,a1,d1;
int h2,a2,d2;

int cal(int a1,int d1)
{
	if(a1<=d2) return -1;
	if(a2<=d1) return h1;
	int n2=h2/(a1-d2)+(h2%(a1-d2)!=0);
	return max(h1,(a2-d1)*n2+1 );
}

int main()
{
	cin>>h1>>a1>>d1;
	cin>>h2>>a2>>d2;
	cin>>h>>a>>d;
	int hh,aa,dd;
	int mn=0x7fffffff;
	for(aa=0;aa<=1000;aa++)
		for(dd=0;dd<=1000;dd++){
			int tmp=cal(a1+aa,d1+dd);
			if(tmp<h1) continue;
			mn=min(mn,(tmp-h1)*h+aa*a+dd*d);
		}
	printf("%d\n",mn);
 return 0;
}

