#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
    0 -> return            0
    1 -> return            1
    2 -> return (1) + (0)
                 ^     ^
                 1  +  0 = 1
    3 -> return (2) + (1)
                 ^     ^
                 1  +  1 = 2
    4 -> return (3) + (2)
                 ^     ^
                 2  +  1 = 3
    5 -> return (4) + (3)
                 ^     ^
                 3  +  2 = 5
                    print  ^
*/
int fibRec(int num){
    if (num <= 1){
        return num;
    }
    return fibRec(num-1)+fibRec(num-2);
}
/*
            x   y  
    0 ->    0   1   
    1 ->    1   1
    2 ->    1   2
    3 ->    2   3
    4 ->    3   5
    5 ->    5   8
    print   ^
*/
int fibIt(int len){
    int x = 0,y = 1,temp = 0;
    for (int count = 0; count < len; count++)
    {
        printf("%d ",x);
        temp = x;
        x = y;
        y += temp;
    }
}
/*
    fact(5) -> 5*fact(4) 
            -> 5*4*fact(3) 
            -> 5*4*3*fact(2) 
            -> 5*4*3*2*fact(1) 
            -> 5*4*3*2*1
*/
int factRec(int x){
    if (x<=1){
        return 1;
    }
    return x*(factRec(x-1));
}
/*
    fact(5) -> 5*i(=4)
            -> 5*4*i(=3)
            -> 5*4*3*i(=2)
            -> 5*4*3*2*i(=1)
            -> 5*4*3*2*1
*/
int factIt(int x){
    for (int i = (x - 1); i > 0; i--)
    {
        x *= i;
    }
    return x;
    
}
int countIns(int num){
    int* arrCount = (int*)calloc(10,sizeof(int));
    int rem = num;
    do{
        rem = num%10;
        num /= 10;
        *(arrCount+rem) += 1; 
    }while (num!=0);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d is %d times\n",i,*(arrCount+i));
    } 
}
int main(){
    /*
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",fibRec(i));
    }
    printf("\n");
    fibIt(10);
    */
    /*
    int arr2D[3][3] = {{1,2,3},
                       {6,5,4},
                       {8,7,9}};    
    for (int i = 0; i < 3; i++)
    {
        int grt = arr2D[i][0];
        for (int j = 0; j < 3; j++)
        {
            if (arr2D[i][j] > grt){
                grt = arr2D[i][j];
            }
        }
        printf("\n%d IS GREATEST IN ROW %d",grt,(i+1));
    }
    */
    
    //countIns(345900);
    
    //printf("fact(5) = %d = %d\n",factIt(5),factRec(5));
    /*
    int mat1[4][4];
    int mat2[4][4];
    int resMat[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("ENTER ELEMENT[%d][%d] = ",i,j);
            scanf("%d",&mat1[i][j]);   
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("ENTER ELEMENT[%d][%d] = ",i,j);
            scanf("%d",&mat2[i][j]);   
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            resMat[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                resMat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d ",mat1[i][j]);   
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d ",mat2[i][j]);   
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d ",resMat[i][j]);   
        }
        printf("\n");
    }
    */
   char a = 'a';
   char A = 'A';
   char z = 'z';
   char Z = 'Z';
   
   printf("%d\n",(int)a);
   printf("%d\n",(int)A);
   printf("%d\n",(int)Z);    
   printf("%d\n",(int)z);
}