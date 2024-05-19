#include <iostream>
using namespace std;
/*
    1330 -> break to 100 , 50 , 20 , 1 rs notes
    use switch
*/
int main() {
    int num = 1330;
    int curr[4] = {100,50,20,1};

    // M1 -> without switch
    // for (int i = 0; i < 4 ; i++)
    // {
    //     int temp = curr[i];
    //     curr[i] = num/temp;
    //     num %= temp;
    // }
    // for (int i = 0; i < 4 ; i++)
    // {
    //     cout<<curr[i]<<" ";
    // }

    // M2 -> with switch
    // for (int i = 0; i < 4; i++)
    // {
    //     int temp = curr[i];
    //     switch (num > curr[i])
    //     {
    //     case true:
    //         curr[i] = num/temp;
    //         num %= temp;   
    //         break;
    //     default:
    //         curr[i] = 0;
    //         break;
    //     }
    // }
    // for (int i = 0; i < 4 ; i++)
    // {
    //     cout<<curr[i]<<" ";
    // }
    return 0;
}