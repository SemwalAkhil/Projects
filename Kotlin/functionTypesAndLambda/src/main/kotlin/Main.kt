/*
fun main() {
//     val trickFunction = trick 
//     It produces an error because the Kotlin compiler recognizes trick as the name of the trick() function, but expects you to call the function, rather than assign it to a variable.
    
    val coins: (Int) -> String = { quantity ->
    	"$quantity quarters"
    }

    // When a function has a single parameter, and you don't provide a name, Kotlin implicitly
    assigns it its names, so you can omit the parameter name and -> symbol
        //    val coins: (Int) -> String = {
        //        "$it quarters"
        //    }
    val cupcake: (Int) -> String = {
    	"Have a cupcake!"
    }
    val trickFunction = trickOrTreat(true,null)
//     val treatFunction = trickOrTreat(false,coins)	//	passing lambda as argument
//     val treatFunction = trickOrTreat(false,cupcake)	//	passing lambda as argument
// 	   val treatFunction = trickOrTreat(false,{"$it quarters"}) // passing lambda expression as argument
//     val treatFunction = trickOrTreat(false,{"Have a cupcake"}) // passing lambda expression as argument
// 	   val treatFunction = trickOrTreat(false){"$it quarters"} // trailing lambda syntax
    val treatFunction = trickOrTreat(false,{"Have a cupcake"}) // trailing lambda syntax
    trickFunction()
    treatFunction()
}
*/
fun trick(){
    println("No treats!")
}
// Lambda expression
val treat = {
    println("Treats!")
}
// with parameters and return type
/*
val treat: () -> Unit = {
    println("Treats!")
}
*/
// A function is a data type, so you can use it like any other data type. You can even return functions from other functions.
fun trickOrTreat(isTrick: Boolean, extraTreat: ((Int) -> String)?): () -> Unit {
    if (isTrick){
        return ::trick
    } else {
        if (extraTreat != null){
            println(extraTreat(5))
        }
        return treat
    }
}

// The composable functions that you used to declare your UI take functions as parameters and are typically called using trailing lambda syntax.

// higher-order function
// When a function returns a function or takes a function as an argument, it's called a higher-order function. The trickOrTreat() function is an example of a higher-order function because it takes a function of ((Int) -> String)? type as a parameter and returns a function of () -> Unit type.
// Kotlin provides several useful higher-order functions, which you can take advantage of with your newfound knowledge of lambdas.

// repeat()
// The repeat() function is a concise way to express a for loop with functions.
// repeat(times: Int, action: (Int) -> Unit)
// The times parameter is the number of times that the action should happen.
// The action parameter is a function that takes a single Int parameter and returns a Unit type.
// The action function's Int parameter is the number of times that the action has executed so far.

fun main(){
    val treatFunction = trickOrTreat(false){"Have $it cupcakes!!"}
    val trickFunction = trickOrTreat(true,null)
    repeat(4){
        treatFunction()
    }
    trickFunction()
}


























