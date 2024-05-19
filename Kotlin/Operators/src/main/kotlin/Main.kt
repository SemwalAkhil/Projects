fun main() {
    val x = 5
    val y = 3
    println("Result : " + (x + y))
    println("Result : " + (x - y))
    println("Result : " + (x * y))
    println("Result : " + (x / y))
    println("Result : " + (x % y))
    println()
    var z = 5.0
    println("Result : " + (z + y))
    println("Result : " + (z - y))
    println("Result : " + (z * y))
    println("Result : " + (z / y))
    println("Result : " + (z % y))

    println()
    z++
    println(z)
    z = z + 2
    println(z)
    z += 2
    println(z)
    /*
        ctrl + d -> duplicates line
    */
    println("True&&False : ${true && false}")
    println("True||False : ${true || false}")
//    in kotlin most of the bitwise operations are done through functions
    println("x or y : ${x or y}")
    println("x or y : ${x and y}")
    println("x or y : ${x xor y}")
    println("x or y : ${x.inv()}")
    println("x shl 1 (left shift 1 bit) : ${x.shl(1)}")
    println("x shr 1 (right shift 1 bit) : ${x.shr(1)}")
    println("x ushr 1 (unsigned right shift 1 bit) : ${x.ushr(1)}")
}