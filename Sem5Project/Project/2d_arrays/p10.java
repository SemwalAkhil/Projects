//10. Program to find the transpose of a given matrix
class Matrices
{
	int mat[][];
	int r;
	int c;
	
	java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
	java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
	Matrices(int r,int c)
	{
		this.r=r;
		this.c=c;
		mat=new int[r][c];
	}
	
	void addData() throws NumberFormatException,java.io.IOException
	{
		String s;
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
	}
	void displayMatrix()
	{
		System.out.println("Data in matrix :");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print(mat[i][j]+"	");
			}
			System.out.println();
		}
	}
	void displayTranspose()
	{
		int transpose[][]=new int[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				transpose[j][i]=mat[i][j];
			}
		}
		System.out.println("Transpose of matrix :");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print(transpose[i][j]+"	");
			}
			System.out.println();
		}
	}
}
class Main
{
	public static void main(String st[]) throws NumberFormatException,java.io.IOException
	{
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		int r,c;
		String s;
		
		System.out.println("Enter data of matrix : ");
		System.out.print("Enter the number of rows : ");
		s=br.readLine();
		r=Integer.parseInt(s);
		System.out.print("Enter the number of columns : ");
		s=br.readLine();
		c=Integer.parseInt(s);
			
		Matrices m1=new Matrices(r,c);
		
		System.out.println();
		m1.addData();
		System.out.println();
		
		m1.displayMatrix();
		
		System.out.println();
		
		if(r==c)
		{
			m1.displayTranspose();
		}
		else
		{
			System.out.println("Not a square matrix");
		}
	}
}

/*
Output : 

Enter data of matrix :
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

Data in matrix :
1       2       3
4       5       6
7       8       9

Transpose of matrix :
1       4       7
2       5       8
3       6       9

*/