#include<stdio.h>
int main()
{
	freopen("out.txt","w",stdout);
	char *Eng1[20]={"zero","one","two","three","four","five","six","seven",
				"eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
				"sixteen","seventeen","eighteen","nineteen"};
	char *Eng2[8]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	int num;
	for(num=1;num<=99;num++){
		
	
	//scanf("%d",&num);
	if(num>=0&&num<=19)
	printf("\"%s\",",Eng1[num]);
	else if(num<100)
	{
	int s,y;
	s=num/10;
	y=num%10;
	printf("\"%s-%s\",",Eng2[s-2],Eng1[y]);
	}
 	else if(num<1000)
 	{
  	int b,s,y;
  	b=num/100;
  	y=num%100;
  	if(y>9)
  	{
   	s=(num%100)/10;
   	y=(num%100)%10;
   	if(y==0)
    	printf("%s hundred and %s\n",Eng1[b],Eng2[s-2]);
   	else
    	printf("%s hundred and %s %s\n",Eng1[b],Eng2[s-2],Eng1[y]);
  	}
  	else
   	printf("%s hundred and %s\n",Eng1[b],Eng1[y]);
 	}
 }
 return 0;
}
