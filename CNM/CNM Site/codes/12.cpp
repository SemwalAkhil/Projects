// 12.Newton's Backward Difference Method
#include <iostream>
#include <iomanip>
#define maxSize 5
using namespace std;

void getTable(double arr[maxSize][maxSize + 1])
{
    for (int i = 0; i < maxSize; i++)
    {
        printf("Enter X[%d] & Y[%d] : ", i, i);
        scanf("%f %f", &arr[i][0], &arr[i][1]);
    }
}
void backwardDifferenceTable(double arr[maxSize][maxSize + 1])
{
    int count = 0;

    for (int i = 2; i < (maxSize + 1); i++)
    {
        for (int j = 0; j < (maxSize - (count++)); j++)
        {
            arr[i][j] = arr[i - 1][j + 1] - arr[i - 1][j];
            cout << setw(4) << arr[i][j] << " ";
        }
        printf("\n");
    }
}
int main()
{
    double table[maxSize][maxSize + 1];
    getTable(table);
    backwardDifferenceTable(table);
    return 0;
}