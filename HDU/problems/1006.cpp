#include<stdio.h>
#include<math.h>
int ans[3686401]={0};
 int figure(int x,int y)
 {
 	int t=abs(x-y);
 	if(t>5529600) return 11059200-t;
 	else return t;
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,n;
	int d1=0,d2=0,d3=0,p,min;
	for(i=1;i<=11059200;i++){
		d1+=720;d1%=11059200;
		d2+=12;d2%=11059200;
		d3+=1;
		//printf("%d %d %d\n",d1,d2,d3);
		min=figure(d1,d2);
		p=figure(d2,d3);if(min>p) min=p;
		p=figure(d1,d3);if(min>p) min=p;
		//printf("%d\n",i);
		for(j=0;j<=min;j++)
			ans[j]++;
		}
	/*while(1){
		scanf("%d",&n);
		if(n==-1) return 0;
		if(n>=120) printf("0.000\n");
		else printf("%.3f\n",float(ans[n])/110592);
	}*/
	for(i=0;i<=3686400;i++)
		printf("ans[%d]=%.3f\n",i,float(ans[i])/110592);
 return 0;
}
