#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,num,v[200],count,sum,t=1;
	bool ans[210001],ok;
	while(1){
		count=0;sum=0;ok=0;
		for(i=1;i<=6;i++){
			scanf("%d",&num);
			if(!ok) ok=num>0;
			sum+=num*i;j=1;
			while((j<<1)<=num){
				v[++count]=i*j;
				j<<=1;
			}
			v[++count]=i*(num-j+1);
		}
		//for(i=1;i<=count;i++)
			//printf("%d ",v[i]);
		if(!ok) break;
        printf("Collection #%d:\n",t++);
		if(sum%2){
			printf("Can't be divided.\n\n");
			continue;
		}
		memset(ans,0,sizeof(ans));
        ans[0]=1;
		for(i=1;i<=count;i++)
			if(v[i])
			for(j=sum/2;j>=v[i];j--)
				if(ans[j-v[i]]) ans[j]=ans[j-v[i]];
		if(ans[sum/2]) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
	}
 return 0;
}

