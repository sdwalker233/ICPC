#include<stdio.h>
int n;

 void run()
 {
 	char in[10],out[10],stack[10];
 	int top=-1,next1=0,next2=0,next3=0,i;
 	bool ans[20];
 	scanf("%s%s",in,out);
 	while(next1<n&&next2<n){
 		if(top<0||stack[top]!=out[next2]){
		 	stack[++top]=in[next1++];
		 	ans[next3++]=0;
		 }
 		while(top>=0&&stack[top]==out[next2]){
 			top--;
 			next2++;
 			ans[next3++]=1;
 		}
 	}
 	if(next2<n) printf("No.\n");
 	else{
 		printf("Yes.\n");
 		for(i=0;i<next3;i++)
 			if(ans[i]) printf("out\n");
 			else printf("in\n");
 		}
 	printf("FINISH\n");
 }

int main()
{
	while(scanf("%d",&n)!=EOF)
		run();
 return 0;
}

