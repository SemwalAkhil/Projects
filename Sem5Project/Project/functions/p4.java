//4. Write a Java method to count all the words in a string.
class Count
{
	int wordCount(String s)
	{
		int x=0;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i)=='.' || s.charAt(i)==',' || s.charAt(i)==' ')
			{
				x++;
			}
		}
		return x+1;
	}
}

class Main
{
	public static void main(String s[])
	{
		String a;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter a string : ");
			a=br.readLine();
			
			Count c=new Count();
			
			System.out.println("Total number of words in given string : "+c.wordCount(a));
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
	}
}

/*
 
Output : 

Enter a string : abc def,ghi.jkl m
Total number of words in given string : 5

 */