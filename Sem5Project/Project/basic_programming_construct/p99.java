import java.util.Scanner;

public class UniqueElements {
    static void printUnique(int[] arr) {
        for(int i=0; i<arr.length; i++) {
            boolean isDuplicate = false;
            for(int j=0; j<arr.length; j++) {
                if(i != j && arr[i] == arr[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if(!isDuplicate)
                System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0; i<n; i++) 
            arr[i] = sc.nextInt();

        System.out.print("Unique elements are: ");
        printUnique(arr);
        sc.close();
    }
}
output:-
        Enter array size: 8
        Enter array elements:
        2 3 5 3 7 5 8 9
        Unique elements are: 2 7 8 9 
        