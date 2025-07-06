// find nth prime number
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> primes = {2};
    int count = 1, n;
    printf("Enter n : ");
    cin >> n;
    for (size_t i = 3; count <= n; i++)
    {
        for (auto &&ele : primes)
        {
            if (!(i % ele))
            {
                break;
            }
            else if (ele >= (i / 2))
            {
                printf("%d ", i);
                primes.push_back(i);
                count++;
                break;
            }
        }
    }
    printf("\n");
    printf("%d prime is : %d", n, primes[n - 1]);
}