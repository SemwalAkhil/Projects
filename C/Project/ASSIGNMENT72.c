/*
72.Write a program demonstrating-
1.Insertion of an element in array from sorted array
*/
#include<stdio.h>
int insertsort(int ar[],int s,int newel){
    int i,j;
    for(i=0;i<s;i++){
        if(ar[i]>=newel){
            break;
        }
    }
    for(j=s;j>i;j--){
        ar[j]=ar[j-1];
    }
    ar[i]=newel;
    return 0;
}
int displayarr(int ar[],int s){
    for(int i=0;i<s;i++){
        printf("%d  ",ar[i]);
    }
    printf("\n");
    return 0;
}
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,6},ns=6,n;
    printf("Array before insertion : ");
    displayarr(arr,(ns-1));
    printf("Enter the element to perform insertion : ");
    scanf("%d",&n);
    insertsort(arr,ns,n);
    printf("Array after insertion : ");
    displayarr(arr,ns);
    return 0;
}