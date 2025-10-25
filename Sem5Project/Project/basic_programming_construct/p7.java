// 7. Write a Java program to convert a decimal number to binary numbers
import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        String bin = "",temp ="";
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the decimal value: ");
        int x = s.nextInt();
        int y = x;
        while(x!=0){
            bin = bin + (char)(x%2 + '0');
            x = x/2;
        }
        x = bin.length()-1;
        while(x!=-1){
            temp = temp + bin.charAt(x--);
        }
        System.out.println("Binary Value of "+y+" is "+temp);
    }
}