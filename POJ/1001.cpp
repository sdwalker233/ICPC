#include<stdio.h>

int m[151],len1;

 void printm(int pos)
 {
 	int i;
 	for(i=len1;i>pos;i--)
 		printf("%d",m[i]);
 	printf(".");
 	if(i<pos) i=pos;
 	for(i;i>=1;i--)
 		printf("%d",m[i]);
 	printf("\n");
 }

 void multiply(int a[],int len2)
 {
 	int i,j,tmp[151]={0},len3=len1+len2-1;
 	for(i=1;i<=len2;i++)              //a[len2]
 		for(j=1;j<=len1;j++){         //m[len1]
 			tmp[i+j-1]+=a[i]*m[j];
 			tmp[i+j]+=tmp[i+j-1]/10;
 			tmp[i+j-1]%=10;
 		}
 	if(tmp[len3+1]!=0) len3++;
	for(i=1;i<=len3;i++)
		m[i]=tmp[i];
	len1=len3;
 }

 void run(char s[],int n)
 {
 	int i,a[151],len2,pos=0,left=0;
 	len1=0;len2=5;
 	while(s[len2]==48) len2--;
 	while(s[left]==48) left++;
 	pos=len2;
 	while(s[pos]!='.') pos--;
 	pos=len2-pos;
 	for(i=len2;i>=left;i--)
 		if(s[i]!='.'){
 			len1++;
 			a[len1]=m[len1]=s[i]-'0';
 		}
 	len2=len1;
 	for(i=len1+1;i<=150;i++)
 	 	m[i]=0;
 	for(i=1;i<n;i++)
 		multiply(a,len2);
 	printm(pos*n);
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int l,n;
	char s[6];
	while(scanf("%s%d",s,&n)!=EOF)
		run(s,n);
 return 0;
}

