#include<iostream>
#include<cstdio>
using namespace std;
int n,m;

 bool judge(int a,int b,int c)
 {
 	if(a+b>c&&a+c>b&&b+c>a) return 1;
 	return 0;
 }

 void run()
 {
 	int i,x,l=0x7ffffff,r=0,count=0;
 	for(i=1;i<=m;i++){
 		scanf("%d",&x);
 		l=min(l,x);
 		r=max(r,x);
 	}
 	l--;
 	r=n-r;
 	//printf(" %d %d\n",l,r);
 	if(l==0&&r==0){
 		printf("0\n");
 		return;
 	}
 	if(l==0||r==0){
 		if(r) l=r;
 		if(l%2) l=(l-1)/2;
 		else l=-(l-1)/2;
 		printf("%I64d\n",(long long)l*(l+1)/2);
 		//if(l%2) printf("%d\n",(int)((double)(l+3)*(l+3)/48+0.5));
 		//else printf("%d\n",(int)((double)l*l/48+0.5));
 		return;
 	}
 	for(i=1;i<l;i++)
 		if(judge(i,l-i,r)) count++;
 	for(i=1;i<r;i++)
 		if(judge(i,r-i,l)) count++;
 	printf("%d\n",count);
 }

int main()
{
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}

