#include <iostream>
using namespace std;
void maxMin(int arr[],int size){
    int maxa = arr[0];
    int mina = arr[0];
    for (int i = 0; i < size; i++)
    {
        // M1
        // maxa = max(maxa,arr[i]);
        // mina = min(mina,arr[i]);

        // M2
        // if (arr[i] > maxa)
        // {
        //     maxa = arr[i];
        // }
        // else if (arr[i] < mina)
        // {
        //     mina = arr[i];
        // }        
    }
    cout<<"MAXIMUM : "<<maxa<<endl;
    cout<<"MINIMUM : "<<mina<<endl;
}
int main() {
    /*
        arr[const] <- preferred practice over -> arr[variable] 
    */
    int arr[] = {14,5,35,32,5,63,2,56,3,24};
    maxMin(arr,10);
    return 0;
}