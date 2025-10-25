//20. Write a Java program to compute the sum of the first 100 prime numbers
class Main
{
    public static void main(String args[])
    {
        int i = 2, c = 100;
        int j, sum = 0;
        while(c!=0)
        {
            j = 2;
            while(j<=(i/2))
            {
                if(i%j == 0)
                    break;
                j++;
            }
            if(j>i/2){
                sum += i;
                c--;
            }  
            i++;  
        }
        System.out.println("Sum of first 100 prime number: " + sum);
    }
}