#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int n,i,x;
	stack<int> st;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%1d",&x);
		if(st.empty()){
			st.push(x);
		}
		else{
			if(x+st.top()==1){
				st.pop();
			}
			else st.push(x);
		}
	}
	printf("%d\n",st.size());
 return 0;
}

