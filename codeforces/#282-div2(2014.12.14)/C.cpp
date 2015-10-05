#include<stdio.h>

int main()
{
	bool ok=0;
	int un=0,min=1000000;
	char s;
	while(1){
		s=getchar();
		if(s=='\n') break;
		if(s=='('){
			if(un<min) min=un;
			un++;
		}
		if(s==')'){
			un--;
			if(un<min) min=un;
		}
		if(s=='#'){
			if(min<=0) printf("-1\n");
			if(ok){
			 	printf("%d\n",min);
				un-=min;
			}
			ok=1;
			min=1000000;
		}
	}
	printf("%d\n",min);
 return 0;
}

