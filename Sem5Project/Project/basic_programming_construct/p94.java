import java.util.Scanner;

public class SecondLowest {
    // Function to find second lowest
    static int findSecondLowest(int[] arr) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for(int i=0; i<arr.length; i++) {
            if(arr[i] < first) {
                second = first;
                first = arr[i];
            } else if(arr[i] < second && arr[i] != first) {
                second = arr[i];
            }
        }
        return second;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0; i<n; i++) {
            array[i] = sc.nextInt();
        }

        int secondLowest = findSecondLowest(array);
        System.out.println("Second Lowest number is: " + secondLowest);
        sc.close();
    }
}
output:- 
        Enter array size: 5
        Enter array elements:
        10 5 20 8 15
        Second Lowest number is: 8
        