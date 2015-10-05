#include<stdio.h>

 void run()
 {
 	char s,last=getchar();
 	int count=1;
 	while(1){
 		s=getchar();
 		if(s==last) count++;
 		else{
 			if(count>1) printf("%d",count);
 			printf("%c",last);
 			count=1;
 			last=s;
 		}
 		if(s=='\n'){
 			printf("\n");
 			break;
 		}
 	}
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
		run();
 return 0;
}

