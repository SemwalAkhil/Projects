//2. Program to Add Two Matrices
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
	void addMatrix(Matrices m)
	{
		int add[][]=new int[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				add[i][j]=this.mat[i][j]+m.mat[i][j];
			}
		}
		System.out.println("Data after adding :");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print(add[i][j]+"	");
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
		
		System.out.println("Enter data of first matrix : ");
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
		System.out.println("Enter data of second matrix : ");
		System.out.print("Enter the number of rows : ");
		s=br.readLine();
		r=Integer.parseInt(s);
		System.out.print("Enter the number of columns : ");
		s=br.readLine();
		c=Integer.parseInt(s);
			
		Matrices m2=new Matrices(r,c);
		System.out.println();
		m2.addData();
		System.out.println();
		m2.displayMatrix();
		
		if(m1.r==m2.r && m1.c==m2.c)
		{
			System.out.println();
			System.out.println("Adding matrix 1 and matrix 2 : ");
			m2.addMatrix(m1);
		}
		else
		{
			System.out.println();
			System.out.println("Addition of matrices not possible");
		}
	}
}

/*
Output : 

Enter data of first matrix :
Enter the number of rows : 2
Enter the number of columns : 2

Enter data of matrix :
Enter value at index (1,1) : 1
Enter value at index (1,2) : 2
Enter value at index (2,1) : 3
Enter value at index (2,2) : 4

Data in matrix :
1       2
3       4

Enter data of second matrix :
Enter the number of rows : 2
Enter the number of columns : 2

Enter data of matrix :
Enter value at index (1,1) : 5
Enter value at index (1,2) : 6
Enter value at index (2,1) : 7
Enter value at index (2,2) : 8

Data in matrix :
5       6
7       8

Adding matrix 1 and matrix 2 :
Data in matrix :
6       8
10      12

*/