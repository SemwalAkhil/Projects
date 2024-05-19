#include <iostream>
using namespace std;
class sort{
    public:
        void bubbleSort(int *arr,int len){
            int temp;
            for (int j = 0; j < len; j++)
            {
                for (int i = 0; i < len; i++)
                {
                    if (*(arr+i) > *(arr+i+1)){
                        temp = *(arr+i);
                        *(arr+i) = *(arr+i+1);
                        *(arr+i+1) = temp;
                    }
                }
            }
        }
        void selectionSort(int *arr,int len){
            int min = *arr;
            int i = 0;
            int temp;
            while (i<len){
                for (int j = 0; j<len ; j++){
                    if (*(arr+i) < *(arr+j)){
                        temp = *(arr+i);
                        *(arr+i) = *(arr+j);
                        *(arr+j) = temp;
                    }
                }
                i++;
            }
        }
        void insertionSort(int *arr,int len){
            for (int mid = 1; i < len; i++)
            {
                int left = i-1;
                while (left >= 0 && *(arr+left)>*(arr+mid))
                {
                    
                }
                
            }
            


        }
        // void mergeSort(int *arr,int len){

        // }

        void display(int *arr,int len){
            for (int i = 0; i < len; i++)
            {
                    cout<<*(arr+i)<<endl;
            }
                
        }
};

int main(){
    sort a;
    int arr[] = {2,4,3,8,5,1};
    // a.bubbleSort(&arr[0],6);
    a.selectionSort(&arr[0],6);
    a.display(&arr[0],6);
    return 0;
}