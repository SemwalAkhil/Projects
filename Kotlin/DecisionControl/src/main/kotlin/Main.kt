fun main() {
    if (true){
        println("hello world")
    }
    if (false){

    }
    else {
        println("welcome to Kotlin")
    }
    if (false){

    }else if(true){
        println("this is good")
    }
    else{
        println("this is bad")
    }
    var x = 15
//    when (x){
//        10,7 -> println("x is $x")
////        in (11..20) -> println("x is in 11-20")
//        !in (11..20) -> println("x is in 11-20")
//        // in start .. end to check if element in range
//        else -> println("x is not 7 or 10")
//    }
//    val text = when (x){
//        10,7 -> "x is $x"
//        !in (11..20) -> "x is in 11-20"
//        else -> "x is not 7 or 10"
//    }
    x = 7
    val text = when {
        x < 7 -> "x is less than 7"
        x == 7 || x == 10 -> "x is $x"
        x in (11..20) -> "x is in 11-20"
        else -> "x is not 7 or 10"
    }
    println(text)
}