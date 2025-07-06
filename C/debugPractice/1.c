/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.
                            4 4 4 4 4 4 4
                            4 3 3 3 3 3 4
                            4 3 2 2 2 3 4
                            4 3 2 1 2 3 4
                            4 3 2 2 2 3 4
                            4 3 3 3 3 3 4
                            4 4 4 4 4 4 4
Input Format
The input will contain a single integer .
Constraints
1 <= n <= 100
Sample Input 0
2
Sample Output 0
2 2 2
2 1 2
2 2 2
Sample Input 1
5
Sample Output 1
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5
Sample Input 2
7
Sample Output 2
7 7 7 7 7 7 7 7 7 7 7 7 7
7 6 6 6 6 6 6 6 6 6 6 6 7
7 6 5 5 5 5 5 5 5 5 5 6 7
7 6 5 4 4 4 4 4 4 4 5 6 7
7 6 5 4 3 3 3 3 3 4 5 6 7
7 6 5 4 3 2 2 2 3 4 5 6 7
7 6 5 4 3 2 1 2 3 4 5 6 7
7 6 5 4 3 2 2 2 3 4 5 6 7
7 6 5 4 3 3 3 3 3 4 5 6 7
7 6 5 4 4 4 4 4 4 4 5 6 7
7 6 5 5 5 5 5 5 5 5 5 6 7
7 6 6 6 6 6 6 6 6 6 6 6 7
7 7 7 7 7 7 7 7 7 7 7 7 7
*/
#include <stdio.h>
#include <math.h>
int main()
{
    FILE *file = fopen("input1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file creating new file\n");
        file = fopen("input1.txt", "w");
        for (int i = 0; i <= 10; i++)
        {
            fprintf(file, "%d\n", i);
        }
        fclose(file);
    }
    file = fopen("input1.txt", "r");
    FILE *ofile = fopen("output.txt", "w");
    int num, max, distance;
    while (fscanf(file, "%d", &num) != EOF)
    {
        // maximum number of lines to form (n x n)
        max = 2 * (num - 1) + 1;
        // n rows
        for (int i = 0; i < max; ++i)
        {
            // n cols
            for (int j = 0; j < max; ++j)
            {
                /*
                    picking a bigger of 2 distance
                    (0,0) (0,1) (0,2)    1  1  1
                    (1,0) (1,1) (1,2) => 1  0  1
                    (2,0) (2,1) (2,2)    1  1  1

                */
                distance = (int)(fabs(i - (num - 1)) > fabs(j - (num - 1))) ? fabs(i - (num - 1)) : fabs(j - (num - 1));
                /*
                    2  2  2
                    2  1  2
                    2  2  2
                */
                fprintf(ofile, "%d ", distance + 1); // Add 1 because distance 0 should be 1
            }
            fprintf(ofile, "\n");
        }
        fprintf(ofile, "----------------------------\n");
    }
    fclose(file);
    fclose(ofile);

    return 0;
}