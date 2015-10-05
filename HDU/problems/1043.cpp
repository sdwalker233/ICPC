#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 362880
#define figuref(a) (a).f=(a).g+(a).h
struct node{
	char s[10];
	int f,g,h,p;
}heap[MAX];
int d[9][9]={{4,3,2,3,2,1,2,1,0},
			 {0,1,2,1,2,3,2,3,4},
			 {1,0,1,2,1,2,3,2,3},
			 {2,1,0,3,2,1,4,3,2},
			 {1,2,3,0,1,2,1,2,3},
			 {2,1,2,1,0,1,2,1,2},
			 {3,2,1,2,1,0,3,2,1},
			 {2,3,4,1,2,3,0,1,2},
			 {3,2,3,2,1,2,1,0,1}};
int heaplen,closef[MAX],dir[MAX],pre[MAX],x[4]={1,-1,3,-3},xx[9]={1,1,2,6,24,120,720,5040,40320};
bool open[MAX],close[MAX];
char s[20];

int inverse(char s[])
 {
 	int i,j,sum=0,num;
 	for(i=0;i<8;i++)
 		for(j=i+1;j<=8;j++)
 			if(s[j]!='0'&&s[j]<s[i]) sum++;
	return sum;
 }

 void heap_insert(node p)
 {
 	int i;
 	for(i=++heaplen;heap[i>>1].f>p.f;i>>=1)
 		heap[i]=heap[i>>1];
 	heap[i]=p;
 }

 int heap_update(node p)
 {
 	int i;
 	for(i=1;i<=heaplen;i++)
 		if(heap[i].p==p.p&&strcmp(heap[i].s,p.s)==0) break;
 	if(heap[i].f<=p.f) return 0;
 	for(;heap[i>>1].f>p.f;i>>=1)
 		heap[i]=heap[i>>1];
 	heap[i]=p;
 	return 1;
 }

 node heap_min()
 {
 	node min=heap[1],last=heap[heaplen--];
 	int i,child;
 	for(i=1;(i<<1)<=heaplen;i=child){
 		child=(i<<1);
 		if(child!=heaplen&&heap[child].f>heap[child+1].f) child++;
 		if(heap[child].f>=last.f) break;
 		heap[i]=heap[child];
 	}
 	heap[i]=last;
 	return min;
 }

 int figureh(node p)
 {
 	int i,sum=0;
 	for(i=0;i<=8;++i)
	 	sum+=d[p.s[i]-'0'][i];
 	//printf("%d\n",sum);
 	return sum;
 }

 int cantor_expansion(node p){
 	int sum=0,i,j,num;
 	bool a[9]={0};
	for(i=0;i<=8;++i){
		num=0;
		for(j=0;j<p.s[i]-'0';j++)
			if(a[j]==0) num++;
		//printf("%d ",num);
		sum+=xx[8-i]*num;
		a[p.s[i]-'0']=1;
	}
	//printf("\n");
	return sum;
 }

 void print(int v)
 {
 	if(dir[v]==-1) return;
 	print(pre[v]);
 	switch(dir[v]){
 		case(0):printf("r");break;
 		case(1):printf("l");break;
 		case(2):printf("d");break;
 		case(3):printf("u");break;
 	}
 }		

 void Astar()
 {
 	int i,v1,v2,j=0;
 	node tmp,now;
 	memset(close,0,sizeof(close));
 	memset(open,0,sizeof(open));
 	heaplen=1;
	for(i=0;i<strlen(s);++i){
		if(s[i]=='x'){
			heap[1].p=j;
			heap[1].s[j++]='0';
		}
		if(s[i]>'0'&&s[i]<='9') heap[1].s[j++]=s[i];
	}
	for(i=0;i<=8;i++)
		if(heap[1].s[i]=='x'){
			heap[1].p=i;
			heap[1].s[i]='0';
		}
	if(inverse(heap[1].s)%2){
		printf("unsolvable\n");
		return;
	}
	heap[1].h=figureh(heap[1]);
	heap[1].g=0;
	figuref(heap[1]);
	dir[cantor_expansion(heap[1])]=-1;
 	while(heaplen){
 		now=heap_min();
 		v1=cantor_expansion(now);
 		open[v1]=0;
 		close[v1]=1;
 		closef[v1]=now.f;
 		//printf("%s**",now.s);print(v1);printf("\n");
 		if(strcmp(now.s,"123456780")==0){
		 	print(v1);
			printf("\n");
			return;
			}
 		tmp.g=now.g+1;
 		for(i=0;i<4;i++){
 			tmp.p=now.p+x[i];
 			if(tmp.p<0||tmp.p>8) continue;
 			if((i==0||i==1)&&tmp.p/3!=now.p/3) continue;
 			strcpy(tmp.s,now.s);
 			tmp.s[now.p]=tmp.s[tmp.p];
 			tmp.s[tmp.p]='0';
 			//printf("%s\n",tmp.s);
 			tmp.h=figureh(tmp);
 			figuref(tmp);
 			v2=cantor_expansion(tmp);
 			if(open[v2]==0&&close[v2]==0){
 				open[v2]=1;
 				dir[v2]=i;
 				heap_insert(tmp);
 				pre[v2]=v1;
 			}
 			else{
 				if(open[v2]&&heap_update(tmp)){
				 	dir[v2]=i;
				 	pre[v2]=v1;
				 }
 				else if(tmp.f<closef[v2]){
 					open[v2]=1;
 					close[v2]=0;
 					dir[v2]=i;
 					pre[v2]=v1;
 					heap_insert(tmp);
 				}	
 			}
 		}
 	}
 }

int main()
{
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(gets(s)!=NULL)
		Astar();
 return 0;
}
