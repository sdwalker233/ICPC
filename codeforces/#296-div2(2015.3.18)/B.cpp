#include<stdio.h>
#include<string.h>

int main()
{
	char s1[200011],s2[200011];
	int i,l,a1[30],a2[30],a3[30][30],ch,x=-1,y=-1,count=0;
	int ok=0;
	memset(a1,-1,sizeof(a1));
	memset(a2,-1,sizeof(a2));
	memset(a3,-1,sizeof(a3));
	scanf("%d%s%s",&l,s1+1,s2+1);
	for(i=1;i<=l;i++)
		if(s1[i]!=s2[i]){
			count++;
			a3[s1[i]-'a'][s2[i]-'a']=i;
			if(ok<=1&&a3[s2[i]-'a'][s1[i]-'a']!=-1){
				ok=2;x=a3[s2[i]-'a'][s1[i]-'a'];y=i;
			}
			ch=s1[i]-'a';
			if(a1[ch]==-1) a1[ch]=i;
			if(!ok&&a2[ch]!=-1){
				ok=1;x=a2[ch];y=a1[ch];
			}
			ch=s2[i]-'a';
			if(a2[ch]==-1) a2[ch]=i;
			if(!ok&&a1[ch]!=-1){
				ok=1;x=a1[ch];y=a2[ch];
			}
		}
	printf("%d\n%d %d\n",count-ok,x,y);
 return 0;
}

