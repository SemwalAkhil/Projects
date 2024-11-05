// Enter the Matrix from user, multiply it with a scalar value and display the answer

#include <iostream>
using namespace std;

int main(){
    int a[50][50], row, col, i, j, n;

cout<<"Enter the rows and columns of the Matrix:"<<endl;
cin>>row>>col;

cout<<"Enter the elements of the Matrix\n";

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cin>>a[i][j];
    }
}
cout<<"Enter the scalar value\n";
cin>>n;

cout<<"The Matrix is:\n";
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cout<<(n*a[i][j])<<"\t";
    }
    cout<<endl;
}
return 0;
}