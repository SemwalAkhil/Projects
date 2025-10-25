//16. Write a Java program to print the odd numbers from 1 to 20
class Main
{
    public static void main(String args[])
    {
        int i = 1, n = 21;
        System.out.println("Odd Numbers from 1 to "+ (n-1));
        while(i != n)
        {
            System.out.print(i + " ");
            i += 2;
        }
    }
}