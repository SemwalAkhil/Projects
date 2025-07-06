// Enter the Number of rows - 6
// Pascal's Triangle of 6 rows.
//             1
//           1   1
//         1   2   1
//       1   3   3   1
//     1   4   6   4   1
//   1   5   10   10   5   1
#include <iostream>
#include <iomanip>

int main()
{
    int rows = 6; // Number of rows

    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        std::cout << std::setw((rows - i) * 2); // Adjust spacing for alignment
        for (int j = 0; j <= i; j++)
        {
            std::cout << number << "   ";
            number = number * (i - j) / (j + 1);
        }
        std::cout << std::endl;
    }

    return 0;
}
