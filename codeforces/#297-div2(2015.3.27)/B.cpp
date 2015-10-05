#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int m,i,a,l;
	bool b[100010]={0},ok=0;
	char s[200010],ch;
	scanf("%s%d",s+1,&m);
	l=strlen(s+1);
	for(i=1;i<=m;i++){
		scanf("%d",&a);
		b[a]=(b[a]?0:1);
	}
	for(i=1;i<=(l>>1);i++){
		if(b[i]) ok=(ok?0:1);
		//if(ok) swap(s[i],s[l-i+1]);
		if(ok){
			ch=s[i];
			s[i]=s[l-i+1];
			s[l-i+1]=ch;
		}
	}
	printf("%s\n",s+1);
 return 0;
}

