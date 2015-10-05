#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
using namespace std;
struct node2{
	int ha,num;
}ans[8][100000];
struct node1{
	int v,num;
}a[10];
struct node{
	int a[8][8],st[8],step,ha;
	node(){
		memset(a,0,sizeof(a));
		memset(st,-1,sizeof(st));
	}
};

int n,ha[8][900000],mul[10],cnt[9]={0};
node qu[900000];

bool check(const node& x)
{
	int i;
	for(i=1;i<=n;i++)
		if(x.st[i]!=0) return 0;
	return 1;
}

void save(const node& x)
{
	int i,p=0;
	for(i=1;i<=n;i++){
		p*=10;
		p+=x.a[i][0];
	}
	++cnt[n];
	ans[n][cnt[n]].ha=p;
	ans[n][cnt[n]].num=x.step;
}

void get_hash(node& x)
{
	int ans=0,i,j;
	x.ha=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=x.st[i];j++)
			x.ha+=(i-1)*mul[x.a[i][j]-1];
	}
}

int BFS()
{
	int i,j,next;
	////int front=0,tail=0;
	queue<node> qu;
	node tmp,now;
	tmp.step=0;
	for(i=1;i<=n;i++){
		tmp.a[i][0]=a[i].v;
		tmp.st[i]=0;
	}
	get_hash(tmp);
	ha[n][tmp.ha]=tmp.step;
	////qu[tail++]=tmp;
	qu.push(tmp);
	////while(front<tail){
	while(!qu.empty()){
		////now=qu[front++];
		now=qu.front();
		qu.pop();
		if(check(now)) save(now);
		//cnt++;
		//printf("%d %d\n",now.ha,now.step);
		//if(check(now)) return now.step;
		for(i=1;i<=n;i++){
			if(now.st[i]==-1) continue;
			for(j=i-1;j<=i+1;j+=2){
				if(j<1||j>n) continue;
				if(now.st[j]==-1||now.a[j][now.st[j]]>now.a[i][now.st[i]]){
					tmp=now;
					tmp.step++;
					tmp.a[j][++tmp.st[j]]=tmp.a[i][tmp.st[i]--];
					get_hash(tmp);
					if(ha[n][tmp.ha]==-1){
						ha[n][tmp.ha]=tmp.step;
						////qu[tail++]=tmp;
						qu.push(tmp);
					}
				}
			}
		}
	}
	return -1;
}

bool cmp1(const node1& x,const node1& y)
{
	return x.v<y.v;
}

bool cmp2(const node1& x,const node1& y)
{
	return x.num<y.num;
}

bool cmp3(const node2& x,const node2& y)
{
	return x.ha<y.ha;
}

void fuck()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mul[i]=mul[i-1]*n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp1);
	for(i=1;i<=n;i++){
		a[i].v=i;
	}
	sort(a+1,a+1+n,cmp2);

	node tmp;
	for(i=1;i<=n;i++){
		tmp.a[i][0]=a[i].v;
		tmp.st[i]=0;
	}
	get_hash(tmp);

	printf("%d\n",ha[n][tmp.ha]);
}

void init()
{
	//int begin=clock();
	int i,j;
	memset(ha,-1,sizeof(ha));
	mul[0]=1;
	for(i=1;i<=7;i++) a[i].v=i;
	for(i=1;i<=4;i++){
		n=i;
		for(j=1;j<=i;j++) mul[j]=mul[j-1]*i;
		BFS();
		/**/
		sort(ans[n]+1,ans[n]+1+cnt[n],cmp3);
		for(j=1;j<=cnt[n];j++){
			printf("%d,%d\n",ans[n][j].ha,ans[n][j].num);
			//printf("%d,",ans[n][j].num);
		}
		printf("\n\n");
		
		printf("%d %d\n",i,cnt[i]);
	}
	//printf("%ld\n",(clock()-begin));
}

int main()
{
	//freopen("out.txt","w",stdout);
	init();
	//return 0;
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

