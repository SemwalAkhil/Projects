//1. Write a Java program to create a class called Animal with a method called makeSound(). Create a subclass called Cat that overrides the makeSound() method to bark.

class Animal
{
    void makeSound()
    {
        System.out.println("ANIMAL SOUND");
    }
}

class Cat extends Animal
{
    void makeSound()
    {
        System.out.println("BARK");
    }
}

class Main
{
    public static void main(String st[])
    {
        Animal obj1 = new Animal();
        Cat obj2 = new Cat();

        obj1.makeSound();
        obj2.makeSound();
    }

}

