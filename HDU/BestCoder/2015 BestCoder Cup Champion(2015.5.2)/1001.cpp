#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a,b,c,d;

 bool fuck()
 {
 	int i,j;
 	unsigned int left=4294967295,right=0;
 	scanf("%d%u%u%d%d%d%d",&n,&l[1],&r[1],&a,&b,&c,&d);
 	for(i=2;i<=n;i++){
 		l[i]=l[i-1]*a+b;
 		r[i]=r[i-1]*c+d;
 	}
 	for(i=1;i<=n;i++){
 		if(l[i]>r[i]){
 			unsigned int temp=l[i];
 			l[i]=r[i];
 			r[i]=temp;
 		}
 	}
 	for(i=1;i<=n;i++){
 		left=min(left,r[i]);
 		right=max(right,l[i]);
 	}
 	for(i=1;i<=n;i++){
 		if(l[i]>left&&r[i]<right) return 1;
 	}
 	return 0;

 }
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		if(!fuck()) printf("NO\n");
		else printf("YES\n");
 return 0;
}

