// CODE:-

abstract class Employee {
    String name;
    double basicSalary;

    Employee(String name, double basicSalary) {
        this.name = name;
        this.basicSalary = basicSalary;
    }

    abstract void calculateSalary();
    abstract void displayInfo();
}

class Manager extends Employee {
    double bonus;

    Manager(String name, double basicSalary, double bonus) {
        super(name, basicSalary);
        this.bonus = bonus;
    }

    void calculateSalary() {
        double total = basicSalary + bonus;
        System.out.println("Total Salary of Manager: " + total);
    }

    void displayInfo() {
        System.out.println("Manager Name: " + name);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("Bonus: " + bonus);
    }
}

class Programmer extends Employee {
    double overtimePay;

    Programmer(String name, double basicSalary, double overtimePay) {
        super(name, basicSalary);
        this.overtimePay = overtimePay;
    }

    void calculateSalary() {
        double total = basicSalary + overtimePay;
        System.out.println("Total Salary of Programmer: " + total);
    }

    void displayInfo() {
        System.out.println("Programmer Name: " + name);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("Overtime Pay: " + overtimePay);
    }
}

class Main {
    public static void main(String[] args) {
        Manager m = new Manager("Rohit", 50000, 15000);
        Programmer p = new Programmer("Amit", 40000, 8000);

        System.out.println("----- Manager Details -----");
        m.displayInfo();
        m.calculateSalary();

        System.out.println("\n----- Programmer Details -----");
        p.displayInfo();
        p.calculateSalary();
    }
}
