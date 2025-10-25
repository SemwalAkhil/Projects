//6. Write a Java method to print characters between two characters 
class Print
{
	void printchar(char x,char y)
	{
		int a=(int)x,b=(int)y;
		char c;
		for(int i=a;i<=b;i++)
		{	c=(char)i;
			System.out.println(c);
		}
	}
}

class Main
{
	public static void main(String st[])
	{
		String a;
		char x,y;
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		Print p=new Print();
		
		try
		{
			System.out.print("Enter first character : ");
			a=br.readLine();
			x=a.charAt(0);
			
			System.out.print("Enter last character : ");
			a=br.readLine();
			y=a.charAt(0);
			
			p.printchar(x,y);
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
	}
}


/*
 
Output : 

Enter first character : a
Enter last character : p
a
b
c
d
e
f
g
h
i
j
k
l
m
n
o
p

 */