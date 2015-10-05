#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	char s[60][60]={0};
	int n,m,i,j,ans=0;
	bool ok1,ok2,ok3,ok4;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			ok1=ok2=ok3=ok4=0;
			if(s[i][j]=='f'||s[i][j+1]=='f'||s[i+1][j]=='f'||s[i+1][j+1]=='f') ok1=1;
			if(s[i][j]=='a'||s[i][j+1]=='a'||s[i+1][j]=='a'||s[i+1][j+1]=='a') ok2=1;
			if(s[i][j]=='c'||s[i][j+1]=='c'||s[i+1][j]=='c'||s[i+1][j+1]=='c') ok3=1;
			if(s[i][j]=='e'||s[i][j+1]=='e'||s[i+1][j]=='e'||s[i+1][j+1]=='e') ok4=1;
			if(ok1&&ok2&&ok3&&ok4) ans++;
		}
	}
	printf("%d\n",ans);
 return 0;
}

