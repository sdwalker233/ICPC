#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[200010],s2[200010];

bool judge(int l1,int r1,int l2,int r2)
{
	int i,l=r1-l1+1,m1=(l1+r1)>>1,m2=(l2+r2)>>1;
	if(l%2){
		for(i=0;i<l;i++)
			if(s1[l1+i]!=s2[l2+i]) return 0;
		return 1;
	}
	if(judge(l1,m1,l2,m2)&&judge(m1+1,r1,m2+1,r2)) return 1;
	if(judge(m1+1,r1,l2,m2)&&judge(l1,m1,m2+1,r2)) return 1;
	return 0;
}

int main()
{
	scanf("%s%s",s1,s2);
	if(judge(0,strlen(s1)-1,0,strlen(s2)-1)) printf("YES\n");
	else printf("NO\n");
 return 0;
}

