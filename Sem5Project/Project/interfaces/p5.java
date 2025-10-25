// 5. Write a Java program to create an interface Resizable with methods resizeWidth(int width) and resizeHeight(int height) that allow an object to be resized. Create a class Rectangle that implements the Resizable interface and implements the resize methods.

interface Resizable {
    void resizeWidth(int width);
    void resizeHeight(int height);
}

class Rectangle implements Resizable {
    int width, height;

    Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public void resizeWidth(int width) {
        this.width = width;
    }

    public void resizeHeight(int height) {
        this.height = height;
    }

    void display() {
        System.out.println("Rectangle width: " + width + ", height: " + height);
    }
}

public class Main {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(10, 20);
        r.display();

        r.resizeWidth(15);
        r.resizeHeight(25);
        r.display();
    }
}

/*
Output:
Rectangle width: 10, height: 20
Rectangle width: 15, height: 25
*/
