#include<stdio.h>
#include<string.h>
int main()
{
	char s[201];
	bool ok;
	int n,b,i,j,l,a[201],t[201];
	while(scanf("%d%d",&n,&b)!=EOF){
		memset(a,0,sizeof(a));ok=0;
		for(i=1;i<=n;i++){
			scanf("%s",s);
			l=strlen(s);
			for(j=0;j<l;j++){
				if(s[l-j-1]>='0'&&s[l-j-1]<='9') t[j]=s[l-j-1]-'0';
				else t[j]=s[l-j-1]-'a'+10;
			}
			for(j=0;j<l;j++)
				a[j]=(a[j]+t[j])%b;
		}
		for(i=201;i>0;i--)
			if(ok||a[i]){
				ok=1;
				if(a[i]<10) printf("%d",a[i]);
				else printf("%c",a[i]+'a'-10);
			}
		if(a[0]<10) printf("%d",a[0]);
		else printf("%c",a[0]+'a'-10);
		printf("\n");
	}
    return 0;
}

