/*8. Write a Java program to create class called "TrafficLight" with attributes for 
   color and duration, and methods to change the color and check for red or green.*/

import java.io.*;

class p8 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter initial color: ");
        String clr = br.readLine();

        System.out.print("Enter duration (in seconds): ");
        int dur = Integer.parseInt(br.readLine());

        TrafficLight t1 = new TrafficLight(clr, dur);
        t1.display();

        if (t1.isRed())
            System.out.println("Stop! The light is red.");
        else if (t1.isGreen())
            System.out.println("Go! The light is green.");
        else
            System.out.println("Caution! The light is " + clr);

        System.out.print("\nEnter new color: ");
        String newClr = br.readLine();

        System.out.print("Enter new duration: ");
        int newDur = Integer.parseInt(br.readLine());

        t1.changeColor(newClr, newDur);
        t1.display();

        if (t1.isRed())
            System.out.println("Stop! The light is red.");
        else if (t1.isGreen())
            System.out.println("Go! The light is green.");
        else
            System.out.println("Caution! The light is " + newClr);
    }
}

// Class representing a traffic light with color and duration
class TrafficLight {
    private String color;
    private int duration;

    TrafficLight(String c, int d) {
        color = c;
        duration = d;
    }

    // Method to change the color and duration
    void changeColor(String newColor, int newDuration) {
        color = newColor;
        duration = newDuration;
    }

    // Method to check if the color is red
    boolean isRed() {
        return color.equalsIgnoreCase("red");
    }

    // Method to check if the color is green
    boolean isGreen() {
        return color.equalsIgnoreCase("green");
    }

    // Display current color and duration
    void display() {
        System.out.println("\nCurrent Light: " + color + " | Duration: " + duration + " seconds");
    }
}
