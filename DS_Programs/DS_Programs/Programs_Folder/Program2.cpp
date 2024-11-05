// Enter two Matrices from user, add the matrices and display the answer

#include <iostream>
using namespace std;

int main(){

int a[50][50], b[50][50], row, col, i, j, c[50][50];

printf("Enter the rows and columns of the Matrices:\n");
cin>>row>>col;

cout<<"Enter the elements of the First Matrix\n";

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cin>>a[i][j];
    }
}

cout<<"Enter the elements of the Second Matrix\n";

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cin>>b[i][j];
    }
}

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        c[i][j]=a[i][j]+b[i][j];
    }
}

cout<<"Sum of the Matrices is:\n";

for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cout<<c[i][j]<<"\t";
    }
    cout<<"\n";
}

 return 0;   
}