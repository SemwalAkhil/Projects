//21. Write a Java program to swap the first and last elements of an array and create a new array
class Main
{
    public static void main(String args[])
    {
        int arr[] = {1,2,3,4,5};
        int copyArr[] = arr.clone();
        copyArr[0] = arr[arr.length-1];
        copyArr[1] = arr[0];
        System.out.println("Your Array: ");
        for(int i:arr){
            System.out.print(i+" ");
        }
        System.out.println("\nFinal New Array: ");
        for(int i:copyArr){
            System.out.print(i+" ");
        }
    }
}