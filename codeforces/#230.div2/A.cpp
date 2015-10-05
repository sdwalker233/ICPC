#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,l,cnt[10]={0};
    char s[500];
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++){
		switch(s[i]){
			case('n'):cnt[1]++;break;
			case('i'):cnt[2]++;break;
			case('e'):cnt[3]++;break;
			case('t'):cnt[4]++;break;
		}
	}
	cnt[1]=(cnt[1]-1)/2;
	cnt[3]/=3;
	printf("%d\n",min(cnt[1],min(cnt[2],min(cnt[3],cnt[4]))));
 return 0;
}

