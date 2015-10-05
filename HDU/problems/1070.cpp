#include<stdio.h>
#include<string.h>

struct node{
	char name[101];
	int p,v,d;
};
int main()
{
	int i,n,t,d;
	node temp,min;
	scanf("%d",&t);
	while(t--){
		min.d=0;min.p=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%s%d%d",temp.name,&temp.p,&temp.v);
			if(temp.v<200) continue;
			temp.d=temp.v/200;
			if(temp.d>5) temp.d=5;
			if(temp.p*min.d==min.p*temp.d&&temp.v>min.v) min=temp;
			if(temp.p*min.d<min.p*temp.d) min=temp;
			}
		printf("%s\n",min.name);
	}
 return 0;
}

