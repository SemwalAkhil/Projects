// CODE:-

class Employee {
    String name, address, job_title;
    double salary;

    Employee(String name, String address, double salary, String job_title) {
        this.name = name;
        this.address = address;
        this.salary = salary;
        this.job_title = job_title;
    }

    void calculate_Bonus() {
        System.out.println("Bonus not defined for general employee.");
    }

    void performance_Report() {
        System.out.println("Performance report not defined for general employee.");
    }

    void manage_Project() {
        System.out.println("Project management not defined for general employee.");
    }
}

class Manager extends Employee {
    Manager(String name, String address, double salary, String job_title) {
        super(name, address, salary, job_title);
    }

    void calculate_Bonus() {
        System.out.println("Manager Bonus: Rs." + (0.20 * salary));
    }

    void performance_Report() {
        System.out.println("Manager " + name + " has excellent team management skills.");
    }

    void manage_Project() {
        System.out.println("Manager " + name + " is managing multiple projects.");
    }
}

class Developer extends Employee {
    Developer(String name, String address, double salary, String job_title) {
        super(name, address, salary, job_title);
    }

    void calculate_Bonus() {
        System.out.println("Developer Bonus: Rs." + (0.15 * salary));
    }

    void performance_Report() {
        System.out.println("Developer " + name + " has good coding and debugging skills.");
    }

    void manage_Project() {
        System.out.println("Developer " + name + " is working on backend development.");
    }
}

class Programmer extends Employee {
    Programmer(String name, String address, double salary, String job_title) {
        super(name, address, salary, job_title);
    }

    void calculate_Bonus() {
        System.out.println("Programmer Bonus: Rs." + (0.10 * salary));
    }

    void performance_Report() {
        System.out.println("Programmer " + name + " writes efficient and clean code.");
    }

    void manage_Project() {
        System.out.println("Programmer " + name + " is maintaining existing projects.");
    }
}

class Main {
    public static void main(String[] args) {
        Manager m = new Manager("Amit", "Delhi", 80000, "Manager");
        Developer d = new Developer("Rohan", "Mumbai", 60000, "Developer");
        Programmer p = new Programmer("Gagan", "Chandigarh", 50000, "Programmer");

        System.out.println("----- Manager Details -----");
        m.calculate_Bonus();
        m.performance_Report();
        m.manage_Project();

        System.out.println("\n----- Developer Details -----");
        d.calculate_Bonus();
        d.performance_Report();
        d.manage_Project();

        System.out.println("\n----- Programmer Details -----");
        p.calculate_Bonus();
        p.performance_Report();
        p.manage_Project();
    }
}
