#include <iostream>
using namespace std;
void update(int arr[]){
    arr[0] =120;
}
int main() {
    int arr[4] = {1,2,3,4};
    cout<<"BEFORE UPDATE "<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<endl;
    }
    update(arr); // SINCE ADDRESS OF FIRST ELEMENT OF ARRAY IS SENT HENCE CHANGES MADE ARE AT ORIGINAL LOCATION 
    cout<<"AFTER UPDATE "<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}