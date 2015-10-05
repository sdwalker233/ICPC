#include<stdio.h>
#include<string.h>

int main()
{
	int i,x,y,d;
	int xx[4]={10,0,-10,0},yy[4]={0,10,0,-10};
	char s[201];
	while(gets(s)!=NULL){
		printf("300 420 moveto\n310 420 lineto\n");
		x=310;y=420;d=0;
		for(i=0;i<strlen(s);i++){
			if(s[i]=='V'){
				d++;
				if(d==4) d=0;
			}
			else{
				d--;
				if(d==-1) d=3;
			}
			x+=xx[d];
			y+=yy[d];
			printf("%d %d lineto\n",x,y);
		}
		printf("stroke\nshowpage\n");
	}
 return 0;
}

