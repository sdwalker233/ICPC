#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2000010];

int fuck()
{
	int l,i,cnt=0,last=-10,first=1;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++) if(s[i]!='c'&&s[i]!='f') return -1;
	while(first<=l&&s[first]=='f') first++;
	if(first>l){
		return (l+1)/2;
	}
	for(i=1;i<first;i++){
		s[l+i]=s[i];
	}
	l+=first-1;
	for(i=first;i<=l;i++){
		if(s[i]=='c'){
			cnt++;
			if(i-last<3) return -1;
			last=i;
		}
	}
	if(s[l]=='c'||s[l-1]=='c') return -1;
	return cnt;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: %d\n",i,fuck());
	}
 return 0;
}


