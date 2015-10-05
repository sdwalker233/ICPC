#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char s[100010];
	int i,l,cnt;
	long long ans=1;
	scanf("%s",s+1);
	l=strlen(s+1);
	cnt=0;
	for(i=1;i<=l;i++){
		if(s[i]+s[i+1]-96==9) cnt++;
		else{
			if(cnt&&cnt%2==0){
				ans*=cnt/2+1;
			}
			cnt=0;
		}
	}
	printf("%lld",ans);
 return 0;
}

