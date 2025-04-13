-- MySQL does not support FULL JOIN directly, but you can simulate it using UNION
-- MYSQL syntax
-- SELECT columns FROM table1 LEFT JOIN table2 ON table1.column_name = table2.column_name UNION SELECT columns FROM table1 RIGHT JOIN table2 ON table1.column_name = table2.column_name

-- Create departments table
CREATE TABLE departments (
  dept_id INT PRIMARY KEY,
  dept_name VARCHAR(50)
);

-- Insert rows into departments
INSERT INTO departments (dept_id, dept_name) VALUES
(10, 'HR'),
(20, 'Engineering'),
(40, 'Marketing');

-- Create employees table
CREATE TABLE employees (
  emp_id INT PRIMARY KEY,
  name VARCHAR(50),
  dept_id INT
);

-- Insert rows into employees
INSERT INTO employees (emp_id, name, dept_id) VALUES
(1, 'Alice', 10),
(2, 'Bob', 20),
(3, 'Charlie', 30);

SELECT e.name, d.dept_name FROM employees AS e LEFT JOIN departments AS d ON e.dept_id = d.dept_id UNION SELECT e.name, d.dept_name FROM employees AS e RIGHT JOIN departments AS d ON e.dept_id = d.dept_id;

DROP TABLE departments;
DROP TABLE employees;