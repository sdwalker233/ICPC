#include<iostream>
#include<cstdio>
using namespace std;
char a[200][12]={"1/2","2/3","3/4","4/5","5/6","6/7","7/8","8/9","9/10","10/11","11/12","12/13",
"2/3","1/1","6/5","4/3","10/7","3/2","14/9","8/5","18/11","5/3","22/13","12/7",
"3/4","6/5","3/2","12/7","15/8","2/1","21/10","24/11","9/4","30/13","33/14","12/5",
"4/5","4/3","12/7","2/1","20/9","12/5","28/11","8/3","36/13","20/7","44/15","3/1",
"5/6","10/7","15/8","20/9","5/2","30/11","35/12","40/13","45/14","10/3","55/16","60/17",
"6/7","3/2","2/1","12/5","30/11","3/1","42/13","24/7","18/5","15/4","66/17","4/1",
"7/8","14/9","21/10","28/11","35/12","42/13","7/2","56/15","63/16","70/17","77/18","84/19",
"8/9","8/5","24/11","8/3","40/13","24/7","56/15","4/1","72/17","40/9","88/19","24/5",
"9/10","18/11","9/4","36/13","45/14","18/5","63/16","72/17","9/2","90/19","99/20","36/7",
"10/11","5/3","30/13","20/7","10/3","15/4","70/17","40/9","90/19","5/1","110/21","60/11",
"11/12","22/13","33/14","44/15","55/16","66/17","77/18","88/19","99/20","110/21","11/2","132/23",
"12/13","12/7","12/5","3/1","60/17","4/1","84/19","24/5","36/7","60/11","132/23","6/1"};

int main()
{
	
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		printf("%s\n",a[(n-1)*12+m-1]);
	}
 return 0;
}
