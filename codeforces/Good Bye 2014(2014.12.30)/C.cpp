#include<stdio.h>

int main()
{
	int n,m,i,j,w[501],ord[1001],stack[501],top=-1,last,tmp,sum=0;
	bool instack[501]={0};
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=m;i++){
		scanf("%d",&ord[i]);
		if(instack[ord[i]]==0){
			stack[++top]=ord[i];
			instack[ord[i]]=1;
		}
	}
	for(i=1;i<=m;i++){
		last=stack[0];
		for(j=1;;j++)
			if(last!=ord[i]){
				sum+=w[last];
				tmp=last;
				last=stack[j];
				stack[j]=tmp;
			}
			else{
				stack[0]=last;
				break;
			}
	}
	printf("%d\n",sum);	
 return 0;
}

