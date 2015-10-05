#include<stdio.h>
struct NODE{
	char s[51];
	int p;
}DNA[101],tmp;
	
int main(){
	int n,m,j,i,a[3];
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%s",&DNA[i].s);
		DNA[i].p=0;
	}
	for(i=1;i<=m;i++){
		a[0]=0;a[1]=0;a[2]=0;
		for(j=0;j<n;j++){
			 switch(DNA[i].s[j]){
			 	case('A'):DNA[i].p+=a[0]+a[1]+a[2];break;
			 	case('C'):DNA[i].p+=a[1]+a[2];a[0]++;break;
			 	case('G'):DNA[i].p+=a[2];a[1]++;break;
			 	case('T'):a[2]++;break;
			 }
			//printf("%c %d %d %d %d\n",DNA[i].s[j],a[0],a[1],a[2],DNA[i].p);
		}
	}
	for(i=1;i<=m;i++)
		for(j=1;j<m;j++)
			if(DNA[j].p>DNA[j+1].p){
				tmp=DNA[j];
				DNA[j]=DNA[j+1];
				DNA[j+1]=tmp;
			}
	for(i=1;i<=m;i++)
		printf("%s\n",DNA[i].s);
 return 0;
}

