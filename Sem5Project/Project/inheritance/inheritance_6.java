// CODE:-

class Animal{
    void move(){
        System.out.println("Animal Moving");
    }
    
}

class Cheetah extends Animal{
    void move(){
        System.out.println("Cheetah Running");
    }
}

class Main{
    public static void main(String st[]){
        Cheetah obj = new Cheetah();
        obj.move();
    }
}