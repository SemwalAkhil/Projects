//58. Write a program in Java to display the first 5 natural numbers

class Main{
    public static void main(String args[])
    {
        int n = 5;
        System.out.print("First "+ n +" natural numbers: ");
        for(int i = 1;i <= n;i++)
        {
            System.out.print(i+" ");
        }
    }
}