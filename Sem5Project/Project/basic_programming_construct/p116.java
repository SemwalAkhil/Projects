import java.util.Scanner;

public class ArmstrongNumbers {
    static boolean isArmstrong(int num) {
        int original = num, sum = 0, digits = 0, temp = num;
        while (temp != 0) {
            digits++;
            temp /=10;
        }
        temp = num;
        while (temp !=0) {
            int rem = temp %10;
            sum += Math.pow(rem, digits);
            temp /=10;
        }
        return sum == original;
    }

    public static void main(String[] args) {
        System.out.print("Armstrong numbers between 1 and 600: ");
        for(int i=1; i<=600; i++) {
            if(isArmstrong(i))
                System.out.print(i + " ");
        }
        System.out.println();
    }
}
output:-
Armstrong numbers between 1 and 600: 1 2 3 4 5 6 7 8 9 153 370 371 407 
