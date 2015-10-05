#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,h1,h2,a1,a2,x1,x2,y1,y2;

 int gcd(int x,int y)
 {
 	if(!y) return x;
 	return gcd(y,x%y);
 }

int exGcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = exGcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int main()
{
	int i,t1,t2,loop1,loop2,tmp,a,b,c,d,a0,x0,y0;
	bool ok1=0,ok2=0,ok3=0,ok4=0;
	scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
	tmp=h1;
	for(i=1;i<=m;i++){
		tmp=((long long)tmp*x1+y1)%m;
		if(!ok1&&tmp==h1){
			loop1=i;
			ok1=1;
		}
		if(!ok2&&tmp==a1){
			t1=i;
			ok2=1;
		}
		if(ok1&&ok2) break;
	}
	tmp=h2;
	for(i=1;i<=m;i++){
		tmp=((long long)tmp*x2+y2)%m;
		if(!ok3&&tmp==h2){
			loop2=i;
			ok3=1;
		}
		if(!ok4&&tmp==a2){
			t2=i;
			ok4=1;
		}
		if(ok3&&ok4) break;
	}
	if(!(ok1&&ok2&&ok3&&ok4)){
		printf("-1\n");
		return 0;
	}
	a0=loop1;
	if(t2>t1){
		a=loop1;b=-loop2;c=t2-t1;
	}
	else {
		a=-loop1;b=loop2;c=t1-t2;
	}
	d=gcd(a,b);
	if(c%d!=0){
		printf("-1\n");
		return 0;
	}
	exGcd(a,b,x0,y0);
	x0*=c;y0*=c;
	while(x0<0) x0+=a0;
	while(x0>=a0) x0-=a0;
	printf("%d\n",t1+x0*loop1);
	printf("%d %d %d %d\n",t1,x0,loop1,a0);
 return 0;
}

