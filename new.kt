fun add(num1:Int,num2:Int):Int {
    val sum = num1 + num2
    return sum
}
fun main() {
    // add(10,2)
    // add(11,5)
    
    // println(add(10,2))
    
    // showName("a","s")

    val count:Int = 10
    println("You have $count unread messages")

    val name = "abc"
    print("You have message from $name")
    birthdayGreeting()
}
fun showName(FirstName:String,LastName:String) {
    println(FirstName+LastName)
}
fun birthdayGreeting(): Unit {
    println("Happy Birthday, Rover!")
    println("You are now 5 years old!")
}