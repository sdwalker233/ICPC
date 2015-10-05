#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,k,n,a[10010],t,sum;
	bool b[100010],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		t=0;ok=1;sum=0;
		memset(b,0,sizeof(b));
		for(j=1;j<=i;j++)
			if(i%j==0){
				a[++t]=j;
				sum+=j;
			}
		b[0]=1;
		sum=i;
		//printf("\n");
		for(j=1;j<=t;j++)
			for(k=sum;k>=a[j];k--)
				if(b[k-a[j]]) b[k]=1;
		for(j=1;j<=sum;j++)
			if(b[j]==0) ok=0;
		if(ok==1) printf("%d\n",i);
		else if(i%2==0){
			printf(" %d  ",i);
			//for(j=1;j<=t;j++) printf("%d ",a[j]);
			printf("\n");
		}
		//if(ok) 
	}
 return 0;
}

