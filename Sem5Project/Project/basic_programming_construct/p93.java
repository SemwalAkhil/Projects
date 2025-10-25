import java.util.Scanner;

public class SecondLargest {
    // Function to find second largest
    static int findSecondLargest(int[] arr) {
        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] > first) { // found new max
                second = first;
                first = arr[i];
            } else if(arr[i] > second && arr[i] != first) {
                second = arr[i];
            }
        }
        return second;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0; i<n; i++) {
            array[i] = sc.nextInt();
        }

        int secondLargest = findSecondLargest(array);
        System.out.println("Second Largest number is: " + secondLargest);
        sc.close();
    }
}
output:-
        Enter array size: 5
        Enter array elements:
        10 5 20 8 15
        Second Largest number is: 15
        