
//66. Write a java program that accepts three numbers from the user and check if numbers are in “increasing” or “decreasing” order.
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter 1st number: ");
        int n1 = s.nextInt();
        System.out.print("Enter 2nd number: ");
        int n2 = s.nextInt();
        System.out.print("Enter 3rd number: ");
        int n3 = s.nextInt();
        if(n1 >= n2 && n2 >= n3)
            System.out.println("Numbers are in Decreasing order!");
        else if(n1 <= n2 && n2 <= n3)
            System.out.println("Numbers are in Increasing order!");
        else
            System.out.println("Numbers are in Random order!");
    }
}
