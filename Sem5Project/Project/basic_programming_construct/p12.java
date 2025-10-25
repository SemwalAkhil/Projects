//12. Write a Java program to count the letters, spaces, numbers and other characters of an input string
import java.io.*;

class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the String: ");
        String str = br.readLine();
        int i = 0, l = str.length();
        int c ,ca = 0,cs = 0,cn = 0,co = 0;
        while(i!=l){
            c = str.charAt(i);
            if(c == ' '){
                cs++;
            }else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                ca++;
            }else if (c >= '0' && c <= '9'){
                cn++;
            }else{
                co++;
            }
            i++;
        }
        System.out.println("Total Characters: " + l);
        System.out.println("Number of Alphabets: " + ca);
        System.out.println("Number of Digits: " + cn);
        System.out.println("Number of Other Characters: " + co);
    }
}