import java.util.Scanner;

public class SortNames {
    static void sortStrings(String[] arr) {
        String temp;
        for(int i=0; i<arr.length-1; i++) {
            for(int j=i+1; j<arr.length; j++) {
                if(arr[i].compareTo(arr[j]) > 0) {  // compareTo for alphabetical order
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void printArray(String[] arr) {
        for(String s : arr) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of names: ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        String[] names = new String[n];
        System.out.println("Enter names:");
        for(int i=0; i<n; i++) {
            names[i] = sc.nextLine();
        }

        sortStrings(names);
        System.out.println("Names in alphabetical order:");
        printArray(names);
        sc.close();
    }
}
output:-
        Enter number of names: 3
        Enter names:
        John
        Alice
        Bob
        Names in alphabetical order:
        Alice
        Bob
        John
        