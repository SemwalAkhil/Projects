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
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile("input1.txt");
    if (!infile)
    {
        cerr << "Failed reading file creating new file\n";
        infile.close();
        ofstream ofile("input1.txt");
        if (!ofile)
        {
            cerr << "Failed creating file\n";
            return 1;
        }
        for (int i = 1; i <= 10; i++)
        {
            ofile << i << endl;
        }
        ofile.close();
        infile.open("input1.txt");
        if (!infile)
        {
            cerr << "Error reading new file \n";
            return 1;
        }
    }
    ofstream ofile("output.txt");
    if (!ofile)
    {
        cerr << "Error creating file";
        return 1;
    }
    int num, max, d1;
    while (infile >> num)
    {
        max = 2 * num - 1;
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                d1 = (abs(num - i - 1) > abs(num - j - 1)) ? abs(num - i - 1) : abs(num - j - 1);
                ofile << d1 + 1 << " ";
            }
            ofile << endl;
        }
    }
    infile.close();
    ofile.close();
    return 0;
}