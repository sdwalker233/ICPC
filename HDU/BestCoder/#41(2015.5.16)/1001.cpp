#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char ch;
	int num;
	node(char _ch=0,int _num=0){
		ch=_ch;
		num=_num;
	}
}card[1000][6];
int l=0;

 void run()
 {
 	int i,j,k,cnt,mn=5,t[50]={0};
 	char ch[10];
 	node s[10];
 	for(i=1;i<=5;i++){
 		scanf("%s",ch);
 		s[i].ch=ch[0];
 		if(strlen(ch)==2) s[i].num=ch[1]-'0';
 		else s[i].num=(ch[1]-'0')*10+ch[2]-'0';
 	}
 	for(i=1;i<=l;i++){
 		for(j=1;j<=5;j++){
 			for(k=1;k<=5;k++)
 				if(s[j].ch==card[i][k].ch&&s[j].num==card[i][k].num) t[i]++;
 		}
 	}
 	for(i=1;i<=l;i++)
 		mn=min(mn,5-t[i]);
	printf("%d\n",mn);
 }

int main()
{
	 int t,k,j;
	 char i;
	 for(i='A';i<='D';i++){
	 	for(j=1;j<=9;j++){
	 		l++;
	 		for(k=1;k<=5;k++){
	 			card[l][k]=node(i,j+k-1);
	 		}
	 	}
	 	l++;
	 	card[l][1]=node(i,1);
		card[l][2]=node(i,10);
		card[l][3]=node(i,11);
		card[l][4]=node(i,12);
		card[l][5]=node(i,13);
	 }
	 scanf("%d",&t);
	 while(t--)
	 	run();
 return 0;
}

