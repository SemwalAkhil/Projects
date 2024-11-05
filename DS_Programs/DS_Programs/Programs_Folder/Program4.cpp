// Enter two Matrices from user, multiply the matrices and display the answer

// Enter two Matrices from user, subtract the matrices and display the answer

#include <iostream>
using namespace std;

int main(){

int a[50][50], b[50][50], row1, col1,row2, col2, i, j,k, c[50][50];

printf("Enter the rows and columns of the First Matrix:\n");
cin>>row1>>col1;

printf("Enter the rows and columns of the Second Matrix:\n");
cin>>row2>>col2;

if(col1==row2){
cout<<"Enter the elements of the First Matrix\n";

for(i=0;i<row1;i++){
    for(j=0;j<col1;j++){
        cin>>a[i][j];
    }
}

cout<<"Enter the elements of the Second Matrix\n";

for(i=0;i<row2;i++){
    for(j=0;j<col2;j++){
        cin>>b[i][j];
    }
}

for(i=0;i<row1;i++){
    for(j=0;j<col2;j++){
        c[i][j]=0;
        for(k=0;k<col1;k++){
            c[i][j]+=a[i][k]*b[k][j];
        }
    }
}



cout<<"The First matrix is:\n";

for(i=0;i<row1;i++){
    for(j=0;j<col1;j++){
        cout<<a[i][j]<<"\t";
    }
    cout<<"\n";
}

cout<<"The Second matrix is:\n";

for(i=0;i<row2;i++){
    for(j=0;j<col2;j++){
        cout<<b[i][j]<<"\t";
    }
    cout<<"\n";
}

cout<<"The resultant matrix is:\n";

for(i=0;i<row1;i++){
    for(j=0;j<col2;j++){
        cout<<c[i][j]<<"\t";
    }
    cout<<"\n";
}
}
else{
    cout<<"Matrix multiplication is not possible.\n";
}

 return 0;   
}