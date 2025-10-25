// 2. Write a Java program to create a class called Vehicle with a method called drive(). Create a subclass called Car that overrides the drive() method to print "Repairing a car".

class Vehicle
{
    void drive()
    {
        System.out.println("Driving a car");
    }
}

class Car extends Vehicle
{
    void drive()
    {
        System.out.println("Repairing a car");
    }
}

class Main{
    public static void main(String st[])
    {
        Vehicle obj1 = new Vehicle();
        Car obj2 = new Car();

        obj1.drive();
        obj2.drive();
    }

}

