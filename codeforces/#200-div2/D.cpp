#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

char s[100010];

int main()
{
	stack<char> st;
	gets(s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(st.empty()||st.top()!=s[i]) st.push(s[i]);
		else st.pop();
	}
	if(st.empty()) printf("Yes\n");
	else printf("No\n");
}