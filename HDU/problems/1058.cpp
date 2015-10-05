#include<stdio.h>
int main()
{
	int i,j,hnum[6000],t[8]={0},n,p[4]={2,3,5,7};
	hnum[0]=1;
	for(i=1;i<5842;i++){
		hnum[i]=0x7fffffff;
		for(j=0;j<4;j++)
			if(hnum[i]>p[j]*hnum[t[p[j]]])
				hnum[i]=p[j]*hnum[t[p[j]]];
		for(j=0;j<4;j++)
			if(hnum[i]==p[j]*hnum[t[p[j]]]) t[p[j]]++;
	}
	while(scanf("%d",&n)!=EOF&&n){
		printf("The %d",n);
		if((n/10)%10!=1&&n%10>=1&&n%10<=3){
			if(n%10==1) printf("st");
			if(n%10==2) printf("nd");
			if(n%10==3) printf("rd");
		}
		else printf("th");
		printf(" humble number is %d.\n",hnum[n-1]);
	}
 return 0;
}
