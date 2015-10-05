#include<stdio.h>
#include<String.h>
struct node{
	int next[26];
	int v;
}trie[100001];
int len,max;
char maxs[16];

 void trie_insert(char s[])
 {
 	int i,p=0;
 	for(i=0;i<strlen(s);i++){
 		if(!trie[p].next[s[i]-'a']||trie[p].next[s[i]-'a']>len)
			trie[p].next[s[i]-'a']=++len;
 		p=trie[p].next[s[i]-'a'];
 	}
 	trie[p].v++;
 	if(trie[p].v>max){
 		max=trie[p].v;
 		strcpy(maxs,s);
 	}
 }
 		
 void init(int n)
 {
 	int i;
 	char s[16];
 	len=0;max=0;
 	for(i=1;i<=n;i++){
		scanf("%s",s);
		trie_insert(s);
	}
	printf("%s %d\n",maxs,len);
 }

int main()
{
	int n,i;
	while(1){
		scanf("%d",&n);
		if(n==0) return 0;
		init(n);
	}
}

