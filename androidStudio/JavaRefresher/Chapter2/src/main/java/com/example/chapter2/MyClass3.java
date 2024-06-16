package com.example.chapter2;

public class MyClass3 extends MyClass2{
//	extends -> inherit a parent class
	public void greet(){
		System.out.println("Hello World");
	}
	public static void main(String[] args){
		int a = 30;
		int b = 40;
		System.out.println(avg(a,b));
	}
}
