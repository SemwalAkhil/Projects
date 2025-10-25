//46. Java Program To Calculate CGPA Percentage
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of subjects: ");
        int i = 1, n = sc.nextInt();
        float per, tm = 0, om = 0;
        while(i <= n)
        {
            System.out.print("\nEnter the Obtained marks of "+ i +" Subject: ");
            om += sc.nextFloat();
            System.out.print("Enter the Total marks of "+ i +" Subject: ");
            tm += sc.nextFloat();
            i++;
        }
        per = (float)(om/tm)*100;
        System.out.println("\nPercentage of student: "+ per);
        System.out.println("CGPA of student: "+ (per/9.5));
    }
}