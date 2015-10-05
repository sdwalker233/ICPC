#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
long long f[20]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700};

 void run(long long n)
 {
 	int p=1,i=0,nl,nr;
 	long long sum=0,l=0,r=0;
 	if(n==1){
 		printf("X");
 		return;
 	}
 	while(p<=18&&n-f[p]>0){
 		n-=f[p++];
 	}
 	nl=0;nr=i-1;
 	while(n-f[i]*f[p-i-1]>0){
 		l+=f[i];
 		n-=f[i]*f[p-i-1];
 		i++;
 	}
 	nl=i;nr=p-i-1;
 	while(n-f[nr]>0){
 		n-=f[nr];
 		l++;
 	}
 	for(i=0;i<nr;i++)
 		r+=f[i];
 	r+=n-1;
 	if(l){
 		printf("(");
 		run(l);
 		printf(")");
 	}
 	printf("X");
 	if(r){
 		printf("(");
 		run(r);
 		printf(")");
 	}
 	//printf("%lld %lld %lld\n",l,r,n);
 }
int main()
{
	//freopen("out.txt","w",stdout);
	int i,j;
	long long n;
	//for(n=1;n<=500000000;n++){
	while(~scanf("%lld",&n)&&n){
		//printf("%lld ",n);
		run(n);
		printf("\n");
	}
 return 0;
}

