#include<stdio.h>
#include<stack>
using namespace std;
stack<char> s;

 void empty_stack()
 {
 	while(!s.empty()){
 		printf("%c",s.top());
 		s.pop();
 	}
 }
 
int main()
{
	int t;
	char ch;
	scanf("%d",&t);
	getchar();
	while(t--){
		while(1){
			ch=getchar();
			if(ch=='\n'){
				empty_stack();
				printf("\n");
				break;
			}
			if(ch==' '){
				empty_stack();
				printf(" ");
			}
			else s.push(ch);
		}
	}
 return 0;
}

