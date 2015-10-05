#include<stdio.h>
 
 int f(char s)
 {
	switch(s){
		case('0'):return 2;
		case('1'):return 7;
		case('2'):return 2;
		case('3'):return 3;
		case('4'):return 3;
		case('5'):return 4;
		case('6'):return 2;
		case('7'):return 5;
		case('8'):return 1;
		case('9'):return 2;
	}
 }

int main()
{
	printf("%d\n",f(getchar())*f(getchar()));
 return 0;
}

