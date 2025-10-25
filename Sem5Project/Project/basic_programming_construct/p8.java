//8. Write a Java program to convert a binary number to decimal number

import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the binary value: ");
        int x = s.nextInt(2);
        System.out.println("Decimal Value: "+x);
    }
}