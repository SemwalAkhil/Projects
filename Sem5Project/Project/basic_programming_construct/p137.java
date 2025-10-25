import java.util.Scanner;

public class RomanToInteger {
    static int value(char r) {
        switch(r) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }

    static int romanToInt(String s) {
        int total = 0, prev = 0;
        for(int i = s.length()-1; i >= 0; i--) {
            int curr = value(s.charAt(i));
            if(curr >= prev)
                total += curr;
            else
                total -= curr;
            prev = curr;
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Roman Numeral: ");
        String roman = sc.nextLine().toUpperCase();

        System.out.println("Integer value: " + romanToInt(roman));
        sc.close();
    }
}
output:-
        Enter Roman Numeral: XIV
        Integer value: 14
        