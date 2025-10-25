class Date extends java.util.Date
{
public int getMonth()
{
return super.getMonth()+1;
}
public int getYear()
{
return super.getYear()+1900;
}
}



class A
{
public static void main(String st[]){
Date d=new Date();
System.out.println(d.getDate());
System.out.println(d.getMonth());
System.out.println(d.getYear());
}
}
