// CODE:-

class A{
    A(int x){
        System.out.println("First this line will execute");
    }
}

class B extends A{
    B(){
        super(1);
        System.out.println("Then, this second line will execute");
    }
}

class Main{
    public static void main(String st[]){
        B obj = new B();
    }
}