// CODE:-

class Shape{
    double getPerimeter(){
        System.out.println("Perimeter: Not defined for generic shape.");
        return 0.0;
    }

    double getArea(){
        System.out.println("Area: Not defined for generic shape.");
        return 0.0;
    }
}

class Circle extends Shape{

    double radius;

    Circle(double radius){
        this.radius = radius;
    }

    double getPerimeter(){
        double perimeter = 2 * Math.PI * radius;
        return perimeter;
    }

    double getArea(){
        double area = Math.PI * Math.pow(radius,2);
        return area;
    }
}


class Main{
    public static void main(String st[]){
        int radius = 5;

        Circle obj = new Circle(radius);

        System.out.println("Radius: " + radius);
        System.out.println("Perimeter of Circle: " + obj.getPerimeter());
        System.out.println("Area of Circle: " + obj.getArea());
    }
}