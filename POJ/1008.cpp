#include<stdio.h>
#include<string.h>
char Haab[19][7]={"pop","no","zip","zotz",
"tzec","xul","yoxkin","mol","chen","yax","zac",
"ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"},
     Tzolkin[20][9]={"imix","ik","akbal","kan","chicchan",
"cimi","manik","lamat","muluk","ok","chuen","eb","ben",
"ix","mem","cib","caban","eznab","canac","ahau"};

 void run(){
 	int i,d,m,y,a=0;
 	char s[9];
 	scanf("%d.%s%d",&d,&s,&y);
 	a+=365*y+d;
 	for(i=0;i<19;i++)
 		if(strcmp(s,Haab[i])==0){
 			a+=i*20;
 			break;
 		}
 	//printf("%d\n",a);
 	y=a/260;
 	a%=260;
 	m=a%13+1;
 	d=a%20;
 	strcpy(s,Tzolkin[d]);
 	printf("%d %s %d\n",m,s,y);
 }
int main(){
	int i,n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}
