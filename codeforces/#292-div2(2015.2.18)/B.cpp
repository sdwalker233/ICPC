#include<stdio.h>
bool a[101]={0},b[101]={0};

 int gcd(int x,int y)
 {
 	if(y==0) return x;
 	return gcd(y,x%y);
 }

int main()
{
	int i,j,n,m,f,g,x;
	bool end;
	scanf("%d%d%d",&n,&m,&f);
	for(i=1;i<=f;i++){
		scanf("%d",&x);
		a[x]=1;
	}
	scanf("%d",&g);
	for(i=1;i<=g;i++){
		scanf("%d",&x);
		b[x]=1;
	}
	x=n*m/gcd(n,m);
	do{
		end=0;
		for(i=0;i<x;i++)
			if(a[i%n]^b[i%m]){
				a[i%n]=b[i%m]=1;
				end=1;
			}
	}while(end);
	for(i=0;i<n;i++)
		if(!a[i]){
			printf("No\n");
			return 0;
		}
	for(i=0;i<m;i++)
		if(!b[i]){
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
 return 0;
}

