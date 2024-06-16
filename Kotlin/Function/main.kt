//fun main() {
//    birthdayGreeting()
//}
//
//fun birthdayGreeting(): Unit {
////    It's optional to specify the Unit return type in Kotlin. For functions that don't return anything, or returning Unit, you don't need a return statement.
//    println("Happy Birthday, Rover!")
//    println("You are now 5 years old!")
//}

//fun main() {
//    println(birthdayGreeting())
//}
//
//fun birthdayGreeting(): String {
//    val nameGreeting = "Happy Birthday, Rover!"
//    val ageGreeting = "You are now 5 years old!"
//    return "$nameGreeting\n$ageGreeting"
//}

fun main() {
    println(birthdayGreeting("Abc"))
    val count = "10"
    val count2 = "20"
    println(count.toInt() + count2.toInt())
}
fun birthdayGreeting(name: String): String {
    val nameGreeting = "Happy Birthday, $name!"
    val ageGreeting = "You are now 5 years old!"
    return "$nameGreeting\n$ageGreeting"
}

//Note: Although you often find them used interchangeably, a parameter and an argument aren't the same thing. When you define a function, you define the parameters that are to be passed to it when the function is called. When you call a function, you pass arguments for the parameters. Parameters are the variables accessible to the function, such as a name variable, while arguments are the actual values that you pass, such as the "Rover" string.

//Warning: Unlike in some languages, such as Java, where a function can change the value passed into a parameter, parameters in Kotlin are immutable. You cannot reassign the value of a parameter from within the function body.