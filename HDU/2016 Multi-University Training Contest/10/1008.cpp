#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct face{
	int a[2][2];
	friend bool operator ==(const face& x,const face &y)
	{
		if(x.a[0][0]==y.a[0][0]&&x.a[0][1]==y.a[0][1]&&x.a[1][0]==y.a[1][0]&&x.a[1][1]==y.a[1][1]) return true;
		else return false;
	}
	void shun()
	{
		int tmp=a[0][0];
		a[0][0]=a[1][0];
		a[1][0]=a[1][1];
		a[1][1]=a[0][1];
		a[0][1]=tmp;
	}
	void ni()
	{
		int tmp=a[0][0];
		a[0][0]=a[0][1];
		a[0][1]=a[1][1];
		a[1][1]=a[1][0];
		a[1][0]=tmp;
	}
	void LR()
	{
		swap(a[0][0],a[0][1]);
		swap(a[1][0],a[1][1]);
	}
	void UD()
	{
		swap(a[0][0],a[1][0]);
		swap(a[0][1],a[1][1]);
	}
};

struct cube{
	face f[6];
	friend bool operator ==(const cube& x,const cube& y)
	{
		int i;
		for(i=0;i<6;i++)
			if((x.f[i]==y.f[i])==0) return false;
		return true;
	}
	void move1()
	{
		f[1].ni();
		f[3].shun();
		face tmp=f[0];
		f[0]=f[2];
		f[2]=f[4];
		f[4]=f[5];
		f[5]=tmp;
	}
	void move2()
	{
		f[0].shun();
		f[1].shun();f[1].shun();
		f[4].ni();
		f[5].ni();f[5].ni();
		face tmp=f[1];
		f[1]=f[2];
		f[2]=f[3];
		f[3]=f[5];
		f[5]=tmp;
	}
	void rotate()
	{
		f[0].shun();
		f[1].shun();
		f[2].shun();
		f[3].shun();
		f[4].shun();
		f[5].ni();
		face tmp=f[1];
		f[1]=f[4];
		f[4]=f[3];
		f[3]=f[0];
		f[0]=tmp;
	}
	void reflect()
	{
		f[0].LR();
		f[1].LR();
		f[2].LR();
		f[3].LR();
		f[4].LR();
		f[5].LR();
		swap(f[1],f[3]);
	}
	void colour()
	{
		int i,j;
		int mp[10]={0},cnt=0;
		for(i=0;i<6;i++){
			for(j=0;j<4;j++){
				int v=f[i].a[j>>1][j&1];
				if(mp[v]==0) mp[v]=++cnt;
				f[i].a[j>>1][j&1]=mp[v];
			}
		}
	}
	bool read()
	{
		if(scanf("%1d%1d",&f[0].a[0][0],&f[0].a[0][1])==EOF) return 0;
		scanf("%1d%1d",&f[0].a[1][0],&f[0].a[1][1]);
		scanf("%1d%1d",&f[1].a[0][0],&f[1].a[0][1]);
		scanf("%1d%1d",&f[2].a[0][0],&f[2].a[0][1]);
		scanf("%1d%1d",&f[3].a[0][0],&f[3].a[0][1]);
		scanf("%1d%1d",&f[1].a[1][0],&f[1].a[1][1]);
		scanf("%1d%1d",&f[2].a[1][0],&f[2].a[1][1]);
		scanf("%1d%1d",&f[3].a[1][0],&f[3].a[1][1]);
		scanf("%1d%1d",&f[4].a[0][0],&f[4].a[0][1]);
		scanf("%1d%1d",&f[4].a[1][0],&f[4].a[1][1]);
		scanf("%1d%1d",&f[5].a[0][0],&f[5].a[0][1]);
		scanf("%1d%1d",&f[5].a[1][0],&f[5].a[1][1]);
		return 1;
	}
	void print()
	{
		int i,j;
		for(i=0;i<6;i++){
			for(j=0;j<4;j++) printf("%d",f[i].a[j>>1][j&1]);
			printf("\n");
		}
	}
}A,B;

bool fuck()
{
	int i,j,t1,t2;
	A.colour();
	for(t1=1;t1<=4;t1++){
		for(t2=1;t2<=4;t2++){
			B.colour();
			if(A==B) return true;
			B.reflect();
			B.colour();
			if(A==B) return true;
			B.reflect();
			B.rotate();
		}
		B.move1();
	}
	for(t1=1;t1<=4;t1++){
		for(t2=1;t2<=4;t2++){
			B.colour();
			if(A==B) return true;
			B.reflect();
			B.colour();
			if(A==B) return true;
			B.reflect();
			B.rotate();
		}
		B.move2();
	}
	return false;
}

int main()
{
	while(A.read()){
		B.read();
		/*A.print();
		A.reflect();
		A.reflect();
		A.print();*/
		if(fuck()) printf("yes\n");
		else printf("no\n");
	}
 return 0;
}

