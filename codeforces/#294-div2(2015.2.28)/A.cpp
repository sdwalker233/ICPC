#include<stdio.h>

int main()
{
	char s;
	int i,v1=0,v2=0;
	for(i=1;i<=72;i++){
		scanf("%c",&s);
		switch(s){
			case('Q'):v1+=9;break;
			case('R'):v1+=5;break;
			case('B'):v1+=3;break;
			case('N'):v1+=3;break;
			case('P'):v1+=1;break;
			case('q'):v2+=9;break;
			case('r'):v2+=5;break;
			case('b'):v2+=3;break;
			case('n'):v2+=3;break;
			case('p'):v2+=1;break;
		}
	}
	if(v1>v2) printf("White");
	if(v1==v2) printf("Draw");
	if(v1<v2) printf("Black");
 return 0;
}

