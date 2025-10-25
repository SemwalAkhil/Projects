//22. Write a Java program to count the number of even and odd elements in a given array
class Main
{
    public static void main(String args[])
    {
        int e=0;
        int arr[]={1,2,3,4,5,6,7,11};
        System.out.println("Your Array: ");
        for(int i:arr){
            System.out.print(i+" ");
            if(i%2==0)
                e++;
        }
        System.out.println("\nNumber of Evens: "+ e);
        System.out.println("Number of Odds: "+ (arr.length - e));
    }
}