#include<stdio.h>

int a[1000001]={0};

int main()
{
	int m,n,count,max,start,end,i;
	long long x;
	a[1]=1;
	for(i=1;i<=1000000;i++){
		x=i;count=0;
		while(1){
			if(x<=1000000&&a[x]){
				count+=a[x];
				break;
			}
			if(x%2){
				x=((3*x)+1)>>1;
				count+=2;
			}
			else{
				x>>=1;
				count++;
			}
		}
		a[i]=count;
	}
	while(scanf("%d%d",&m,&n)!=EOF){
		max=0;
		start=m<n?m:n;
		end=m>n?m:n;
		for(i=start;i<=end;i++)
			if(a[i]>max) max=a[i];
		printf("%d %d %d\n",m,n,max);
	}
 return 0;
}

