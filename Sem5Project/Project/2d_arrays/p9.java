//9. Program to find the sum of each row and each column of a matrix
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
	void sumRow()
	{
		int t;
		for(int i=0;i<r;i++)
		{
			t=0;
			for(int j=0;j<c;j++)
			{
				t+=mat[i][j];
			}
			System.out.println("Sum of row "+(i+1)+" : "+t);
		}
	}
	void sumColumn()
	{
		int t;
		for(int i=0;i<c;i++)
		{
			t=0;
			for(int j=0;j<r;j++)
			{
				t+=mat[j][i];
			}
			System.out.println("Sum of column "+(i+1)+" : "+t);
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
		m1.sumRow();
		System.out.println();
		m1.sumColumn();
	}
}

/*
Output : 

Enter data of matrix :
Enter the number of rows : 2
Enter the number of columns : 3

Enter data of matrix :
Enter value at index (1,1) : 1
Enter value at index (1,2) : 2
Enter value at index (1,3) : 3
Enter value at index (2,1) : 4
Enter value at index (2,2) : 5
Enter value at index (2,3) : 6

Data in matrix :
1       2       3
4       5       6

Sum of row 1 : 6
Sum of row 2 : 15

Sum of column 1 : 5
Sum of column 2 : 7
Sum of column 3 : 9

*/