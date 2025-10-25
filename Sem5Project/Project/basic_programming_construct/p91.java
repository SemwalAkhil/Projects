import java.util.Scanner;
import java.util.ArrayList;

public class ArrayToArrayList {
    // Function to convert array to ArrayList
    static ArrayList<Integer> convertToArrayList(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            list.add(arr[i]);
        }
        return list;
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

        ArrayList<Integer> list = convertToArrayList(array);
        System.out.println("Converted ArrayList: " + list);
        sc.close();
    }
}
output:-
        Enter array size: 5
        Enter array elements:
        10
        20
        30
        40
        50
        Converted ArrayList: [10, 20, 30, 40, 50]
        