// 15.Newton Divided Interpolation
#include <iostream>
#include <iomanip>
#define maxSize 100
using namespace std;

void getTable(double arr[maxSize][maxSize + 1], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter X[%d] & Y[%d] : ", i, i);
        cin >> arr[i][0] >> arr[i][1];
    }
}
void forwardDifferenceTable(double arr[maxSize][maxSize + 1], int size)
{
    int count = 1;

    for (int i = 2; i < (size + 1); i++)
    {
        for (int j = 0; j < (size - count); j++)
        {
            arr[j][i] = (arr[j + 1][i - 1] - arr[j][i - 1]) / (arr[j + i - 1][0] - arr[j][0]);
        }
        count++;
    }
}
void showTable(double arr[maxSize][maxSize + 1], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size + 1 - count); j++)
        {
            cout << setw(4) << setfill(' ') << arr[i][j] << " ";
        }
        count++;
        printf("\n");
    }
}
double valueAtX(double x, double arr[maxSize][maxSize + 1], int size)
{
    double result = 0;
    double xProd = 1;
    for (int i = 1; i < (size + 1); i++)
    {
        result += arr[0][i] * xProd;
        xProd *= x - arr[i - 1][0];
    }
    return result;
}
int main()
{
    double table[maxSize][maxSize + 1], val;
    int size;
    printf("Enter size of table (max : %d) : ", maxSize);
    cin >> size;
    if (size > maxSize)
    {
        printf("Max Size exceeded ! Operation Failed !");
    }
    getTable(table, size);
    forwardDifferenceTable(table, size);
    showTable(table, size);
    printf("Enter x : ");
    cin >> val;
    cout << valueAtX(val, table, size);
    return 0;
}