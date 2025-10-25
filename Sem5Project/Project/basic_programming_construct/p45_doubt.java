//45. Java Program to calculate electricity bill
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Old Unit: ");
        int ou = sc.nextInt();
        System.out.print("Enter New Unit: ");
        int nu = sc.nextInt();
        System.out.print("Enter Per Unit Charge: ");
        int puc = sc.nextInt();
        int uc = nu - ou;
        float p = uc * puc;
        p += (p*12.0f)/100; //including tax 
        System.out.println("Total Bill: "+ p);
    }
}