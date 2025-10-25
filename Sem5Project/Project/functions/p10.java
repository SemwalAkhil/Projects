//10. Write a Java method to count the number of digits in an integer with the value 2. The integer may be assumed to be non-negative.
class Count
{
	int count2(String s)
	{
		int c=0;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i)=='2')
			{
				c++;
			}
		}
		return c;
	}
}

class Main
{
	public static void main(String st[]) throws java.io.IOException
	{
		String s;
		int num;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		System.out.print("Enter a number : ");
		s=br.readLine();
		
		try
		{
			num=Integer.parseInt(s);
			
			Count c=new Count();
			System.out.println("Total number of digit '2' in given integer : "+c.count2(s));
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}


/*

Output : 

Enter a number : 123422
Total number of digit '2' in given integer : 3

 */