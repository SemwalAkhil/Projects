import java.util.Scanner;

public class DuplicateFinder {
    // Function to find duplicates
    static void findDuplicates(int[] arr) {
        boolean foundDuplicate = false;

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) { // Compare with all next elements
                if (arr[i] == arr[j]) {
                    System.out.println("Duplicate found: " + arr[i]);
                    foundDuplicate = true;
                    break; // Avoid multiple prints for same value
                }
            }
        }
        if (!foundDuplicate) {
            System.out.println("No duplicates found");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter array elements:");
        for(int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        findDuplicates(array);
        sc.close();
    }
}
output:-
        Enter array size: 6
        Enter array elements:
        4
        7
        2
        4
        9
        7
        Duplicate found: 4
        Duplicate found: 7
        