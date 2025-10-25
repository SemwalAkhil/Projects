//13. Write a Java program to print the ascii value of a given character
import java.io.*;

class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the character: ");
        int c = br.read();
        System.out.println("Ascii value of '" + (char)c +"' character is "+ c);
    }
}
