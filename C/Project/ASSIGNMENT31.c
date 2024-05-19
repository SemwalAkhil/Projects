/*
	31. Program to find the sum of odd numbers and sum of even numbers from the list of given numbers
*/
#include <stdio.h>
void sum(int* arr,int size){
	int sumEven=0;
	int sumOdd=0;
	for (int i=0 ; i<size ; i++){
		if (arr[i]%2 == 0){
			sumEven+=arr[i];
		}
		else{
			sumOdd+=arr[i];
		}
	}
	printf("SUM OF ODD : %d\n",sumOdd);
	printf("SUM OF EVEN : %d",sumEven);
}
int main(){
	int arr[]={1,2,3,4,5};
	sum(arr,5);
	return 0;
}