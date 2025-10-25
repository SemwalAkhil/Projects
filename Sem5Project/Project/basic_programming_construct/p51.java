//51. Java Program To Calculate Power Of Number
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        System.out.print("Enter the power: ");
        int p = sc.nextInt();
        int f = 0;
        float sum = 1;
        if(p<0){
            f = 1;
            p = -p;
        }
        while(p!=0){
            sum *= n;
            p--;
        }
        if(f == 1)
            sum = 1/sum;
        System.out.println("Power of number: "+ sum);
    }
}