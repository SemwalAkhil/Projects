// CODE:-

class Person{
    void getFirstName(){
        System.out.println("First Name: " + "GAGAN");
    }

    void getLastName(){
        System.out.println("Last Name: " + "SAINI");
    }
}

class Employee extends Person{
    void getEmployeeId(){
        System.out.println("Employee ID: " + 90);
    }
    
    void getLastName(){
        System.out.println("Last Name: " + "SAINI, " + "Job Title: " + "Software Programmer");
    }
}

class Main{
    public static void main(String st[]){
        Employee obj = new Employee();

        obj.getFirstName();
        obj.getLastName();
        obj.getEmployeeId();
    }
}