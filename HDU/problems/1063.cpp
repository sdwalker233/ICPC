#include<stdio.h>
#include<string.h>

int m[501],a[501],len1,len2;

 void printm(int pos)
 {
 	int i;
 	for(i=len1;i>pos;i--)
 		printf("%d",m[i]);
 	if(pos) printf(".");
 	if(i<pos) i=pos;
 	for(i;i>=1;i--)
 		printf("%d",m[i]);
 	printf("\n");
 }

 void multiply(int a[],int len2)
 {
 	int i,j,tmp[501]={0},len3=len1+len2-1;
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

 void run1(char s[],int n)
 {
 	int i,pos=0,left=0;
 	memset(a,0,sizeof(a));
 	memset(m,0,sizeof(m));
 	len1=0;len2=strlen(s)-1;
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
 	for(i=1;i<n;i++)
 		multiply(a,len2);
 	printm(pos*n);
 }

 void run2(char s[],int n)
 {
 	int i;
 	memset(a,0,sizeof(a));
 	memset(m,0,sizeof(m));
 	for(i=1;i<=strlen(s);i++)
		a[i]=m[i]=s[strlen(s)-i]-'0';
	len1=len2=strlen(s);
	for(i=1;i<n;i++)
 		multiply(a,len2);
 	i=len1;
 	while(m[i]==0) i--;
 	for(i;i>=1;i--)
 		printf("%d",m[i]);
 	printf("\n");
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,n;
	bool t;
	char s[6];
	while(scanf("%s%d",s,&n)!=EOF){
		if(n==0){
			printf("1\n");
			getchar();
			continue;
		}
		t=0;
		for(i=0;i<strlen(s);i++)
			if(s[i]=='.') t=1;
		if(t) run1(s,n);
		else run2(s,n);
		getchar();
	}
		
 return 0;
}

