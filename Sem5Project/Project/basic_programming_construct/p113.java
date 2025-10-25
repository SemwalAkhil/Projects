import java.util.Scanner;

public class HCF {
    static int calculateHCF(int a, int b) {
        int hcf = 1;
        int min = (a < b) ? a : b;
        for(int i = min; i >= 1; i--) {
            if(a % i == 0 && b % i == 0) {
                hcf = i;
                break;
            }
        }
        return hcf;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter first number: ");
        int x = sc.nextInt();
        System.out.print("Enter second number: ");
        int y = sc.nextInt();

        System.out.println("HCF is: " + calculateHCF(x, y));
        sc.close();
    }
}
output:-
        Enter first number: 24
        Enter second number: 36
        HCF is: 12
        