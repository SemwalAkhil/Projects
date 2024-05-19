package com.first;
// import java.util.Arrays;
import java.util.Scanner;
public class Main {

    public static void checkMoney(int money){
        final int pen = 40;
        final int pencil = 10;
        if (money>=(pen+pencil)) {
                System.out.println("You can buy both pen and pencil");
            } else {
                if (money>=pen) {
                    System.out.println("You can buy either pen or pencil");
                } else {
                    if (money>=pencil) {
                        System.out.println("You can buy only pencil");    
                    } else {
                        System.out.println("You can't buy anything");
                    }

                }
            }
    }
    public static void randomGame() {
        System.out.println("WELCOME TO THE GAME");
        int rand = (int) (100*Math.random());
        int input = 0;
        Scanner sc = new Scanner(System.in);
        while (input>=0 && input!=rand) {
            System.out.println("Enter Number :");
            input=sc.nextInt();
            if (input>rand) {
                System.out.println("Answer is less than it. Try Again !!!");
            } else {
                System.out.println("Answer is greater than it. Try Again !!!");
            }
        }
        System.out.println("Congrats !!! You got the right answer");
        System.out.println("Play again??? (Y/N)");
        String choice=sc.next();
        if (choice=="Y") {
            randomGame();
        }
        sc.close();


        
        

    }
    public static void main(String[] args) {
        // System.out.println("hello world");
        // String name = "abc";
        // System.out.println(name);
        // String name2 = name.replace('a', 'b');
        // System.out.println(name2);
        // System.out.println(name.charAt(0));
        // int marks=10;
        // System.out.println(marks);
        // int[] alpha= new int[3];
        // alpha[0]=4;
        // alpha[1]=2;
        // alpha[2]=3;
        // Arrays.sort(alpha);
        // System.out.println(alpha[0]);
        // int a=10;
        // a+=1.5;
        // a++;
        // System.out.println(a);
        // System.out.println(Math.max(5,6));
        // Scanner sc = new Scanner(System.in);
        // System.out.print("enter your age : ");
        // int age = sc.nextInt();
        // sc.close();
        // System.out.println(age);
        // int a='a';
        // System.out.println(a);
        // int a= 10;
        // int b= 12;
        // System.out.println(a>b?a:b);

    
    // Scanner sc = new Scanner(System.in);
    // System.out.print("Enter money you have : ");
    // int money = sc.nextInt();
    // checkMoney(money);
    // sc.close();
    
    /* 
    int[] marks={1,2,3,4};
    try {
        System.err.println(marks[5]);
    } catch (Exception e) {
        System.err.println("error");
    }
    System.out.println("out");
    */
    randomGame();
    } 
}
