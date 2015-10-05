#include<stdio.h>
#include<string.h>
struct trie{
	int next[3];
	bool end;
	trie(){
		next[0]=next[1]=next[2]=-1;
		end=0;
	}
}t[1000000];
int p=0;
bool find;

 void trie_query(char s[],int pos,int now,bool c){
 	int i;
 	if(find) return;
 	if(pos>=strlen(s)){
 		if(t[now].end&&c) find=1;
 		return;
 	}
 	for(i=0;i<=2;i++){
 		if(t[now].next[i]==-1) continue;
 		if(i==s[pos]-'a') trie_query(s,pos+1,t[now].next[i],c);
 		else if(c==0) trie_query(s,pos+1,t[now].next[i],1);
 	}
 }

 void trie_add(char s[]){
 	int now=0,i,l=strlen(s);
 	for(i=0;i<l;i++){
 		if(t[now].next[s[i]-'a']==-1){
 			t[now].next[s[i]-'a']=++p;
 		}
 		now=t[now].next[s[i]-'a'];
 	}
 	t[now].end=1;
 }

int main()
{
	int m,n,i;
	char s[600001];
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<=n;i++){
		gets(s);
		trie_add(s);
	}
	for(i=1;i<=m;i++){
		gets(s);
		find=0;
		trie_query(s,0,0,0);
		if(find) printf("YES\n");
		else printf("NO\n");
	}
 return 0;
}

