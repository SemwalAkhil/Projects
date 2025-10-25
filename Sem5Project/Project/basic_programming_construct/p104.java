import java.util.Scanner;

public class SearchElement {
    static int search(int[] arr, int key) {
        for(int i=0; i<arr.length; i++) {
            if(arr[i] == key) {
                return i; // return index if found
            }
        }
        return -1; // -1 means not found
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements:");
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter key element to search: ");
        int key = sc.nextInt();

        int index = search(arr, key);
        if(index == -1) {
            System.out.println(key + " not found in the array");
        } else {
            System.out.println(key + " found at position: " + (index+1));
        }
        sc.close();
    }
}
output:-
        Enter array size: 5
        Enter elements:
        10
        20
        30
        40
        50
        Enter key element to search: 30
        30 found at position: 3
        