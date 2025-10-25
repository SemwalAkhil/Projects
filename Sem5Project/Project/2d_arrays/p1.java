//1. Enter the Matrix of rows and columns entered by the user and print in matrix format
class Main
{
	public static void main(String st[])
	{
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			int r,c;
			String s;
			
			System.out.print("Enter the number of rows : ");
			s=br.readLine();
			r=Integer.parseInt(s);
			System.out.print("Enter the number of columns : ");
			s=br.readLine();
			c=Integer.parseInt(s);
			
			System.out.println();
			
			int mat[][]=new int[r][c];
			
			System.out.println("Enter data of matrix : ");
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					System.out.print("Enter value at index ("+(i+1)+","+(j+1)+") : ");
					s=br.readLine();
					mat[i][j]=Integer.parseInt(s);
				}
			}
			
			System.out.println();
			
			System.out.println("Data entered in matrix :");
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					System.out.print(mat[i][j]+"	");
				}
				System.out.println();
			}
			
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}


/*
Output : 

Enter the number of rows : 3
Enter the number of columns : 3

Enter data of matrix :
Enter value at index (1,1) : 1
Enter value at index (1,2) : 2
Enter value at index (1,3) : 3
Enter value at index (2,1) : 4
Enter value at index (2,2) : 5
Enter value at index (2,3) : 6
Enter value at index (3,1) : 7
Enter value at index (3,2) : 8
Enter value at index (3,3) : 9

Data entered in matrix :
1       2       3
4       5       6
7       8       9

*/