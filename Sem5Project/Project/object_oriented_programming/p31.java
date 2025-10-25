/*31. Write a Java program to create a class called Car with private instance variables 
    company_name, model_name, year, and mileage. Provide public getter and setter methods 
    to access and modify the company_name, model_name, and year variables. Mileage is 
    set via constructor and only a getter is provided.*/

import java.io.*;

class p31 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Input company name
        System.out.print("Enter company name: ");
        String company = br.readLine();

        // Input model name
        System.out.print("Enter model name: ");
        String model = br.readLine();

        // Input year
        System.out.print("Enter year of manufacture: ");
        int year = Integer.parseInt(br.readLine());

        // Input mileage (constructor requires it)
        System.out.print("Enter mileage: ");
        double mileage = Double.parseDouble(br.readLine());

        // Create Car object using constructor
        Car car = new Car(company, model, year, mileage);

        // Display Car details
        System.out.println("\nCar Details:");
        System.out.println("Company Name: " + car.getCompanyName());
        System.out.println("Model Name: " + car.getModelName());
        System.out.println("Year: " + car.getYear());
        System.out.println("Mileage: " + car.getMileage());
    }
}

// Car class demonstrating encapsulation with constructor-based mileage
class Car {
    private String company_name;
    private String model_name;
    private int year;
    private double mileage; // read-only after constructor

    // Constructor sets all variables including mileage
    Car(String c, String m, int y, double mile) {
        company_name = c;
        model_name = m;
        year = y;
        mileage = mile;
    }

    // Getter and setter for company_name
    public String getCompanyName() {
        return company_name;
    }

    public void setCompanyName(String c) {
        company_name = c;
    }

    // Getter and setter for model_name
    public String getModelName() {
        return model_name;
    }

    public void setModelName(String m) {
        model_name = m;
    }

    // Getter and setter for year
    public int getYear() {
        return year;
    }

    public void setYear(int y) {
        year = y;
    }

    // Getter for mileage (read-only)
    public double getMileage() {
        return mileage;
    }
}
