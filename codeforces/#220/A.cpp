#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n,m,x,y,a,b;
	int ans=0x7fffffff,s1,s2;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
	if((x==1||x==n)&&(y==1||y==m)){
		printf("0\n");
		return 0;
	}
	if((x-a<1&&x+a>n)||(y-b<1&&y+b>m)){
		printf("Poor Inna and pony!\n");
		return 0;
	}
	if((x-1)%a==0&&(y-1)%b==0){
		s1=(x-1)/a;s2=(y-1)/b;
		if((s1-s2)%2==0) ans=min(ans,max(s1,s2));
	}
	if((x-1)%a==0&&(m-y)%b==0){
		s1=(x-1)/a;s2=(m-y)/b;
		if((s1-s2)%2==0) ans=min(ans,max(s1,s2));
	}
	if((n-x)%a==0&&(y-1)%b==0){
		s1=(n-x)/a;s2=(y-1)/b;
		if((s1-s2)%2==0) ans=min(ans,max(s1,s2));
	}
	if((n-x)%a==0&&(m-y)%b==0){
		s1=(n-x)/a;s2=(m-y)/b;
		if((s1-s2)%2==0) ans=min(ans,max(s1,s2));
	}
	if(ans==0x7fffffff) printf("Poor Inna and pony!\n");
	else printf("%d\n",ans);
 return 0;
}

