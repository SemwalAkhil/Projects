import java.util.Scanner;

public class CountNotes {
    static void countNotes(int amount) {
        int[] notes = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
        System.out.println("Note distribution:");
        for (int note: notes) {
            int count = amount/note;
            amount %= note;
            System.out.println(note + " : " + count);
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter amount: ");
        int amount = sc.nextInt();
        countNotes(amount);
        sc.close();
    }
}
output:-
        Enter amount: 786
        Note distribution:
        1000 : 0
        500 : 1
        100 : 2
        50 : 1
        20 : 1
        10 : 1
        5 : 1
        2 : 0
        1 : 1
