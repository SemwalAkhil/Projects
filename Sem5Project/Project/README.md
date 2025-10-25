# C4 Knowledge Seekers – Core Java Programming Solutions

Welcome to the **C4 Knowledge Seekers – Core Java Programming** solutions repository!
This repo contains student-submitted solutions to the practice problems listed at the [Core Java Programming](https://c4knowledgeseekers.in/practice-problems/core-java-programming) page.

---

## 📚 About

This repository aims to:

* Provide working Java code solutions for each of the Core Java topics on the site.
* Help students compare approaches, learn from each other, and improve their programming skills.
* Serve as a reference library for future students (and current ones) to see well-structured, clean Java code for common problems.

---

## 🧭 Topics Covered

The problems are organized by topics as per the site. Some of the topics include:

* 2D ARRAYS
* APPLETS
* BASIC PROGRAMMING CONSTRUCTS
* DATA CONVERSION
* DELEGATION EVENT MODEL
* EXCEPTION HANDLING
* FUNCTIONS
* GUI (AWT)
* INHERITANCE
* INPUT/OUTPUT
* INTERFACES
* JDBC
* MULTITHREADING
* OBJECT ORIENTED PROGRAMMING
* PACKAGES
* SINGLE DIMENSION ARRAYS
* STRINGS

---

## 📂 Repository Structure

The repo is organized **topic-wise** (e.g. `basic_programming_construct`, `strings`, `inheritance`, etc.).  

Inside each topic folder, problem solutions are named as **p_X.java** where **X** is the problem number.  

- **p1.java** → Single-script program (all logic in one file)  
- **p2_1.java, p2_2.java, …** → Multi-script or multi-class programs (can have sub-classes in the same file)  

Example:  

```

basic_programming_construct/
├── p1.java        # Simple single-script program
├── p2_1.java      # Multi-script program, first variation
├── p2_2.java      # Multi-script program, second variation
...
strings/
├── p1.java
├── p2_1.java
...

````

---

## 🧰 Program Templates

### 🔹 Single-script Programs (p1.java, p3.java, etc.)

```java
// 1. Title of the program

/*
IMPORTS
*/

// Use same class name as script name
class p1 {
    public static void main(String args[]) {
        // Program logic here
    }
}
````

---

### 🔹 Multi-script Programs (p2_1.java, p2_2.java, etc.)

```java
// 2.1. Title of the program (Sample for programs across multiple script files or classes)

/*
IMPORTS
*/

// Use same class name as script name
class p2_1 {
    public static void main(String args[]) {
        // Main program logic here
    }
}

// In case further sub-classes are needed, 
// use the following naming or any naming that suits functionality
class p2_1_1 {
    void myfunc() {
        // Subclass logic here
    }
}
```

Another example (second variation):

```java
// 2.2. Title of the program

/*
IMPORTS
*/

class p2_2 {
    public static void main(String args[]) {
        // Main program logic here
    }
}

class p2_2_1 {
    void myfunc() {
        // Subclass logic here
    }
}
```

---

## 🧑‍🤝‍🧑 Contribution Guidelines

1. Add your solution under the correct **topic folder**.
2. Follow the **pX.java** naming convention.
3. Use the correct template (single-script or multi-script).
4. Keep your class name the same as the file name.
5. Comment the **program title** at the top.
6. Test your code before committing.

---

## ✅ Best Practices

* Use proper indentation and meaningful variable names.
* Add comments for tricky parts of the logic.
* Follow the same class/file naming style.
* Keep everything inside the relevant topic folder.

---

> “Consistency is more important than complexity — let’s keep our code organized and simple to learn from.”

---
