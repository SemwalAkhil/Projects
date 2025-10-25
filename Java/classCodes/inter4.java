interface inter1
{
int x=10;
void display();
}
interface inter2
{
int display(int y);
}

class A implements inter1,inter2
{
public void display()
{
System.out.println("inter1");
}
public int display(int y)
{
System.out.println("inter2");
return 1;
}
}
class Main
{
public static void main(String st[])
{
inter1 obj=new A();
inter2 obj1=new A();
obj1.display(10);
obj.display();

}
}