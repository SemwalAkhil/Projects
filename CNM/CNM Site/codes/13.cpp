// 13.Newton's Forward Difference Method
#include <iostream>
#include <iomanip>
#include <cmath>
#define maxSize 100
using namespace std;

double factorial(double x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * factorial(x - 1);
}
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
            arr[j][i] = arr[j + 1][i - 1] - arr[j][i - 1];
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
    int pos = 0;
    double result = 0;
    double u, uProd = 1;
    u = (x - arr[pos][0]) / (arr[1][0] - arr[0][0]);
    for (int i = 1; i < (size + 1 - pos); i++)
    {
        for (int j = 0; j < (i - 1); j++)
        {
            uProd *= u - j;
        }

        result += (arr[pos][i] * uProd) / factorial(i - 1);
        uProd = 1;
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