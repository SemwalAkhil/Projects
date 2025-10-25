//12. Write a Java method that accepts three integers and returns true if one is the middle point between the other two integers, otherwise false
class Check
{
	boolean middle(int x,int y,int z)
	{
		if(((x+y)/2==z) || ((x+z)/2==y) || ((z+y)/2==x))
		{
			return true;
		}
		return false;
	}
}

class Main
{
	public static void main(String st[]) throws java.io.IOException
	{
		String s;
		int x,y,z;
		boolean res;
		
		Check c=new Check();
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter first number : ");
			s=br.readLine();
			x=Integer.parseInt(s);
			
			System.out.print("Enter second number : ");
			s=br.readLine();
			y=Integer.parseInt(s);
			
			System.out.print("Enter third number : ");
			s=br.readLine();
			z=Integer.parseInt(s);
			
			res=c.middle(x,y,z);
			
			if(res==true)
			{
				System.out.println("One number is middle of other 2 integer");
			}
			else
			{
				System.out.println("One number is not middle of other 2 integer");
			}
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}


/*

Output : 

Enter first number : 6
Enter second number : 5
Enter third number : 7
One number is middle of other 2 integer

 */