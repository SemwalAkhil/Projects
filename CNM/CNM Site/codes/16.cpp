// 16. Trapezoidal Method Tabulated
#include <iostream>
using namespace std;
#define maxSize 100
double trapezoidal(double arr[maxSize][2], int size)
{
    double result = 0;
    for (int i = 0; i < size; i++)
    {
        if ((i == 0) || (i == size - 1))
        {
            result += arr[i][1];
        }
        else
        {
            result += 2 * arr[i][1];
        }
    }
    return result * ((arr[1][0] - arr[0][0]) / 2);
}
int main()
{
    double arr[maxSize][2], h;
    int size;
    printf("Enter size of table : ");
    scanf("%d", &size);
    printf("Enter x0 : ");
    scanf("%lf", &arr[0][0]);
    printf("Enter common difference in x : ");
    scanf("%lf", &h);
    for (int i = 0; i < size; i++)
    {
        if (i != 0)
        {
            arr[i][0] = arr[i - 1][0] + h;
        }
        printf("Enter y for %lf : ", arr[i][0]);
        scanf("%lf", &arr[i][1]);
    }
    printf("Value of integration : %lf", trapezoidal(arr, size));
    return 0;
}