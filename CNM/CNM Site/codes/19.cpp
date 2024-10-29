// 19. Simpson's 3/8 Functional
#include <iostream>
using namespace std;
#define maxSize 100
double function(double x)
{
    return (1 / (1 + x * x));
}
double simpson(double arr[maxSize][2], int size)
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
            if ((i % 3) == 0)
            {
                result += 2 * arr[i][1];
            }
            else
            {
                result += 3 * arr[i][1];
            }
        }
    }
    return result * ((3 * (arr[1][0] - arr[0][0])) / 8);
}
int makeTable(double arr[maxSize][2], double start, double end, double difference)
{
    double i;
    int count = 0;
    for (i = start; i <= end; i += difference)
    {
        arr[count][0] = i;
        arr[count][1] = function(arr[count++][0]);
    }
    if ((i - difference) == end)
    {
        return count;
    }
    return 0;
}
int main()
{
    double arr[maxSize][2], start, end, difference;
    int size;
    printf("Enter start of integral : ");
    scanf("%lf", &start);
    printf("Enter end of integral : ");
    scanf("%lf", &end);
    printf("Enter interval of integral : ");
    scanf("%lf", &difference);
    size = makeTable(arr, start, end, difference);
    if (size)
    {
        printf("Integral of function for given range : %lf", simpson(arr, size));
    }
    else
    {
        printf("Invalid interval try again");
    }
    return 0;
}