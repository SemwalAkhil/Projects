// CODE:-

class Employee{
    void work(){
        System.out.println("Do Your Work");
    }

    void getSalary(){
        System.out.println("Rs. 100000");
    }
}

class HRManager extends Employee{
    void work(){
        System.out.println("Complete Your Work");
    }

    void addEmployee(){
        System.out.println("Employee Added");
    }
}

class Main{
    public static void main(String st[]){
        Employee obj1 = new Employee();
        HRManager obj2 = new HRManager();

        obj2.work();
        obj2.getSalary();
        obj2.addEmployee();
    }
}