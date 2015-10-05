#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
	int x,y;
	node(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
}mat[100];

int main()
{
	int i,n,x,y,l,in=1;
	long long ans;
	node tmp1,tmp2;
	char ch[5],s[100000];
	stack<node> st;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s%d%d",ch,&x,&y);
		mat[ch[0]].x=x;
		mat[ch[0]].y=y;
	}
	while(~scanf("%s",s)){
		while(!st.empty()) st.pop();
		l=strlen(s);
		ans=0;
		for(i=0;i<l;i++){
			if(s[i]=='(') continue;
			else if(s[i]==')'){
				tmp2=st.top();st.pop();
				tmp1=st.top();st.pop();
				if(tmp1.y!=tmp2.x) break;
				st.push(node(tmp1.x,tmp2.y));
				ans+=tmp1.x*tmp1.y*tmp2.y;
			}
			else{
				st.push(mat[s[i]]);
			}
		}
		if(i<l) printf("error\n");
		else printf("%d\n",ans);
	}
 return 0;
}

