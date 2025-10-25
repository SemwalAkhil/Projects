interface inter1
{
int x=10;
void display1();
}
class b
{
}

class A extends b implements inter1
{
public void display1()
{
System.out.println("inter1");
}
}
class Main
{
public static void main(String st[])
{
inter1 obj=new A();
obj.display1();
}
}