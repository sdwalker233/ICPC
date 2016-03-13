#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int A,B,C;
int a[100],b[100],c[100];

void fuck()
{
	int i,x,y;
	char ch[10];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%d%d%d",&A,&B,&C);
	for(i=1;i<=A;i++){
		scanf("%s%d",ch,&x);
		a[ch[0]-'A']=x;
	}
	for(i=1;i<=B;i++){
		scanf("%s%d",ch,&x);
		b[ch[0]-'A']=x;
	}
	for(i=1;i<=C;i++){
		scanf("%s%d",ch,&x);
		c[ch[0]-'A']=x;
	}
	for(x=1;x<=100;x++){
		for(y=1;y<=100;y++){
			for(i=0;i<26;i++){
				if(x*a[i]+y*b[i]!=c[i]) break;
			}
			if(i>=26){
				printf("%d %d\n",x,y);
				return;
			}
		}
	}
	printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}