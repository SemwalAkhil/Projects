/*
	49. To determine greatest of three numbers using functions
*/
#include <stdio.h>
#include <math.h>

int grt(int a, int b, int c){
	if ((a==b)&&(b==c)){
		return a;
	}
	if (a>b){
		if (a>c){
			return a;
		}
		return c;
	}
	else{
		if (b>c){
			return b;
		}
		return c;
	}
}

int main(){
	 int a,b,c;
	 printf("Enter the a,b&c : ");
	scanf("%d%d%d",&a,&b,&c);
	printf("Greatest %d ", grt(a,b,c));
	return 0;
}