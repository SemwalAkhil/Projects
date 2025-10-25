// CODE:-

abstract class GeometricShape {
    abstract double area();
    abstract double perimeter();
}

class Triangle extends GeometricShape {
    double base, height, side1, side2, side3;

    Triangle(double base, double height, double side1, double side2, double side3) {
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    double area() {
        return 0.5 * base * height;
    }

    double perimeter() {
        return side1 + side2 + side3;
    }
}

class Square extends GeometricShape {
    double side;

    Square(double side) {
        this.side = side;
    }

    double area() {
        return side * side;
    }

    double perimeter() {
        return 4 * side;
    }
}

class Main {
    public static void main(String[] args) {
        Triangle t = new Triangle(5, 4, 5, 4, 6);
        Square s = new Square(5);

        System.out.println("----- Triangle -----");
        System.out.println("Area of Triangle: " + t.area());
        System.out.println("Perimeter of Triangle: " + t.perimeter());

        System.out.println("\n----- Square -----");
        System.out.println("Area of Square: " + s.area());
        System.out.println("Perimeter of Square: " + s.perimeter());
    }
}
