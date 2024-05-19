/*
	44. Program to show the concept of nested switch.A user is prompted input a category and subcategory and appropriate message is displayed.
*/
#include <stdio.h>

int main(){
	int Class=0;
	int rollNo=0;
	printf("ENTER CLASS OF STUDENT: ");
	scanf("%d",&Class);
	printf("ENTER ROLL NUMBER OF STUDENT: ");
	scanf("%d",&rollNo);
	switch(Class){
		case 1:
			switch(rollNo){
				case 1:
					printf("YOU'RE %d%d\n",Class,rollNo);
					break;
				default:
					printf("YOU'RE NOT OF THIS INSTITUTE\n");
					break;		
			}
			break;
		default:
			printf("YOU'RE NOT OF THIS INSTITUTE\n");
			break;			
	}
	return 0;
}