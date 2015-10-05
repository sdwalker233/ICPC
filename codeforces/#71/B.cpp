#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x;
	int y;
	int f;
}wa[1010],q[1010];
int n,m,t,k,x[1010],y[1010],f[1010];

 int fuck(int a,int b)
 {
 	return (a-1)*m+b;
 }

int main()
{
	int i,j,num[1010]={0},tmp;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(i=1;i<=k;i++){
		scanf("%d%d",&wa[i].x,&wa[i].y);
		wa[i].f=fuck(wa[i].x,wa[i].y);
	}
	for(i=1;i<=t;i++){
		scanf("%d%d",&q[i].x,&q[i].y);
		q[i].f=fuck(q[i].x,q[i].y);
	}
	for(i=1;i<=k;i++){
		for(j=1;j<=t;j++){
			if(wa[i].f<q[j].f) num[j]++;
			if(wa[i].f==q[j].f) num[j]=-0x80000000;
		}
	}
	for(i=1;i<=t;i++){
		tmp=q[i].f-num[i];
		if(num[i]<0){
			printf("Waste\n");
			continue;
		}
		switch(tmp%3){
			case(0):printf("Grapes\n");break;
			case(1):printf("Carrots\n");break;
			case(2):printf("Kiwis\n");break;
		}
	}
 return 0;
}

