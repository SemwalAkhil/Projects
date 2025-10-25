//19. Write a Java program to convert seconds to hour, minute and seconds
import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the Seconds: ");
        int sec = s.nextInt();
        int h = sec/3600;
        sec = sec - (h*3600);
        int m = sec/60;
        sec = sec - (m*60);
        System.out.println("Hours : minutes : seconds -> "+h+":"+m+":"+sec);
    }
}