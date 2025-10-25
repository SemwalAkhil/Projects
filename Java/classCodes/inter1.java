interface inter1
{
int x=10;
void display();
}

class A implements inter1
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
A obj=new A();
obj.display();
}
}