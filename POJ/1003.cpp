#include<stdio.h>

 int f(float a)
 {
 	int i=2;
 	float sum=0.0;
 	while(sum<1){
 		sum+=1/(i*a);
 		//printf("%f ",sum);
 		++i;
 	}
 	return i-2;
 }

int main()
{
	float a;
	for(;;){
		scanf("%f",&a);
		if(a==0.0) break;
		printf("%d card(s)\n",f(a));
	}
 return 0;
}

