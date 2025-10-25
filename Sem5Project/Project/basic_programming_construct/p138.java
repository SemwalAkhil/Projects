import java.util.Scanner;

public class AbsoluteValue {
    static float absolute(float num) {
        if(num < 0)
            return -num;
        else
            return num;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter float value: ");
        float n = sc.nextFloat();

        System.out.println("Absolute value: " + absolute(n));
        sc.close();
    }
}
output:-
        Enter float value: -9.5
        Absolute value: 9.5
        