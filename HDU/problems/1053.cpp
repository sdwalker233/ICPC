#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
struct tree{
	int child1,child2;
}tr[100];
struct node{
	int w;
	int ch;
	node(int w=0,int ch=0):w(w),ch(ch){}
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};
priority_queue<node> q;
int next,w[28];

 node operator + (const node &a,const node &b){
	return node(a.w+b.w,next++);
 }

 int cal(int x,int depth)
 {
 	if(x<=27){
 		if(depth==0) return w[x];
 		return depth*w[x];
 	}
 	return cal(tr[x].child1,depth+1)+cal(tr[x].child2,depth+1);
 }

 int huffman()
 {
 	node t1,t2;
 	while(1){
 		t1=q.top();q.pop();
 		if(q.empty()){
 			return t1.ch;
 			break;
 		}
		t2=q.top();q.pop();
		//printf("%d %d\n",t1.ch,t2.ch);
 		tr[next].child1=t1.ch;
 		tr[next].child2=t2.ch;
 		q.push(t1+t2);
 	}
 }
int main()
{
	int i,count,head,len,ans;
	node t;
	string s;
	while(getline(cin,s)){
		if(s=="END") break;
		len=s.length();
		sort(&s[0],&s[0]+len);
		count=1;
		for(i=1;i<len;i++){
			if(s[i]==s[i-1]) count++;
			else{
				if(s[i-1]!='_') t.ch=s[i-1]-'A'+1;
				else t.ch=27;
				t.w=w[t.ch]=count;
				q.push(t);
				count=1;
			}
		}
		if(s[i-1]!='_') t.ch=s[i-1]-'A'+1;
		else t.ch=27;
		t.w=w[t.ch]=count;
		q.push(t);
		next=28;
		head=huffman();
		ans=cal(head,0);
		printf("%d %d %.1lf\n",len*8,ans,(double)len*8/ans);
	}
 return 0;
}

