// 14.Lagrangian's Interpolation
#include <iostream>
#define maxSize 100
using namespace std;
void getTable(double arr[maxSize][2], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter X[%d] & Y[%d] : ", i, i);
        cin >> arr[i][0] >> arr[i][1];
    }
}
double lagrangianInterpolation(double val, double arr[maxSize][2], int size)
{
    double prodX = 1, result = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j != i)
            {
                prodX *= (val - arr[j][0]) / (arr[i][0] - arr[j][0]);
            }
        }
        result += prodX * arr[i][1];
        prodX = 1;
    }
    return result;
}
int main()
{
    double table[maxSize][2], val;
    int size;
    printf("Enter size of table : ");
    cin >> size;
    getTable(table, size);
    printf("Enter value of x : ");
    cin >> val;
    cout << lagrangianInterpolation(val, table, size);
    return 0;
}