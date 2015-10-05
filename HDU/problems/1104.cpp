#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int n,m,k,km;
int map[1000010];
struct node{
	int num;
	int step;
	string s;
};

void bfs()
{
	int i;
	queue<node> Q;
	memset(map,0,sizeof(map));
	node p,q;
	p.num=n;
	p.s="";
	p.step=0;
	Q.push(p);
	map[(n%k+k)%k]=1;
	while(!Q.empty())
	{
		q=Q.front();
		Q.pop();
		if(((n+1)%k + k) % k == (q.num%k + k) % k)
		{
			cout<<q.step<<endl;
			cout<<q.s<<endl;
			return;
		}
		p.step=q.step+1;
        p.num=(q.num+m)%km;
		p.s=q.s+'+';
		if(map[(p.num%k+k)%k]==0)
		{
			Q.push(p);
			map[(p.num%k+k)%k]=1;
		}
		
		p.num=(q.num-m)%km;
		p.s=q.s+'-';
		if(map[(p.num%k+k)%k]==0)
		{
			Q.push(p);
			map[(p.num%k+k)%k]=1;
		}
		p.num=(q.num*m)%km;
		p.s=q.s+'*';
		if(map[(p.num%k+k)%k]==0)
		{
			Q.push(p);
			map[(p.num%k+k)%k]=1;
		}
		p.num=(q.num%m+m)%m%km;
		p.s=q.s+'%';
		if(map[(p.num%k+k)%k]==0)
		{
			Q.push(p);
			map[(p.num%k+k)%k]=1;
		}
	}
	cout<<0<<endl;
	return;
}

int main()
{
	while(scanf("%d %d %d",&n,&k,&m)!=EOF)
	{
		if(n==0&&m==0&&k==0)  break;
		km=k*m;
		bfs();
	}
	return 0;
}
