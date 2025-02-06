fun main() {
    // Start measuring time
    val startTime = System.nanoTime()

    // Code block whose execution time you want to measure
    for (i in 0 until 100000000) {} // Example loop

    // Stop measuring time
    val endTime = System.nanoTime()

    // Calculate the time taken in seconds
    val timeTaken = (endTime - startTime) / 1_000_000_000.0

    println("Kotlin Execution Time: %.6f seconds".format(timeTaken))
}
