// 6.	WAP to Multiply two matrixes.
#include <iostream>
using namespace std;
class Solution{
    public:
    // getting 2D array
    int** getMat(int a,int b){
        int** newArr = new int*[a];
        for (int i = 0; i < a; i++)
        {
            newArr[i] = new int[b];
            for (int j = 0; j < b; j++)
            {
                cout<<"ENTER ELEMENT ["<<i<<"] ["<<j<<"] :";
                cin>>newArr[i][j];
            }
        }
        return newArr;
    }
    // displaying 2d array
    void displayMat(int** mat,int m,int n){
        
        for (int i = 0; i < m; i++)
        {
            cout<<"[";
            for (int j = 0; j < n; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"]";
            cout<<endl;
        }
    }
    // matrix multiplication
    void matrixMul(){
        // getting size of matrices
        int m,n,p,q;
        cout<<"ENTER SIZE OF MATRIX : ";
        cin>>m>>n;
        cout<<"ENTER SIZE OF MATRIX 2 : ";
        cin>>p>>q;
        // checking if multiplicaation possible
        if (n == p)
        {
            // getting matrices
            cout<<"MATRIX 1 ELEMENTS"<<endl;
            int** mat1 = getMat(m,n);
            displayMat(mat1,m,n);
            cout<<"MATRIX 2 ELEMENTS"<<endl;
            int** mat2 = getMat(p,q);
            displayMat(mat2,p,q);

            // allocating memory to result matrix
            int** arr = new int*[m];
            for (int i = 0; i < m; i++)
            {
                arr[i] = new int[q];
            }
            // multiplication
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < q; j++)
                {
                    arr[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        arr[i][j] += mat1[i][k] * mat2[k][j];
                    }                    
                }   
            }
            // displaying result matrix
            cout<<"RESULT MATRIX"<<endl;
            displayMat(arr,m,q);
            
            // deallocating memory for mat1 and mat2
            for (int i = 0; i < m; i++) {
                delete[] mat1[i];
            }
            delete[] mat1;

            for (int i = 0; i < p; i++) {
                delete[] mat2[i];
            }
            delete[] mat2;

            // deallocating memory for arr
            for (int i = 0; i < m; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }
        else{
            cout<<"MULTIPLICATION FILLED"<<endl;
        }
    }
};
int main() {
    Solution a;
    a.matrixMul();
    return 0;
}