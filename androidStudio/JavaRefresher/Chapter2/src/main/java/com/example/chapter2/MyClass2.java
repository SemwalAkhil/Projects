package com.example.chapter2;

public class MyClass2 {
	public static void main(String[] args) {
		int a = 10;
		int b = 20;
		System.out.println("Average is : " + avg(a, b));
//		Non static functions need object instance to call
//		Static functions don't need object instance to call
		MyClass3 obj = new MyClass3();
		obj.greet();
		MyClass2 obj2 = new MyClass2();
		obj2.greet();
	}
	public static float avg(int a, int b) {
		return ((float)a + (float)b)/2;
	}
	public void greet() {
		System.out.println("Hello");
	}
//	Static methods belong to the class itself and operate without needing a specific object instance. They are useful for utility functions, factory methods, and scenarios where you don't need object-specific data.
//	Instance methods (non-static methods) belong to individual objects of the class. They can access and manipulate the object's data (instance variables) and provide behavior specific to that object.
}
