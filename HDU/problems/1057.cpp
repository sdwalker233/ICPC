#include<stdio.h>
#include<string.h>
int n,d[20],m[25][25]={0},xx[4]={1,0,0,-1},yy[4]={0,1,-1,0};

 void run()
 {
 	int i,j,k,p,tmp[25][25];
 	scanf("%d",&n);
 	for(i=0;i<=15;i++)
 		scanf("%d",&d[i]);
 	for(i=1;i<=20;i++)
 		for(j=1;j<=20;j++)
 			scanf("%d",&m[i][j]);
 	for(k=1;k<=n;k++){
 		memcpy(tmp,m,sizeof(tmp));
 		for(i=1;i<=20;i++)
 			for(j=1;j<=20;j++)
 				for(p=0;p<4;p++)
 					tmp[i][j]+=m[i+xx[p]][j+yy[p]];
 		for(i=1;i<=20;i++)
 			for(j=1;j<=20;j++){
 				m[i][j]+=d[tmp[i][j]];
 				if(m[i][j]<0) m[i][j]=0;
 				if(m[i][j]>3) m[i][j]=3;
 			}		
 		}
 	for(i=1;i<=20;i++){
 		for(j=1;j<=20;j++)
 			switch(m[i][j]){
 				case(0):printf(".");break;
 				case(1):printf("!");break;
 				case(2):printf("X");break;
 				case(3):printf("#");break;
 			}
 		printf("\n");
 	}
 }

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		run();
		if(t) printf("\n");
	}
 return 0;
}

