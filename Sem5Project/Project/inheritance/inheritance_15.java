// CODE:-

abstract class Animal{
    abstract void sound();
}

class Lion extends Animal{
    void sound(){
        System.out.println("Lion says: Roarrr!");
    }
}

class Tiger extends Animal{
    void sound(){
        System.out.println("Tiger says: Grrr!");
    }
}

class Main{
    public static void main(String st[]){
        Animal a1 = new Lion();
        Animal a2 = new Tiger();

        a1.sound();
        a2.sound();
    }
}