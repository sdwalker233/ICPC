#include<stdio.h>

int main()
{
	int n,i,j,max,ans,t,a[101];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<n;i++){
		max=0;
		for(j=1;j<=n-1;j++){
			if(j==i-1){
				t=a[j+2]-a[j];
				j++;
			}
			else t=a[j+1]-a[j];
			if(t>max) max=t;
		}
		if(max<ans) ans=max;
	}
	printf("%d\n",ans);		
 return 0;
}

