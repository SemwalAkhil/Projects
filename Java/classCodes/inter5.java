interface inter1
{
int x=10;
void display1();
}
interface inter3
{
void get();
}

interface inter2 extends inter1,inter3
{
void display2();
}

class A implements inter2
{
public void display1()
{
System.out.println("inter1");
}
public void display2()
{
System.out.println("inter2");

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