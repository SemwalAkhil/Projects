package com.example.chapter2;

import java.util.ArrayList;

public class MyClass4 {
	public static void main(String[] args) {
		int a[] = {1,2,3,4,5};
		for (int j : a) {
			System.out.println(j);
		}
		ArrayList al = new ArrayList();
		al.add(1);
		al.add(2);
		al.add(3);
		for (int i = 0; i < al.size(); i++) {
			System.out.println(al.get(i));
		}
	}
}
