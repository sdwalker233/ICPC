#include<stdio.h>

int main()
{
	int y,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&y,&n);
		while(n--){
			while(1){
				if((y%4==0&&y%100!=0)||y%400==0) break;
				y++;
			}
			y++;
		}
		printf("%d\n",y-1);
	}
 return 0;
}

