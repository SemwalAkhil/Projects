/*
	17.2. To convert time in seconds to time in minutes , hours and seconds
*/
#include <stdio.h>
int timeConversion(int sec){
	int hour=0;
	int min=0;
	min=sec/60;
	hour=min/60;
	sec%=60;
	min%=60;
	printf("%d HOURS %d MINUTES %d SECONDS",hour,min,sec);
}
int main(){
	timeConversion(3661);
	return 0;
}