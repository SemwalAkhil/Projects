interface inter1
{
int x=10;
void display();
}
interface inter2
{
void display();
}

class A implements inter1,inter2
{
public void display()
{
System.out.println("hello");
}
}
class Main
{
public static void main(String st[])
{
inter1 obj=new A();
inter2 obj1=new A();
obj1.display();
obj.display();

}
}