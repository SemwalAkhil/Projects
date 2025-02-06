// Start measuring time
const start = performance.now();

// Code block whose execution time you want to measure
for (let i = 0; i < 100000000; i++); // Example loop

// Stop measuring time
const end = performance.now();

// Calculate the time taken in seconds
const timeTaken = (end - start) / 1000; // Convert milliseconds to seconds

console.log(`JS Execution Time: ${timeTaken.toFixed(6)} seconds`);
