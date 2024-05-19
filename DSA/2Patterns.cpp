#include <iostream>
#include <iomanip>
using namespace std;
/*
    * * * *
    * * * *
    * * * *
    * * * *
    no. of rows = no. of cols
*/
void printPattern(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
/*
    1 1 1 1
    2 2 2 2
    3 3 3 3
    4 4 4 4
    no. of rows = no. of cols
    no. on each row = row no.
*/
void printPattern1(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
/*
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    no. of rows = no. of cols
    no. on each col = col no.
*/
void printPattern2(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
/*
    4 3 2 1 
    4 3 2 1 
    4 3 2 1 
    4 3 2 1 
    no. of rows = no. of cols
    no. on each col = no.of col - col no.
*/
void printPattern3(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<n-j<<" ";
        }
        cout<<endl;
    }
}
/*
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16 
    no. of rows = no. of cols
    no. on each block = row no. * col no.
*/
void printPattern4(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<setw(2)<<setfill('0')<<(i*4 + j)<<" ";
        }
        cout<<endl;
    }
}
void printPattern4Alt(int n){
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++,count++)
        {
            cout<<setw(2)<<setfill('0')<<count<<" ";
        }
        cout<<endl;
    }
}
/*
    * 
    * *
    * * *
    * * * *
    row no. = no. of cols
    no. of stars in each row = row no.
*/
void printPattern5(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
/*
    1
    2 2
    3 3 3
    4 4 4 4
    row no. = no. of cols
    no. on each row = row no.
    repition = row no.
*/
void printPattern6(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
/*
    1   
    2 3        
    4 5 6       
    7 8 9 10
    row no. = no. of cols
    counting
*/
void printPattern7(int n){
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++,count++)
        {
            cout<<setw(2)<<setfill('0')<<count<<" ";
        }
        cout<<endl;
    }
}
/*
    1   
    2 3        
    3 4 5       
    4 5 6 7
    row no. = no. of cols
    col 1 elemwnt = row no.
*/
void printPattern8(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < 2*i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/*
    1   
    2 1        
    3 2 1       
    4 3 2 1
    row no. = no. of cols
    col 1 elemwnt = row no.
    decrease till 1
*/
void printPattern9(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/*
    A A A A
    B B B B
    C C C C
    D D D D
    no. of rows = no. of cols
    char on each row = increase with row no.
*/
void printPattern10(int n){
    int init = 65;
    for (int i = 0; i < n; i++,init++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<char(init)<<" ";
        }
        cout<<endl;
    }
}
/*
    A B C D
    A B C D
    A B C D
    A B C D
    no. of rows = no. of cols
    char on each row = increase with col no.
*/
void printPattern11(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0,init = 65 ; j < n; j++,init++)
        {
            cout<<char(init)<<" ";
        }
        cout<<endl;
    }
}
/*
    A B C D
    E F G H
    I J K L
    M N O P
    no. of rows = no. of cols
    char increasing
*/
void printPattern12(int n){
    char init = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++,init++)
        {
            cout<<char(init)<<" ";
        }
        cout<<endl;
    }
}
/*
    A B C D
    B C D E
    C D E F
    D E F G
    no. of rows = no. of cols
    char increasing in following form
            1 2 3 4
            2 3 4 5
            3 4 5 6
            4 5 6 7
*/
void printPattern13(int n){
    char init = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<char(init+i+j)<<" ";
        }
        cout<<endl;
    }
}
/*
    A
    B C
    D E F
    G H I J
    row no. = no. of cols
    char increasing
*/
void printPattern14(int n){
    char init = 65;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++,init++)
        {
            cout<<char(init)<<" ";
        }
        cout<<endl;
    }
}
/*
    A
    B C
    C D E
    D E F G
    row no. = no. of cols
    char increasing in row
    col 1 element in increasing order
*/
void printPattern15(int n){
    char init = 65;
    for (int i = 1; i <= n; i++,init++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<char(init+j)<<" ";
        }
        cout<<endl;
    }
}
/*
    D               4
    C D             3 4
    B C D           2 3 4
    A B C D         1 2 3 4
    row no. = no. of cols 
    char increasing in row
    col 1 element in decreasing order
*/
void printPattern16(int n){
    char init = 64+n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<char(init-i+j)<<" ";
        }
        cout<<endl;
    }
}
/*
          * 
        * *
      * * *
    * * * *
    no. of row = no. of cols
    no. of stars in each row = row no.
    no. of empty space in each row = total rows-row no.
*/
void printPattern17(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
        {
            if (j > i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
/*
    * * * *
    * * *
    * *
    * 
    total row - row no. + 1 = no. of cols
    no. of stars in each row = total row - row no. + 1
*/
void printPattern18(int n){
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
/*
    * * * *
      * * *
        * *
          * 
    no. of row = no. of cols
    no. of stars in each row = total rows - row no. + 1
    no. of empty space in each row = row no. - 1
*/
void printPattern19(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
/*
    1 1 1 1
      2 2 2
        3 3
          4
    no. of row = no. of cols
    no. in each row = row no.
    no. of repition in each row = total rows - row no. + 1
    no. of empty space in each row = row no. - 1
*/
void printPattern20(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i){
                cout<<"  ";
            }
            else{
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
    }
}
/*
    1 2 3 4
      2 3 4
        3 4
          4
    no. of row = no. of cols
    no. = col no.
    no. missing in each row = no. of empty space in each row = row no. - 1
*/
void printPattern21(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i){
                cout<<"  ";
            }
            else{
                cout<<j+1<<" ";
            }
        }
        cout<<endl;
    }
}
/*
          1
        2 3
      4 5 6
    7 8 9 10
    no. of rows = no. of cols
    increasing counting
    no. of spaces = total rows - row no.
*/
void printPattern22(int n){
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
        {
            if (j > i){
                cout<<"   ";
            }
            else{
                cout<<setw(2)<<setfill('0')<<count<<" ";
                count++;
            }
        }
        cout<<endl;
    }
}
/*
          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
    total rows + row no. - 1 = no. of cols
    increasing vertical counting
    no. of spaces = total rows - row no.
    horizontal count increase till row no. then decrease
*/
void printPattern23(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j > 0; j--)
        {
            cout<<"  ";
        }
        int count = 1;
        for (count; count < i; ++count)
        {
            cout<<count<<" ";
        }
        for (count; count > 0; count--)
        {
            cout<<count<<" ";
        }
        cout<<endl;
    }
}
/*
    1 2 3 4 5 5 4 3 2 1
    1 2 3 4 * * 4 3 2 1
    1 2 3 * * * * 3 2 1
    1 2 * * * * * * 2 1
    1 * * * * * * * * 1
    
    2 * total rows = no. of cols
    no. in col. = increasing row number till max is reached then back to 1 
    max no. replaced by * until minimum (i.e. 1) on either sides
*/
void printPattern24(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= (n-i); j++)
        {
            cout<<j<<" ";
        }
        for (int j = 0; j < 2*i; j++)
        {
            cout<<"* ";
        }
        
        for (int j = (n-i); j > 0 ; j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }   
}
int main() {
    cout<<"PATTERN"<<endl;
    printPattern(4);
    cout<<endl;
    cout<<"PATTERN 1"<<endl;
    printPattern1(4);
    cout<<endl;
    cout<<"PATTERN 2"<<endl;
    printPattern2(4);
    cout<<endl;
    cout<<"PATTERN 3"<<endl;
    printPattern3(4);
    cout<<endl;
    cout<<"PATTERN 4"<<endl;
    printPattern4(4);
    cout<<endl;
    cout<<"PATTERN 4 ALT"<<endl;
    printPattern4Alt(4);
    cout<<endl;
    cout<<"PATTERN 5"<<endl;
    printPattern5(4);
    cout<<endl;
    cout<<"PATTERN 6"<<endl;
    printPattern6(4);
    cout<<endl;
    cout<<"PATTERN 7"<<endl;
    printPattern7(4);
    cout<<endl;
    cout<<"PATTERN 8"<<endl;
    printPattern8(4);
    cout<<endl;
    cout<<"PATTERN 9"<<endl;
    printPattern9(4);
    cout<<endl;
    cout<<"PATTERN 10"<<endl;
    printPattern10(4);
    cout<<endl;
    cout<<"PATTERN 11"<<endl;
    printPattern11(4);
    cout<<endl;
    cout<<"PATTERN 12"<<endl;
    printPattern12(4);
    cout<<endl;
    cout<<"PATTERN 13"<<endl;
    printPattern13(4);
    cout<<endl;
    cout<<"PATTERN 14"<<endl;
    printPattern14(4);
    cout<<endl;
    cout<<"PATTERN 15"<<endl;
    printPattern15(4);
    cout<<endl;
    cout<<"PATTERN 16"<<endl;
    printPattern16(4);
    cout<<endl;
    cout<<"PATTERN 17"<<endl;
    printPattern17(4);
    cout<<endl;
    cout<<"PATTERN 18"<<endl;
    printPattern18(4);
    cout<<endl;
    cout<<"PATTERN 19"<<endl;
    printPattern19(4);
    cout<<endl;
    cout<<"PATTERN 20"<<endl;
    printPattern20(4);
    cout<<endl;
    cout<<"PATTERN 21"<<endl;
    printPattern21(4);
    cout<<endl;
    cout<<"PATTERN 22"<<endl;
    printPattern22(4);
    cout<<endl;
    cout<<"PATTERN 23"<<endl;
    printPattern23(4);
    cout<<endl;
    cout<<"PATTERN 24"<<endl;
    printPattern24(4);
    return 0;
}