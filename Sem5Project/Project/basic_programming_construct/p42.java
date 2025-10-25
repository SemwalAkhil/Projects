//42. Java program to check vowel or consonant
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.print("Enter the Alphabet: ");
            char c = sc.next().charAt(0);
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            {
                if(c == 'a' || c== 'e' || c== 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    System.out.println("Its a vowel!");
                else
                    System.out.println("Its a consonant!");
                break;
            }
            else
                System.out.println("Please enter valid Alphabet!\n");
        }
    }
}