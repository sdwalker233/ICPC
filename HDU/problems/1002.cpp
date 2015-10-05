#include<stdio.h>
#include<string.h>
int n;

 void run(int x)
 {
 	int a[1002]={0},b[1002]={0},c[1001]={0},i,l1,l2,l3;
 	char s1[1001],s2[1001];
 	scanf("%s%s",s1,s2);
 	l1=strlen(s1);
 	l2=strlen(s2);
 	for(i=0;i<l1;i++)
 		a[l1-i]=s1[i]-'0';
 	for(i=0;i<l2;i++)
 		b[l2-i]=s2[i]-'0';
 	l3=l1>l2?l1:l2;
 	for(i=1;i<=l3;i++){
 		c[i]+=a[i]+b[i];
 		c[i+1]+=c[i]/10;
 		c[i]%=10;
 	}
 	if(c[l3+1]) l3++;
 	printf("Case %d:\n",x);
 	printf("%s",s1);
 	printf(" + ");
 	printf("%s",s2);
 	printf(" = ");
 	for(i=l3;i>=1;i--)
 		printf("%d",c[i]);
 	if(x!=n) printf("\n\n");
 }

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run(i);
 return 0;
}

