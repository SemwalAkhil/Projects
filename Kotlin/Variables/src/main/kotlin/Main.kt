fun main() {
    var userName:String = "Kotlin"
//    specifying type of variable is optional
    println("Hello $userName")
    userName = "ak"
    println("Hello $userName")
//    userName = 4 //-> conversion from one type to other is not allowed
    val newName:String = "Kotlin"
    println("Hello $newName")
//    newName = "ak" //-> reassigning val not allowed
    var age:Int = 15
    println("Hello $userName your age is $age")
}