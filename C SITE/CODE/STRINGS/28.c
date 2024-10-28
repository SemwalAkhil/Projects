// TODO
// 28. CREATE A DICTIONARY HAVING 10 WORDS AND THEIR MEANING WITH FOLLOWING OPERATIONS. [CREATE, DELETE, SEARCH].
#include <stdio.h>
#define maxSize 100
int create(char dict[10][maxSize], int index, char row[maxSize])
{
    int i;
    for (i = 0; row[i] != 0; i++)
    {
        dict[index][i] = row[i];
        if (i >= (maxSize - 1))
        {
            return 0;
        }
    }
    dict[index][i] = 0;
    return 1;
}
int delete(char dict[10][maxSize], int index)
{
    if ((index < 10) && (index >= 0))
    {
        dict[index][0] = 0;
        return 1;
    }
    return 0;
}
int search(char dict[10][maxSize], char term[maxSize])
{
    int j;
    for (int i = 0; i < 10; i++)
    {
        for (j = 0; (dict[j] != '-') && (dict[j] != 0); j++)
        {
            if (term[j] != dict[i][j])
            {
                break;
            }
        }
        if (term[j] == dict[i][j])
        {
            return i;
        }
    }
    return -1;
}
int main()
{

    return 0;
}