#include <iostream>
using namespace std;
// 1
int main()
{
    int a, b = 1;
    a = 10;
    if (++a)
    cout << b;
    else
    cout << ++b;
}

// 2
// int main()
// {
//     int a = 1;
//     int b = 2;

//     if(a-- > 0 && ++b > 2 ){
//         cout << "Stage1 - Inside If ";
//     } else{
//         cout << "Stage2 - Inside else ";
//     }
//     cout << a << " " << b << endl;
// }

// int main()
// {
//     int a = 1;
//     int b = 2;

//     if(a-- > 0 || ++b > 2 ){
//         cout << "Stage1 - Inside If ";
//     } else{
//         cout << "Stage2 - Inside else ";
//     }
//     cout << a << " " << b << endl;
// }

// 4
// int main()
// {
//     int number = 3;
//     cout << (25 * (++number) );
// }

// 5
// int main()
// {
//     int a = 1;
//     int b = a++;
//     int c = ++a;
//     cout << b ;
//     cout << c;
// }