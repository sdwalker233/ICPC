#include<stdio.h>
int ans[2000001];
int main()
{
	int n,x,y,a,b,i,m;
	scanf("%d%d%d",&n,&x,&y);
	a=y;b=x;
	for(i=1;i<=x+y;i++)
		if(a==b){
			ans[i]=0;
			ans[i+1]=0;
			i++;
			a+=y;b+=x;
		}
		else if(a<b){
			ans[i]=1;
			a+=y;
		}
		else{
			ans[i]=2;
			b+=x;
		}
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		switch(ans[(m-1)%(x+y)+1]){
			case(1):printf("Vanya\n");break;
			case(2):printf("Vova\n");break;
			case(0):printf("Both\n");break;
		}
	}
 return 0;
}

