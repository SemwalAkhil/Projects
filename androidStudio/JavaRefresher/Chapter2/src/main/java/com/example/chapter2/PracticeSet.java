package com.example.chapter2;

import java.util.HashMap;

public class PracticeSet {
	public static void main(String[] args) {
		PracticeSet ps = new PracticeSet();
//		ps.multiplicationTable(5);
//		System.out.println("10 + 20 = "+ps.add(10, 20));
//		System.out.println(ps.day(1));
//		System.out.println(ps.incomeTax(500000));
//		System.out.println(ps.sumEven(10));
		ps.pattern(5);
	}
	public void multiplicationTable(int i){
		for(int j=1 ; j<=10 ; j++){
			System.out.println(i+"*"+j+"="+i*j);
		}
	}
	public int add(int a,int b){
		return a+b;
	}
	public String day(int day){
		HashMap<Integer,String> days = new HashMap<>();
		days.put(1, "Sunday");
		days.put(2, "Monday");
		days.put(3, "Tuesday");
		days.put(4, "Wednesday");
		days.put(5, "Thursday");
		days.put(6, "Friday");
		days.put(7, "Saturday");
		return days.get(day);
	}
	public double incomeTax(double income){
		if(income<=250000){
			return 0;
		}
		else if(income<=500000){
			return (income)*0.05;
		}
		else{
			return (income)*0.1;
		}
	}
	public int sumEven(int n){
		int sum=0;
		for(int i=1 ; i<=n ; i++){
			if((i&1) == 0){
				sum+=i;
			}
		}
		return sum;
	}
	public void pattern(int n){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<i ; j++){
				System.out.print("  ");
			}
			for(int j=(n-i) ; j>0 ; j--){
				System.out.print("* ");
			}
			System.out.println();
		}
	}
}
