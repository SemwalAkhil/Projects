// Enter a Matrix from user, copy it in another matrix of same size

#include <iostream>
using namespace std;

int main(){

int a[50][50], b[50][50], row, col, i, j;

printf("Enter the rows and columns of the Matrix:\n");
cin>>row>>col;

cout<<"Enter the elements of the Matrix\n";

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cin>>a[i][j];
        b[i][j]=a[i][j];
    }
}

cout<<"The Matrix is:\n";
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cout<<b[i][j]<<"\t";
    }
    cout<<endl;
}
return 0;
}
