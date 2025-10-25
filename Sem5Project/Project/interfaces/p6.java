// 6. Write a Java program to create an interface Drawable with a method draw() that takes no arguments and returns void. Create three classes Circle, Rectangle, and Triangle that implement the Drawable interface and override the draw() method to draw their respective shapes.

interface Drawable {
    void draw();
}

class Circle implements Drawable {
    public void draw() {
        System.out.println("Drawing a Circle");
    }
}

class Rectangle implements Drawable {
    public void draw() {
        System.out.println("Drawing a Rectangle");
    }
}

class Triangle implements Drawable {
    public void draw() {
        System.out.println("Drawing a Triangle");
    }
}

public class Main {
    public static void main(String[] args) {
        Drawable c = new Circle();
        Drawable r = new Rectangle();
        Drawable t = new Triangle();

        c.draw();
        r.draw();
        t.draw();
    }
}

/*
Output:
Drawing a Circle
Drawing a Rectangle
Drawing a Triangle
*/
