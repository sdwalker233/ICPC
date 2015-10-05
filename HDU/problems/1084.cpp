#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	int score,num;
	string time;
};
int n;

 bool cmp1(node x,node y)
 {
	 return x.time<y.time;
 }

 bool cmp2(node x,node y)
 {
	 return x.num<y.num;
 }

 void fuck()
 {
	 int i,j,p,cnt[6]={0},x[110],y[110];
	 node stu[6][101];
	 for(i=1;i<=n;i++){
		 cin>>p;
		 ++cnt[p];
		 cin>>stu[p][cnt[p]].time;
		 stu[p][cnt[p]].num=cnt[p];
		 x[i]=p;y[i]=cnt[p];
	 }
	 for(i=1;i<=cnt[5];i++)
		stu[5][i].score=100;
	 for(i=1;i<=cnt[0];i++)
		stu[0][i].score=50;
	 for(i=1;i<=4;i++){
		 sort(&stu[i][1],&stu[i][cnt[i]+1],cmp1);
		 for(j=1;j<=cnt[i]/2;j++)
			 stu[i][j].score=50+10*i+5;
		 for(j;j<=cnt[i];j++)
			 stu[i][j].score=50+10*i;
		 sort(&stu[i][1],&stu[i][cnt[i]+1],cmp2);
	 }
	 for(i=1;i<=n;i++)
		printf("%d\n",stu[x[i]][y[i]].score);
	 printf("\n");
 }

int main()
{
	while(~scanf("%d",&n)&&n!=-1){
		fuck();
	}
 return 0;
}

