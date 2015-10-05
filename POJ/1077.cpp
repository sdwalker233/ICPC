#include<stdio.h>
int a[10],heaplen=0;
struct heap{
	int a[10];
	int f;
	int x;//hash
	int pos;//0
	int front;
	char move;
}heap[100000];


 void astar(){
 	int i;
 	struct heap p,now,next;
 	heap_Insert(a);
 	while(){
		now=heap_min();
 		if(now.pos-3>0){
 			next=now;
 			swap(next.a[pos],next.a[pos-3]);
 			next.pos-=3;
 		if(now.pos-1>0) 
 		if(now.pos+1<10) 
 		if(now.pos+3>10) 
 		
 }

 void init(){
 	int i=1;
 	char s;
 	while(i<=9){
 		s=getchar();
 		if(s==' ') continue;
 		if(s<='8'&&s>='1') a[i]=s-48;
 		else a[i]=0;
 		i++;
	}
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i;
    init();
    astar();
 return 0;
}

