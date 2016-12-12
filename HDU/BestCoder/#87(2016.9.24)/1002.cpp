#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,d1,d2;
char s1[1010],s2[1010];
int a[1010];

bool check(int x)
{
	if(x<d1||x>2*(d1+d2)) return 0;
	return 1;
}

bool fuck()
{
	int i,j,cnt=0,dd;
	d1=d2=0;
	memset(a,0,sizeof(a));
	scanf("%d%d%s",&n,&m,s1+1);
	for(i=1;i<=n/2;i++){
		if(s1[i]==s1[i+n/2]) d2++;
		else d1++;
	}
	if(check(m)==0) return 0;
	for(i=1;i<=n/2;i++){
		if(s1[i]==s1[i+n/2]) d2--;
		else d1--;
		if(d1==0&&s1[i]!=s1[i+n/2]){
			if(m%2==1){
				s2[i]=s2[i+n/2]=min(s1[i],s1[i+n/2]);
				m--;
				continue;
			}
		}
		for(j='a';j<='z';j++){
			dd=(s1[i]!=j)+(s1[i+n/2]!=j);
			if(check(m-dd)) break;
		}
		if(j>'z') return 0;
		s2[i]=s2[i+n/2]=j;
		m-=dd;
	}
	s2[n+1]=0;
	puts(s2+1);
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		if(fuck()==0) printf("Impossible\n");
	}
 return 0;
}

