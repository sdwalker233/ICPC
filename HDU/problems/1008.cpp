#include<stdio.h>
int n;

 void run()
 {
 	int i,ans=0,now=0,next;
 	for(i=1;i<=n;i++){
 		scanf("%d",&next);
 		if(next>now) ans+=(next-now)*6+5;
 		else ans+=(now-next)*4+5;
 		now=next;
 	}
 	printf("%d\n",ans);
 }

int main()
{
	while(1){
		scanf("%d",&n);
		if(n==0) return 0;
		run();
	}
 return 0;
}

