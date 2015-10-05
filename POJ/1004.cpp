#include<stdio.h>

int main()
{
	int i;
	float a,aver=0.0;
	for(i=1;i<=12;i++){
 	   scanf("%f",&a);
 	   aver+=a;
    }
    printf("$%.2f",aver/12);
	
 return 0;
}

