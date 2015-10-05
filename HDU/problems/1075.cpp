#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string,string> a;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char s1[100],s2[100],ch,last=0;
	int l;
	scanf("%s",s1);
	while(scanf("%s%s",s1,s2)&&strcmp(s1,"END"))
		a.insert(pair<string,string>(s2,s1));
	getchar();
	while(1){
		l=0;
		while(1){
			ch=getchar();
			if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) s1[l++]=ch;
			else break;
		}
		s1[l]=0;
		//printf("%s\n",s1);
		if(last=='\n'&&strcmp(s1,"END")==0) return 0;
		if(a.find(s1)!=a.end()) cout<<a[s1];
		else cout<<s1;
		cout<<ch;
		last=ch;
	}
 return 0;
}

