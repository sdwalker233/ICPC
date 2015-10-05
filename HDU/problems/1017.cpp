#include<stdio.h>
int n,m;

 int run(int n,int m)
 {
 	int a,b,count=0;
 	for(a=1;a<n;a++)
 		for(b=a+1;b<n;b++)
 			if((a*a+b*b+m)%(a*b)==0) count++;
 	return count;
 }

int main()
{
	int r,i,j;
	scanf("%d",&r);
	for(i=1;i<=r;i++){
		j=1;
		while(1){
			scanf("%d%d",&n,&m);
			if(n==0&&m==0) break;
			printf("Case %d: %d\n",j++,run(n,m));
		}
		if(i!=r) printf("\n");
	}
 return 0;
}

