#include<stdio.h>
 
 int f(int x)
 {
 	if(x>=0) return x;
 	else return x+10;
 }

int main()
{
	int i,j,n,a[10001],ans=0;
	char s,s1;
	scanf("%d",&n);
	getchar();
	s1=getchar();a[0]=0;
	for(i=1;i<n;i++){
		s=getchar();
		a[i]=s-s1;
	}
	for(i=1;i<n;i++){
		j=0;
		while(j<n){
			if(f(a[(i+j)%n]-a[i])>f(a[(ans+j)%n]-a[ans])) break;
			if(f(a[(i+j)%n]-a[i])<f(a[(ans+j)%n]-a[ans])){
				ans=i;
				break;
			}
			j++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d",f(a[(ans+i)%n]-a[ans]));
 return 0;
}

